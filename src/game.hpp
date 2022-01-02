/*
* game.hpp
* Author : Skalefou
* Creation date: 08/11/2021 (D/M/Y)
* Date of last update : 31/12/2021 (D/M/Y)
*
* This file describes the "Game" class
*/

#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics.hpp>
#include "audio.hpp"
#include "mainMenu.hpp"
#include "play.hpp"

//Defines the maximum time it takes for the program to freeze
#define SLEEP_TIME_MAX 16'666

enum {MENU, PLAY, GAME_OVER};

class Game
{
public:
	Game();
	~Game();
	void deleteMainMenu();
	sf::Time sleepTime();
	void program();
private:
	sf::RenderWindow window;
	sf::Clock timeExecution;
	sf::Color backgroundColor;
	bool execution;
	unsigned int gameState;
	Audio audio;
	MainMenu *mainMenu;
	Play play;
	/*
	* window : Program window. Useful throughout the program.
	* timeExecution : Duration of tick execution, particularly useful in the sleepTime() method.
	* backgroundColor : Sets the background color of the program window, useful during program display.
	* execution : bool defining whether the execution of the program is still in progress or whether it must stop.
	* gameState : Defines the state of the game (Menu, play or the state of Game over).
	* audio : Object that contains everything related to audio.
	* *mainMenu : Object that contains everything related to main menu of the game.
	*/
};

#endif