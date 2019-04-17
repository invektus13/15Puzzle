#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
    public:
        Tile();
        ~Tile();

    protected:

    private:
        sf::IntRect m_tile;
        sf::Vector2f m_tileSpeed;
        sf::Texture m_texture;
        sf::
};

#endif // TILE_H
