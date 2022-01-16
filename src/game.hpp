/*
* game.hpp
* Author : Skalefou
* Creation date: 08/11/2021 (D/M/Y)
* Date of last update : 16/01/2022 (D/M/Y)
*
* This file describes the "Game" class
*/

#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "audio.hpp"
#include "mainMenu.hpp"
#include "play.hpp"
#include "sprite.hpp"

//Define the maximum time it takes for the program to freeze
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
	bool execution, fontWork = false, focus = true;
	unsigned int gameState;
	Audio audio;
	std::unique_ptr<MainMenu> mainMenu;
	std::unique_ptr<Play> play;
	sf::Font font;
	Sprite sprite;
	/*
	* window : Program window. Useful throughout the program.
	* timeExecution : Duration of tick execution, particularly useful in the sleepTime() method.
	* backgroundColor : Sets the background color of the program window, useful during program display.
	* execution : bool defining whether the execution of the program is still in progress or whether it must stop.
	* fontWork : Indicates if "m_font" is working correctly.
	* focus : Indicates whether the window is fully used by the user.
	* gameState : Defines the state of the game (Menu, play or the state of Game over).
	* audio : Object that contains everything related to audio.
	* *mainMenu : Object that contains everything related to main menu of the game.
	*/
};

#endif