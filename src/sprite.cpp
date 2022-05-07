/*
file: sprite.cpp
author: Skalefou
description: File managing the functions of the Sprite class which manages sprite.
*/
#include "sprite.hpp"

Sprite::Sprite()
{
    const std::vector <sf::Vector2f> position {{287.f, 80.f}};
    for(int i = 0; i < std::size(m_nameFileTexture); i++)
    {
        m_texture.push_back(sf::Texture{});
        m_texture[i].loadFromFile(std::string{"data/texture/"+m_nameFileTexture[i]});
    }
    for(int i = 0; i < std::size(m_texture); i++)
    {
        m_sprite.push_back(std::make_unique<sf::Sprite>(sf::Sprite{}));
        m_sprite[i]->setTexture(m_texture[i]);
        m_sprite[i]->setPosition(position[i]);
    }
}

void Sprite::draw(sf::RenderWindow &window, const int id)
{
    window.draw(m_sprite[id]);
}