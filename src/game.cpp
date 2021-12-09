/*
* game.cpp
* Author : Skalefou
* Creation date: 08/11/2021 (D/M/Y)
* Date of last update : 11/11/2021 (D/M/Y)
* 
* This file has all the methods of the "Game" class.
*/

#include "game.hpp"

//Initializes the attributes of the Game class
Game::Game() : backgroundColor(255, 222, 173, 255), execution(true), gameState(MENU)
{
	window.create(sf::VideoMode(512, 512), "Firefighter", sf::Style::Close);
    mainMenu = new MainMenu;
}

Game::~Game()
{
    deleteMainMenu();
}

void Game::deleteMainMenu()
{
    delete mainMenu;
    mainMenu = 0;
    audio.deleteMusicTheme();
}

//sleepTime() returns the amount of time it takes for the program to hang, which is subtracted by the execution time that the program takes.
sf::Time Game::sleepTime()
{
    if (sf::microseconds(SLEEP_TIME_MAX) <= timeExecution.getElapsedTime())
        return sf::microseconds(0);
    else
        return (sf::microseconds(SLEEP_TIME_MAX) - timeExecution.getElapsedTime());
}

//The play function performs the entire process of the game
void Game::play()
{
	while (window.isOpen() && execution)
	{
        sf::sleep(sleepTime());
        timeExecution.restart();
        window.clear(backgroundColor);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (mainMenu != 0)
            mainMenu->play(window, audio, execution, gameState);
        if (mainMenu != 0 && gameState != MENU)
            deleteMainMenu();
        window.display();
	}
}
