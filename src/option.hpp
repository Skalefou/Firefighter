/*
* option.hpp
* Author : Skalefou
* Creation date: 02/01/2022 (D/M/Y)
* Date of last update : 08/01/2022 (D/M/Y)
*
* This file describes the "Option" class
*/

#ifndef OPTION_HPP
#define OPTION_HPP
#pragma once

#define NUMBER_TEXT_OPTION 9

enum {SOUND, MUSIC};

#include "audio.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <string>

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

class Option
{
public:
	Option(sf::Font &font, bool &fontWork, Audio &audio);
	std::string volumeText(Audio& audio, const bool type);
	void setCanOpenOption(const bool canOpenOption);
	void selectorAnimateText();
	void animateText();
	bool canOpenOption() const;
	void setOption(const bool option, sf::Color &backgroundColor);
	bool getOption() const;
	void resetChoice(const unsigned int lastkey);
	void selectorChoice(Audio &audio, bool &execution, sf::Color &backgroundColor);
	void draw(sf::RenderWindow& window);
	void run(sf::RenderWindow &window, Audio &audio, bool &execution, sf::Color &backgroundColor);

private:
	bool m_option = false, m_canOpenOption = true;
	std::array <sf::Text, NUMBER_TEXT_OPTION> m_text;
	sf::RectangleShape m_frame;
	unsigned int m_selector = 1, m_lastKey;
	std::vector<int> m_selectorAnimateText;
	sf::Clock m_clockAnimateText, m_coolDownInput;
	bool m_colorAnimateText, m_releaseInput = false;

	/*
	* m_option : Checks if the option menu are open or not.
	* m_canOpenOption : Check if we can open the option menu.
	* m_frame : Create the red frame of options.
	* m_selector : Indicates selection in the options menu.
	* m_lastkey : Indicates the last key on the keyboard the user presses.
	* m_selectorAnimateText : Table indicating all the texts that must be animated.
	* m_clockAnimateText,m_coolDownInput : Clock resets after a certain time.
	* m_colorAnimateText : Specifies the color that the animated text should have.
	* m_releaseInput : Indicates whether the user releases a key on the keyboard.
	*/
};

#endif