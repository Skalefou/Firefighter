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

    
    std::vector<std::string> textString {"Firefighter", "Play", "Sound : 10", "Music : 10", "Quit"};
    std::vector<int> characterSize {26, 16, 16, 16, 16}; 
    menu.init(font, textString, characterSize);
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
        timeExecution.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(stateGame == MENU)

        window.clear(backgroundColor);
        window.display();
    }
}