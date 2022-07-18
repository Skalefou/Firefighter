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

enum {FIREFIGHTER_MENU_SPRITE, FIRE1_SPRITE, FIRE2_SPRITE, PLAYER_SPRITE};

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
    void changePosition(const int id, sf::Vector2f position);
private:
    std::vector <std::string> m_nameFileTexture {"firefighter_menu.png", "fire1.png", "fire2.png", "player.png"};
    std::vector <Texture> m_sprite;
};

#endif