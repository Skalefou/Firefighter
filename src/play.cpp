/*
* play.cpp
* Author : Skalefou
* Creation date: 01/01/2022 (D/M/Y)
* Date of last update : 08/01/2022 (D/M/Y)
*
* This file has all the methods of the "Play" class.
*/

#include <SFML/Graphics.hpp>
#include "play.hpp"

//Initializes the attributes of the Play class.
Play::Play(sf::Font& font, bool& fontWork, Audio& audio) : option(font, fontWork, audio)
{

}

//Loop managing all aspects of the class.
void Play::run(sf::RenderWindow& window, sf::Color& backgroundColor, Audio &audio, bool &execution)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && option.canOpenOption() && m_releaseEscape)
	{
		option.setOption(!option.getOption(), backgroundColor);
		m_releaseEscape = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !m_releaseEscape)
		m_releaseEscape = true;
	
	if (option.getOption())
		option.run(window, audio, execution, backgroundColor);

}
