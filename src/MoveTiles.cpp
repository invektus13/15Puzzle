#include "MoveTiles.h"

MoveTiles::MoveTiles()
{
    //ctor
}

MoveTiles::~MoveTiles()
{
    //dtor
}

void MoveTiles::swapRight(GamePieces puzzleTiles[][4], int x, int y)
{
    sf::Texture temptext=puzzleTiles[x][y].getTexture();
    int temptag=puzzleTiles[x][y].getTag();

    puzzleTiles[x][y].setTexture(puzzleTiles[x+1][y].getTexture());
    puzzleTiles[x][y].setTag(puzzleTiles[x+1][y].getTag());

    puzzleTiles[x+1][y].setTexture(temptext);
    puzzleTiles[x+1][y].setTag(temptag);
}

void MoveTiles::swapLeft(GamePieces puzzleTiles[][4],int x,int y)
{
    sf::Texture temptext=puzzleTiles[x][y].getTexture();
    int temptag=puzzleTiles[x][y].getTag();

    puzzleTiles[x][y].setTexture(puzzleTiles[x-1][y].getTexture());
    puzzleTiles[x][y].setTag(puzzleTiles[x-1][y].getTag());

    puzzleTiles[x-1][y].setTexture(temptext);
    puzzleTiles[x-1][y].setTag(temptag);
}

void MoveTiles::swapDown(GamePieces puzzleTiles[][4],int x,int y)
{
    sf::Texture temptext=puzzleTiles[x][y].getTexture();
    int temptag=puzzleTiles[x][y].getTag();

    puzzleTiles[x][y].setTexture(puzzleTiles[x][y+1].getTexture());
    puzzleTiles[x][y].setTag(puzzleTiles[x][y+1].getTag());

    puzzleTiles[x][y+1].setTexture(temptext);
    puzzleTiles[x][y+1].setTag(temptag);
}

void MoveTiles::swapUp(GamePieces puzzleTiles[][4],int x,int y)
{
    sf::Texture temptext=puzzleTiles[x][y].getTexture();
    int temptag=puzzleTiles[x][y].getTag();

    puzzleTiles[x][y].setTexture(puzzleTiles[x][y-1].getTexture());
    puzzleTiles[x][y].setTag(puzzleTiles[x][y-1].getTag());

    puzzleTiles[x][y-1].setTexture(temptext);
    puzzleTiles[x][y-1].setTag(temptag);

}
