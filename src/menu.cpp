/*
file: menu.cpp
author: Skalefou
description: file managing the functions of the Menu class which includes the whole program
*/

#include "firefighter.hpp"
#include "menu.hpp"

void Menu::enterChoice(sf::RenderWindow &window, int &stateGame)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_cursor == m_cursorBegin)
        stateGame = PLAY;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_cursor == m_cursorEnd)
        window.close();
}

 void Menu::run(sf::RenderWindow &window, int &stateGame)
 {
     moveCursor();
     enterChoice(window, stateGame);
     colorAnimation();
     draw(window);
 }