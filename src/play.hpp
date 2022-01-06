/*
* play.hpp
* Author : Skalefou
* Creation date: 01/01/2022 (D/M/Y)
* Date of last update : 02/01/2022 (D/M/Y)
*
* This file describes the "Play" class
*/

#ifndef PLAY_HPP
#define PLAY_HPP
#pragma once

#include "option.hpp"

class Play
{
public:
	Play(sf::Font& font, bool &fontWork);
	void run(sf::RenderWindow& window, sf::Color &backgroundColor);
private:
	Option option;
	bool m_releaseEscape;
};

#endif
