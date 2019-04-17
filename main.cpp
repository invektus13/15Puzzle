#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "GamePieces.h"
#include "Randomizer.h"
#include "MoveTiles.h"

//shuffle
//timer
//movecount
//winscreen
//start timer

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(200,300), "Game1");

    /////////////////load&initialize////////////////////
    sf::Texture texture[16];
    GamePieces puzzleTiles[4][4];
    int gameboard[4][4];
    sf::Font winFont;
    winFont.loadFromFile("Asset/COMIC.TTF");
    sf::Text wintext;
    wintext.setFont(winFont);
    wintext.setCharacterSize(30);
    wintext.setFillColor(sf::Color::Black);
    wintext.setString("You WIN!");
    wintext.setOrigin(sf::Vector2f(wintext.getGlobalBounds().left+wintext.getGlobalBounds().width/2,wintext.getGlobalBounds().top+wintext.getGlobalBounds().height/2));
    wintext.setPosition(sf::Vector2f(100,100));
    sf::Text clickcount;
    clickcount.setFont(winFont);
    clickcount.setCharacterSize(15);
    clickcount.setFillColor(sf::Color::Black);
    clickcount.setString("Clicks: 0");
    //clickcount.setOrigin(sf::Vector2f(clickcount.getGlobalBounds().left+clickcount.getGlobalBounds().width/2,clickcount.getGlobalBounds().top+clickcount.getGlobalBounds().height/2));
    clickcount.setPosition(5,205);
    sf::Text Timer;
    Timer.setFont(winFont);
    Timer.setCharacterSize(40);
    Timer.setFillColor(sf::Color::Black);
    Timer.setString("0:0:0");
    Timer.setOrigin(sf::Vector2f(Timer.getGlobalBounds().left+Timer.getGlobalBounds().width/2,Timer.getGlobalBounds().top+Timer.getGlobalBounds().height/2));
    Timer.setPosition(100,250);

    sf::SoundBuffer movebuffer;
    movebuffer.loadFromFile("Asset/effect.wav");
    sf::Sound moving;
    moving.setBuffer(movebuffer);

    int clickcounter=0;

    //loading texture//
    int texturecount=0;
    for(int y=0;y<4;y++)
        {
            for(int x=0;x<4;x++)
            {
                texture[texturecount].loadFromFile("Asset/"+std::to_string(texturecount+1)+".png");
                puzzleTiles[x][y].setTexture(texture[texturecount]);
                puzzleTiles[x][y].setTag(texturecount);
                texturecount++;
            }
        }

    //setting sprite position//
        for(int y=0;y<4;y++)
        {
            for(int x=0;x<4;x++)
            {
                puzzleTiles[x][y].setSpritePosition(sf::Vector2f(x*puzzleTiles[x][y].m_sprite.getGlobalBounds().width,y*puzzleTiles[x][y].m_sprite.getGlobalBounds().height));
            }
        }

    //loading utilities//
    sf::Clock clock;
    float dt;
    Randomizer randommachine;
    randommachine.Randomize(puzzleTiles);
    MoveTiles mover;
    bool iswin=false;

    int hour=0;
    int minute=0;
    int second=0;


    ///////////startTheGame////////////
    while(window.isOpen())
    {
        sf::Event event;


        clickcount.setString("Clicks: "+std::to_string(clickcounter));
        second=clock.getElapsedTime().asSeconds();

        if(second>=59)
        {
            second=0;
            clock.restart();
            minute++;
        }
        if(minute>=59)
        {
            minute=0;
            hour++;
        }
        Timer.setString(std::to_string(hour)+":"+std::to_string(minute)+":"+std::to_string(second));


        /////////////process events//////////////////
        while(window.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
            if(event.type==sf::Event::MouseButtonPressed)
            {
                auto mousepos=sf::Mouse::getPosition(window);
                auto newpos=window.mapPixelToCoords(mousepos);

                for(int y=0;y<4;y++)
                {
                    for(int x=0;x<4;x++)
                    {
                        if(puzzleTiles[x][y].m_sprite.getGlobalBounds().contains(newpos))
                        {
                            if(puzzleTiles[x+1][y].getTag()==15)
                            {mover.swapRight(puzzleTiles,x,y);
                            clickcounter++;
                            moving.play();}

                            if(puzzleTiles[x-1][y].getTag()==15)
                            {mover.swapLeft(puzzleTiles,x,y);
                            clickcounter++;
                            moving.play();}

                            if(puzzleTiles[x][y+1].getTag()==15)
                            {mover.swapDown(puzzleTiles,x,y);
                            clickcounter++;
                            moving.play();}

                            if(puzzleTiles[x][y-1].getTag()==15)
                            {mover.swapUp(puzzleTiles,x,y);
                            clickcounter++;
                            moving.play();}

                        }
                    }
                }
            }
        }


        //////////////////checkwin//////////////////
        int wintags=16;
        int wintagcounter=0;
        for(int y=0;y<4;y++)
        {
            for(int x=0;x<4;x++)
            {
                if(puzzleTiles[x][y].getTag()==wintagcounter)
                    wintagcounter++;
            }
        }

        if(wintagcounter==wintags)
        {
            std::cout<<"Win";
            iswin=true;
        }

        window.clear(sf::Color::White);


        ///////////////////////draw///////////////////
        for(int x=0;x<4;x++)
        {
            for(int y=0;y<4;y++)
            {
                window.draw(puzzleTiles[x][y].m_sprite);
            }
        }

        if(iswin)
        window.draw(wintext);
        window.draw(clickcount);
        window.draw(Timer);

        window.display();
    }

    return 0;
}
