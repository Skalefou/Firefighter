#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#pragma once

#include <array>
#include <SFML/Graphics.hpp>
#include "audio.hpp"

#define NUMBER_TEXT_MAINMENU 9
enum { UP, DOWN, LEFT, RIGHT };

class MainMenu
{
public:
	MainMenu();
	void draw(sf::RenderWindow& window);
	void selectorTextAnimate();
	void textChangeAudio(const unsigned int v);
	void selectorChoice(Audio &audio, bool &execution, unsigned int &gameState);
	void animateText();
	void play(sf::RenderWindow& window, Audio &audio, bool &execution, unsigned int &gameState);
private:
	sf::Font m_font;
	std::array <sf::Text, NUMBER_TEXT_MAINMENU> m_text;
	unsigned int m_selector, m_lastKey;
	sf::Clock m_clockAnimateText, m_coolDownInput;
	std::vector <unsigned int>m_selectorAnimate;
	bool m_colorAnimateText, m_releaseInput;
};

#endif
