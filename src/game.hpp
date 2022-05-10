/*
file: game.hpp
author: Skalefou
description: Header managing the "Game" class that manipulates the whole game.
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "option.hpp"

class Game 
{
public:
    void init(sf::Font &font);
private:
    Option m_option;
};

#endif