/*
file: menu.hpp
author: Skalefou
description: Header managing the "Menu" class which includes the whole program
*/
#ifndef MENU_HPP
#define MENU_HPP

#include "configuration.hpp"
#include "sound.hpp"

class Menu : public Configuration
{
public:
    void enterChoice(sf::RenderWindow &window, int &stateGame, Sound &sound);
    void run(sf::RenderWindow &window, int &stateGame, Sound &sound);
private:
    sf::Clock m_choiceWait;
    bool m_releaseInput = true;
};

#endif