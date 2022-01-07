/*
* mainMenu.cpp
* Author : Skalefou
* Creation date: 09/12/2021 (D/M/Y)
* Date of last update : 07/01/2021 (D/M/Y)
*
* This file has all the methods of the "mainMenu" class.
*/

#include "mainMenu.hpp"
#include <string>

//Initializes the attributes of the mainMenu class.
MainMenu::MainMenu(sf::Font& font, const bool fontWork) : m_selector(1), m_colorAnimateText(false), m_releaseInput(false), m_lastKey(UP)
{
	if (fontWork)
	{
		const std::array <std::string, NUMBER_TEXT_MAINMENU> textString{ "Firefighter", "Play", "<", "Music : 10", ">", "<", "Sound : 10", ">", "Quit" };
		const std::array <float, 2 * NUMBER_TEXT_MAINMENU> posText
		{
			10.f, 32.f,
			90.f, 256.f,
			10.f, 302.f,
			40.f, 302.f,
			208.f, 302.f,
			10.f, 348.f,
			40.f, 348.f,
			213.f, 348.f,
			90.f, 394.f
		};
		for (unsigned int i = 0; i < NUMBER_TEXT_MAINMENU; i++)
		{
			m_text[i].setFont(font);
			m_text[i].setString(textString[i]);
			if (i != 0)
				m_text[i].setCharacterSize(36);
			m_text[i].setPosition(sf::Vector2f(posText[2*i], posText[2*i+1]));
		}
		m_text[0].setCharacterSize(48);
		selectorTextAnimate();
		m_text[1].setFillColor(sf::Color(255, 215, 0));
	}
}

//Displays the elements of the class on the screen.
void MainMenu::draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < NUMBER_TEXT_MAINMENU; i++)
		window.draw(m_text[i]);
}

//Determine which texts are to be animated.
void MainMenu::selectorTextAnimate()
{
	m_selectorAnimate.clear();
	for (unsigned int i = 0; i < NUMBER_TEXT_MAINMENU; i++)
		m_text[i].setFillColor(sf::Color::White);
	if (m_selector == 1)
		m_selectorAnimate.push_back(1);
	else if (m_selector == 2)
		for(unsigned int i = 2; i < 5; i++)
			m_selectorAnimate.push_back(i);
	else if (m_selector == 3)
		for (unsigned int i = 5; i < 8; i++)
			m_selectorAnimate.push_back(i);
	else
		m_selectorAnimate.push_back(8);
}

//Changes the texts of the volume options according to the volume of music and sounds.
void MainMenu::textChangeAudio(const unsigned int v)
{
	std::string t {""};
	if (m_selector == 2)
		t += "Music : ";
	else
		t += "Sound : ";
	t += std::to_string(v);
	if (m_selector == 2)
		m_text[3].setString(t);
	else
		m_text[6].setString(t);
}

//Resets some of the choices of the selectorChoice function.
void MainMenu::resetChoice(const unsigned int lastkey)
{
	if(lastkey == UP || lastkey == DOWN)
		selectorTextAnimate();
	m_coolDownInput.restart();
	m_releaseInput = false;
	m_lastKey = lastkey;
}

//Allows selection of different options.
void MainMenu::selectorChoice(Audio& audio, bool& execution, unsigned int& gameState)
{
	//Changes the selection depending on the keyboard key the user enters
	if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != UP) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (m_selector > 1)
			m_selector--;
		else
			m_selector = 4;
		resetChoice(UP);
		audio.playSound(SELECTION_SOUND);
	}
	else if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != DOWN) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (m_selector < 4)
			m_selector++;
		else
			m_selector = 1;
		resetChoice(DOWN);
		audio.playSound(SELECTION_SOUND);
	}
	//Change the volume
	else if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != LEFT) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (m_selector == 2 || m_selector == 3))
	{
		unsigned int a = 0;
		if (m_selector == 2 && audio.getVolumeMusic() > 0.f)
		{
			audio.setVolumeMusic((audio.getVolumeMusic() - 10.f));
			a = (unsigned int)(audio.getVolumeMusic() / 10);
			textChangeAudio(a);
		}
		else if (m_selector == 3 && audio.getVolumeSound() > 0.f)
		{
			audio.setVolumeSound((audio.getVolumeSound() - 10.f));
			a = (unsigned int)(audio.getVolumeSound() / 10);
			textChangeAudio(a);
		}
		textChangeAudio(a);
		resetChoice(LEFT);
		audio.playSound(SELECTION_SOUND);
	}
	else if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != RIGHT) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && (m_selector == 2 || m_selector == 3))
	{
		unsigned int a = 0;
		if (m_selector == 2 && audio.getVolumeMusic() < 100.f)
		{
			audio.setVolumeMusic((audio.getVolumeMusic() + 10.f));
			a = (unsigned int)(audio.getVolumeMusic() / 10);
			textChangeAudio(a);
		}
		else if (m_selector == 3 && audio.getVolumeSound() < 100.f)
		{
			audio.setVolumeSound((audio.getVolumeSound() + 10.f));
			a = (unsigned int)(audio.getVolumeSound() / 10);
			textChangeAudio(a);
		}
		resetChoice(RIGHT);
		audio.playSound(SELECTION_SOUND);
	}
	//Validate the selection
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		if (m_selector == 1)
			gameState = 1;
		else if (m_selector == 4)
			execution = false;
		audio.playSound(SELECTION_SOUND);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_releaseInput = true;
}

//Animates animated texts
void MainMenu::animateText()
{
	if (m_clockAnimateText.getElapsedTime() > sf::milliseconds(375))
	{
		sf::Color c;
		if (m_colorAnimateText)
			c = sf::Color(255, 215, 0);
		else
			c = sf::Color(169, 169, 169);
		for (unsigned int i = 0; i < std::size(m_selectorAnimate); i++)
			m_text[m_selectorAnimate[i]].setFillColor(c);
		m_colorAnimateText = !m_colorAnimateText;
		m_clockAnimateText.restart();
	}
}

//Loop managing all aspects of the class.
void MainMenu::play(sf::RenderWindow& window, Audio& audio, bool& execution, unsigned int& gameState)
{
	selectorChoice(audio, execution, gameState);
	animateText();
	draw(window);
	
}