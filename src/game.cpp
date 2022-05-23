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

void Game::keyEnter(int &stategame)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_activeKey)
    {
        if(stategame == 2)
            stategame = 1;
        else if (stategame == 1)
            stategame = 2;
        m_activeKey = false;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_activeKey == false)
        m_activeKey = true;
}

void Game::run(sf::RenderWindow &window, int &stategame)
{
    keyEnter(stategame);
    draw(window, stategame);
}

void Game::draw(sf::RenderWindow &window, int &stategame)
{
    if(stategame == 1)
        m_option.draw(window);
}