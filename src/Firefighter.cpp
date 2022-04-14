/*
file: firefighter.cpp
author: Skalefou
description: file managing the functions of the Firefighter class which includes the whole program
*/
#include "firefighter.hpp"

Firefighter::Firefighter()
{
    //Load Menu
    font.loadFromFile("data/Pixellari.ttf");

    std::vector<sf::Vector2f> t {sf::Vector2f(14.f, 14.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f)};
    menu.init(font, {"Firefighter", "Play", "Sound : 10", "Music : 10", "Quit"}, {36, 26, 26, 26, 26}, {sf::Vector2f(128.f, 24.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f), sf::Vector2f(18.f, 18.f)});
}

sf::Time Firefighter::timeSleep()
{
    if (sf::microseconds(16'666) <= timeExecution.getElapsedTime())
        return sf::microseconds(0);
    else
        return (sf::microseconds(16'666) - timeExecution.getElapsedTime());
}

void Firefighter::run()
{
    while(window.isOpen())
    {
        sf::sleep(timeSleep());
        window.clear(backgroundColor);
        timeExecution.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(stateGame == MENU)
            menu.draw(window);
        
        window.display();
    }
}