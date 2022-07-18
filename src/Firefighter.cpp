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

    menu.init(font, {"Firefighter", "Play", "Sound : 10", "Music : 10", "Quit"}, {56, 36, 36, 36, 36}, {sf::Vector2f(10.f, 24.f), sf::Vector2f(10.f, 256.f), sf::Vector2f(10.f, 302.f), sf::Vector2f(10.f, 344.f), sf::Vector2f(10.f, 386.f), sf::Vector2f(10.f, 428.f)}, 1, 4);
    game.init(font, sprite);
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
            menu.run(window, stateGame, sound, sprite);
        else if (stateGame == PLAY)
            game.run(window, stateGame, sound, sprite);
        
        window.display();
    }
}