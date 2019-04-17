#ifndef GAMEPIECES_H
#define GAMEPIECES_H

#include <SFML/Graphics.hpp>

class GamePieces
{
    public:
        GamePieces();
        ~GamePieces();

    public:
        void draw();
        void moveUp(float);
        void moveDown(float);
        void moveLeft(float);
        void moveRight(float);

        void setTexture(sf::Texture texture)
        {
            m_spritetexture=texture;
            m_sprite.setTexture(m_spritetexture);
        }

        void draw(sf::RenderWindow &window)
        {
            window.draw(m_sprite);
        }

        void setSpritePosition(sf::Vector2f position)
        {m_sprite.setPosition(position);}

        void setTag(int tag)
        {m_spritetag=tag;}

        int getTag()
        {return m_spritetag;}

        sf::Texture getTexture()
        {return m_spritetexture;}

        sf::Sprite m_sprite;

    private:

        sf::Vector2f m_movespeed;
        sf::Texture m_spritetexture;
        int m_spritetag;
        float speed=3;
};

#endif // GAMEPIECES_H
