/*
* game.hpp
* Author : Skalefou
* Creation date: 08/11/2021 (D/M/Y)
* Date of last update : 11/11/2021 (D/M/Y)
*
* This file describes the "Game" class
*/

#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics.hpp>

//Defines the maximum time it takes for the program to freeze
#define SLEEP_TIME_MAX 16'666

class Game
{
public:
	Game();
	sf::Time sleepTime();
	void play();
private:
	sf::RenderWindow window;
	sf::Clock timeExecution;
	sf::Color backgroundColor;
	
	/*
	* window : Program window. Useful throughout the program.
	* timeExecution : Duration of tick execution, particularly useful in the sleepTime() method.
	* backgroundColor : Sets the background color of the program window, useful during program display.
	*/
};

#endif