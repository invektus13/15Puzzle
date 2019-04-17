#include "GamePieces.h"

GamePieces::GamePieces()
{
    //ctor
    m_movespeed.x=0;
    m_movespeed.y=0;
    m_spritetag=0;
}

GamePieces::~GamePieces()
{
    //dtor
}

void GamePieces::moveLeft(float dt)
{
    m_movespeed.x=0;
    m_movespeed.x-=25;

    m_sprite.move(m_movespeed);
}
void GamePieces::moveRight(float dt)
{
    m_movespeed.x=0;
    m_movespeed.x+=25;

    m_sprite.move(m_movespeed);
}

void GamePieces::moveDown(float dt)
{
    m_movespeed.y+=1;

    m_sprite.move(m_movespeed*speed);
}


void GamePieces::moveUp(float dt)
{
    m_movespeed.y-=1;

    m_sprite.move(m_movespeed*speed);
}
