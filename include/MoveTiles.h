#ifndef MOVETILES_H
#define MOVETILES_H

#include "GamePieces.h"
class MoveTiles
{
    public:
        MoveTiles();
        ~MoveTiles();

        void swapDown(GamePieces [][4],int,int);
        void swapUp(GamePieces [][4],int,int);
        void swapLeft(GamePieces [][4],int,int);
        void swapRight(GamePieces [][4],int,int);

    protected:

    private:
};

#endif // MOVETILES_H
