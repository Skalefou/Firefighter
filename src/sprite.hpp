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

struct Texture 
{
    sf::Sprite sprite;
    sf::Texture texture;
};

class Sprite
{
public:
    Sprite();
    void draw(sf::RenderWindow &window, const int id);
private:
    std::vector <std::string> m_nameFileTexture {"firefighter_menu.png"};
    std::vector <Texture> m_sprite;
};

#endif