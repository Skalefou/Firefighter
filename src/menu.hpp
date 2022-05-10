/*
file: menu.hpp
author: Skalefou
description: Header managing the "Menu" class which manages the menu.
*/
#ifndef MENU_HPP
#define MENU_HPP

#include "configuration.hpp"
#include "sound.hpp"
#include "sprite.hpp"

class Menu : public Configuration
{
public:
    void enterChoice(sf::RenderWindow &window, int &stateGame, Sound &sound);
    void drawSprite(sf::RenderWindow &window, Sprite &sprite);
    void run(sf::RenderWindow &window, int &stateGame, Sound &sound, Sprite &sprite);
private:
    sf::Clock m_choiceWait;
    bool m_releaseInput = true;
};

#endif