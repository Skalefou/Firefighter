/*
* play.hpp
* Author : Skalefou
* Creation date: 01/01/2022 (D/M/Y)
* Date of last update : 16/01/2022 (D/M/Y)
*
* This file describes the "Play" class
*/

#ifndef PLAY_HPP
#define PLAY_HPP
#pragma once

#include "option.hpp"
#include "sprite.hpp"

class Play
{
public:
	Play(sf::Font& font, bool &fontWork, Audio &audio);
	void run(sf::RenderWindow& window, sf::Color &backgroundColor, Audio &audio, bool &execution);
private:
	Option option;
	bool m_releaseEscape = true;

	/*
	* option : Object containing everything related to the options menu.
	* m_releaseEscape : Check if the "Escape" key is not pressed.
	*/
};

#endif
