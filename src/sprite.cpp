/*
file: sprite.cpp
author: Skalefou
description: File managing the functions of the Sprite class which manages sprite.
*/
#include "sprite.hpp"

Sprite::Sprite()
{
    const std::vector <sf::Vector2f> position {{287.f, 80.f}, {0.f, 0.f}};
    for(int i = 0; i < std::size(m_nameFileTexture); i++)
    {
        m_sprite.push_back(Texture{});
        m_sprite[i].texture.loadFromFile("data/texture/" + m_nameFileTexture[i]);
    }

    for(int i = 0; i < std::size(m_sprite); i++)
    {
        m_sprite[i].sprite.setTexture(m_sprite[i].texture);
        m_sprite[i].sprite.setPosition(position[i]);
    }
}

void Sprite::draw(sf::RenderWindow &window, const int id)
{
    window.draw(m_sprite[id].sprite);
}