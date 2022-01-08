/*
* option.cpp
* Author : Skalefou
* Creation date: 02/01/2022 (D/M/Y)
* Date of last update : 08/01/2022 (D/M/Y)
*
* This file has all the methods of the "Option" class.
*/

#include "option.hpp"

//Initializes the attributes of the Option class.
Option::Option(sf::Font& font, bool& fontWork, Audio& audio)
{
	//Initializes m_frame.
	m_frame.setSize(sf::Vector2f(452.f, 256.f));
	m_frame.setFillColor(sf::Color(191, 48, 48, 192));
	m_frame.setOutlineThickness(3.f);
	m_frame.setPosition(sf::Vector2f(30.f, 128.f));

	//Load the texts.
	if (font.loadFromFile("data/Pixellari.ttf"))
	{
		const std::array<std::string, NUMBER_TEXT_OPTION> text{ "Option", "Back to game", "<", volumeText(audio, MUSIC), ">", "<", volumeText(audio, SOUND), ">", "Quit"};
		const std::array<float, 2 * NUMBER_TEXT_OPTION> posText
		{
			206.f, 128.f,
			40.f, 188.f,
			40.f, 224.f,
			70.f, 224.f,
			238.f, 224.f,
			40.f, 260.f,
			70.f, 260.f,
			243.f, 260.f,
			40.f, 296.f
		};

		//Initializes m_text.
		for (unsigned int i = 0; i < NUMBER_TEXT_OPTION; i++)
		{
			m_text[i].setFont(font);
			m_text[i].setString(text[i]);
			m_text[i].setCharacterSize(36);
			m_text[i].setPosition(sf::Vector2f(posText[2 * i], posText[2 * i + 1]));
		}
		selectorAnimateText();
		m_text[1].setFillColor(sf::Color(255, 215, 0));
		fontWork = true;
	}
}

//Changes the text indicating the volume of music and sound.
std::string Option::volumeText(Audio& audio, const bool type)
{
	int volume;
	std::string t{ "" };
	if (type)
	{
		volume = (int)(audio.getVolumeMusic() / 10.f);
		t += "Music : ";
	}
	else
	{
		volume = (int)(audio.getVolumeSound() / 10.f);
		t += "Sound : ";
	}
	return t += std::to_string(volume);
}

//Allows to change the ability to open options.
void Option::setCanOpenOption(const bool canOpenOption)
{
	m_canOpenOption = canOpenOption;
}

//Determines which texts should be animated.
void Option::selectorAnimateText()
{
	m_selectorAnimateText.clear();
	for (unsigned int i = 0; i < NUMBER_TEXT_OPTION; i++)
		m_text[i].setFillColor(sf::Color::White);
	if (m_selector == 1)
		m_selectorAnimateText.push_back(1);
	else if (m_selector == 2)
		for (unsigned int i = 2; i < 5; i++)
			m_selectorAnimateText.push_back(i);
	else if (m_selector == 3)
		for (unsigned int i = 5; i < 8; i++)
			m_selectorAnimateText.push_back(i);
	else
		m_selectorAnimateText.push_back(8);
}

//Animates animated texts.
void Option::animateText()
{
	if (m_clockAnimateText.getElapsedTime() > sf::milliseconds(375))
	{
		sf::Color c;
		if (m_colorAnimateText)
			c = sf::Color(255, 215, 0);
		else
			c = sf::Color(169, 169, 169);
		for (unsigned int i = 0; i < std::size(m_selectorAnimateText); i++)
			m_text[m_selectorAnimateText[i]].setFillColor(c);
		m_colorAnimateText = !m_colorAnimateText;
		m_clockAnimateText.restart();
	}
}

//Returns a value allowing to know if the options menu can be opened.
bool Option::canOpenOption() const
{
	return m_canOpenOption;
}

//Allows you to remove or put the options menu.
void Option::setOption(const bool option, sf::Color& backgroundColor)
{
	m_option = option;
	if (option)
	{
		backgroundColor = sf::Color(178, 153, 121, 255);
		m_selector = 1;
		selectorAnimateText();
	}
	else
		backgroundColor = sf::Color(255, 222, 173, 255);
}

//Return a value to let you know if the options menu is open.
bool Option::getOption() const
{
	return m_option;
}

//Resets some of the choices of the selectorChoice function.
void Option::resetChoice(const unsigned int lastkey)
{
	if (lastkey == UP || lastkey == DOWN)
		selectorAnimateText();
	m_coolDownInput.restart();
	m_releaseInput = false;
	m_lastKey = lastkey;
}

//Allows selection of different options.
void Option::selectorChoice(Audio& audio, bool &execution, sf::Color& backgroundColor)
{
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
	else if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != LEFT) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (m_selector == 2 || m_selector == 3))
	{
		unsigned int a = 0;
		if (m_selector == 2 && audio.getVolumeMusic() > 0.f)
		{
			audio.setVolumeMusic((audio.getVolumeMusic() - 10.f));
			a = (unsigned int)(audio.getVolumeMusic() / 10);
			m_text[3].setString(volumeText(audio, MUSIC));
		}
		else if (m_selector == 3 && audio.getVolumeSound() > 0.f)
		{
			audio.setVolumeSound((audio.getVolumeSound() - 10.f));
			a = (unsigned int)(audio.getVolumeSound() / 10);
			m_text[6].setString(volumeText(audio, SOUND));
		}
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
			m_text[3].setString(volumeText(audio, MUSIC));
		}
		else if (m_selector == 3 && audio.getVolumeSound() < 100.f)
		{
			audio.setVolumeSound((audio.getVolumeSound() + 10.f));
			a = (unsigned int)(audio.getVolumeSound() / 10);
			m_text[6].setString(volumeText(audio, SOUND));
		}
		resetChoice(RIGHT);
		audio.playSound(SELECTION_SOUND);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		if (m_selector == 1)
			setOption(false, backgroundColor);
		else if (m_selector == 4)
			execution = false;
		audio.playSound(SELECTION_SOUND);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_releaseInput = true;
}

//Displays all elements on the screen.
void Option::draw(sf::RenderWindow& window)
{
	window.draw(m_frame);
	for (unsigned int i = 0; i < NUMBER_TEXT_OPTION; i++)
		window.draw(m_text[i]);
}

//Loop managing all aspects of the class.
void Option::run(sf::RenderWindow& window, Audio& audio, bool &execution, sf::Color& backgroundColor)
{
	selectorChoice(audio, execution, backgroundColor);
	animateText();
	draw(window);
}

