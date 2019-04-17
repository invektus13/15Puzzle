#include "Randomizer.h"

Randomizer::Randomizer()
{
    //ctor
}

Randomizer::~Randomizer()
{
    //dtor
}

Randomizer::Randomize(GamePieces puzzleTiles[][4])
{
     for(int i=0;i<500;i++)
    {
        int x=rand()%4;
        int y=rand()%4;

        if(puzzleTiles[x+1][y].getTag()==15)
        {

            sf::Texture temptext=puzzleTiles[x][y].getTexture();
            int temptag=puzzleTiles[x][y].getTag();

            puzzleTiles[x][y].setTexture(puzzleTiles[x+1][y].getTexture());
            puzzleTiles[x][y].setTag(puzzleTiles[x+1][y].getTag());

            puzzleTiles[x+1][y].setTexture(temptext);
            puzzleTiles[x+1][y].setTag(temptag);
        }
        if(puzzleTiles[x-1][y].getTag()==15)
        {

            sf::Texture temptext=puzzleTiles[x][y].getTexture();
            int temptag=puzzleTiles[x][y].getTag();

            puzzleTiles[x][y].setTexture(puzzleTiles[x-1][y].getTexture());
            puzzleTiles[x][y].setTag(puzzleTiles[x-1][y].getTag());

            puzzleTiles[x-1][y].setTexture(temptext);
            puzzleTiles[x-1][y].setTag(temptag);
        }

        if(puzzleTiles[x][y+1].getTag()==15)
        {
            sf::Texture temptext=puzzleTiles[x][y].getTexture();
            int temptag=puzzleTiles[x][y].getTag();

            puzzleTiles[x][y].setTexture(puzzleTiles[x][y+1].getTexture());
            puzzleTiles[x][y].setTag(puzzleTiles[x][y+1].getTag());

            puzzleTiles[x][y+1].setTexture(temptext);
            puzzleTiles[x][y+1].setTag(temptag);
        }

        if(puzzleTiles[x][y-1].getTag()==15)
        {
            sf::Texture temptext=puzzleTiles[x][y].getTexture();
            int temptag=puzzleTiles[x][y].getTag();

            puzzleTiles[x][y].setTexture(puzzleTiles[x][y-1].getTexture());
            puzzleTiles[x][y].setTag(puzzleTiles[x][y-1].getTag());

            puzzleTiles[x][y-1].setTexture(temptext);
            puzzleTiles[x][y-1].setTag(temptag);

        }
    }
}
