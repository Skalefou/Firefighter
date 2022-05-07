/*
file: sprite.hpp
author: Skalefou
description: Header managing the "Sprite" class which manages sprite. 
*/
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

enum {FIREFIGHTER_MENU_SPRITE};

class Sprite
{
public:
    Sprite();
    void draw(sf::RenderWindow &window, const int id);
private:
    std::string m_nameFileTexture {"firefighter_menu.png"};
    std::vector <sf::Texture> m_texture;
    std::vector <std::unique_ptr<sf::Sprite>> m_sprite;
};

#endif