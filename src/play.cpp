#include <SFML/Graphics.hpp>
#include "play.hpp"

Play::Play(sf::Font& font, bool& fontWork) : m_releaseEscape(true), option(font, fontWork)
{

}

void Play::run(sf::RenderWindow& window, sf::Color& backgroundColor)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && option.canOpenOption() && m_releaseEscape)
	{
		option.setOption(!option.getOption(), backgroundColor);
		m_releaseEscape = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !m_releaseEscape)
		m_releaseEscape = true;
	
	if (option.getOption())
		option.run(window);

}
