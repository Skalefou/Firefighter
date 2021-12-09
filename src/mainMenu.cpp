#include "mainMenu.hpp"
#include <string>

MainMenu::MainMenu() : m_selector(1), m_colorAnimateText(false), m_releaseInput(false), m_lastKey(UP)
{
	if (m_font.loadFromFile("data/Pixellari.ttf"))
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
			m_text[i].setFont(m_font);
			m_text[i].setString(textString[i]);
			if (i != 0)
				m_text[i].setCharacterSize(36);
			m_text[i].setPosition(sf::Vector2f(posText[2*i], posText[2*i+1]));
		}
		m_text[0].setCharacterSize(48);
		m_text[1].setFillColor(sf::Color(255, 215, 0));
		selectorTextAnimate();
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < NUMBER_TEXT_MAINMENU; i++)
		window.draw(m_text[i]);
}

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

void MainMenu::textChangeAudio(const unsigned int v)
{
	std::string t;
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

void MainMenu::selectorChoice(Audio& audio, bool& execution, unsigned int& gameState)
{
	if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != UP) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_selector > 1)
	{
		m_selector--;
		selectorTextAnimate();
		m_coolDownInput.restart();
		m_releaseInput = false;
		m_lastKey = UP;
	}
	else if ((m_coolDownInput.getElapsedTime() > sf::milliseconds(375) || m_releaseInput == true || m_lastKey != DOWN) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_selector < 4)
	{
		m_selector++;
		selectorTextAnimate();
		m_coolDownInput.restart();
		m_releaseInput = false;
		m_lastKey = DOWN;
	}
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
		m_coolDownInput.restart();
		m_releaseInput = false;
		m_lastKey = LEFT;
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
		m_coolDownInput.restart();
		m_releaseInput = false;
		m_lastKey = RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		if (m_selector == 1)
			gameState = 1;
		else if (m_selector == 4)
			execution = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_releaseInput = true;
}

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

void MainMenu::play(sf::RenderWindow& window, Audio& audio, bool& execution, unsigned int& gameState)
{
	selectorChoice(audio, execution, gameState);
	animateText();
	draw(window);
}