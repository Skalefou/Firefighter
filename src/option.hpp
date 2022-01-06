/*
* option.hpp
* Author : Skalefou
* Creation date: 02/01/2022 (D/M/Y)
* Date of last update : 02/01/2022 (D/M/Y)
*
* This file describes the "Option" class
*/

#ifndef OPTION_HPP
#define OPTION_HPP
#pragma once

#include <SFML/Graphics.hpp>

class Option
{
public:
	Option(sf::Font &font, bool &fontWork);
	void setCanOpenOption(const bool canOpenOption);
	bool canOpenOption() const;
	void setOption(const bool option, sf::Color &backgroundColor);
	bool getOption() const;
	void draw(sf::RenderWindow& window);
	void run(sf::RenderWindow &window);

private:
	bool m_option, m_canOpenOption;
	sf::RectangleShape m_frame;
};

#endif