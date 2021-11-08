#ifndef GAME_HPP
#define GAME_HPP
#pragma once

#include <SFML/Graphics.hpp>

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
};

#endif