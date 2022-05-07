/*
file: firefighter.hpp
author: Skalefou
description: Header managing the "Firefighter" class which includes the whole program
*/
#ifndef FIREFIGHTER_HPP
#define FIREFIGHTER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

#include "menu.hpp"
#include "sound.hpp"
#include "sprite.hpp"

enum {MENU, OPTION, PLAY, GAME_OVER, QUIT};

class Firefighter
{
public:
    Firefighter();
    sf::Time timeSleep();
    void run();
private:
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(512, 512), "Firefighter", sf::Style::Close);
    sf::Color backgroundColor = sf::Color(255, 222, 173, 255);
    sf::Clock timeExecution;
    sf::Font font;
    Menu menu;
    Sound sound;
    Sprite sprite;
    int stateGame = MENU;
};

#endif