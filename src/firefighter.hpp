/*
file: firefighter.hpp
author: Skalefou
description: Header managing the "Firefighter" class which includes the whole program
*/
#ifndef FIREFIGHTER_HPP
#define FIREFIGHTER_HPP

#include <SFML/Graphics.hpp>

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
};

#endif