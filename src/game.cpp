/*
file: game.cpp
author: Skalefou
description: file managing the functions of the Game class that manipulates the whole game.
*/

#include "game.hpp"

void Game::init(sf::Font &font)
{
    m_option.init(font, {"Pause", "Continue", "Sound : 10", "Music : 10", "Quit"}, {46, 36, 36, 36, 36}, {sf::Vector2f(196.f, 238.f), sf::Vector2f(176.f, 256.f), sf::Vector2f(176.f, 302.f), sf::Vector2f(176.f, 344.f), sf::Vector2f(176.f, 386.f), sf::Vector2f(176.f, 428.f)}, 1, 4);
}