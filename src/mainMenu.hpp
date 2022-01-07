/*
* mainMenu.hpp
* Author : Skalefou
* Creation date: 09/12/2021 (D/M/Y)
* Date of last update : 31/12/2021 (D/M/Y)
*
* This file describes the "mainMenu" class
*/

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
	MainMenu(sf::Font &font, const bool fontWork);
	void draw(sf::RenderWindow& window);
	void selectorTextAnimate();
	void textChangeAudio(const unsigned int v);
	void resetChoice(const unsigned int lastkey);
	void selectorChoice(Audio &audio, bool &execution, unsigned int &gameState);
	void animateText();
	void play(sf::RenderWindow& window, Audio &audio, bool &execution, unsigned int &gameState);
private:
	std::array <sf::Text, NUMBER_TEXT_MAINMENU> m_text;
	unsigned int m_selector, m_lastKey;
	sf::Clock m_clockAnimateText, m_coolDownInput;
	std::vector <unsigned int>m_selectorAnimate;
	bool m_colorAnimateText, m_releaseInput;
	/*
	* m_font : Contains the font for the text of the program.
	* m_text : array containing the texts.
	* m_selector : Contains the selection of the option in the menu.
	* m_lastkey : Contains the last key on the keyboard that the user presses.
	* m_clockAnimateText, m_coolDownInput : Sf::Clock to manage the time in the program.
	* m_selectorAnimate : vector indicating which texts are animated.
	* m_colorAnimateText : bool indicating the color of the animated text.
	* m_releaseInput : bool indicating whether the user releases a key on the keyboard.
	*/
};

#endif
