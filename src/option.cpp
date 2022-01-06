#include "option.hpp"

Option::Option(sf::Font& font, bool& fontWork) : m_option(false), m_canOpenOption(true)
{
	m_frame.setSize(sf::Vector2f(452.f, 256.f));
	m_frame.setFillColor(sf::Color(191, 48, 48, 192));
	m_frame.setOutlineThickness(3.f);
	m_frame.setPosition(sf::Vector2f(30.f, 128.f));

	if(font.loadFromFile("data/Pixellari.ttf"))
		fontWork = true;
}

void Option::setCanOpenOption(const bool canOpenOption)
{
	m_canOpenOption = canOpenOption;
}

bool Option::canOpenOption() const
{
	return m_canOpenOption;
}

void Option::setOption(const bool option, sf::Color& backgroundColor)
{
	m_option = option;
	if (option)
		backgroundColor = sf::Color(178, 153, 121, 255);
	else
		backgroundColor = sf::Color(255, 222, 173, 255);
}

bool Option::getOption() const
{
	return m_option;
}

void Option::draw(sf::RenderWindow& window)
{
	window.draw(m_frame);
}

void Option::run(sf::RenderWindow& window)
{
	draw(window);
}

