/*
file: game.hpp
author: Skalefou
description: Header managing the "Game" class that manipulates the whole game.
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "option.hpp"

class Game 
{
public:
    void init(sf::Font &font);
    void keyEnter(int &stategame);
    void run(sf::RenderWindow &window, int &stategame, Sound &sound);
    void draw(sf::RenderWindow &window, int &stategame);
private:
    Option m_option;
    bool m_activeKey = true, m_optionOn = false;
};

#endif