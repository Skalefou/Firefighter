/*
file: option.cpp
author: Skalefou
description: file managing the functions of the Option class that handles in-game configuration.
*/

#include "option.hpp"

Option::Option()
{
    m_outlines.setSize(sf::Vector2f(246.f, 303.f));
    m_outlines.setPosition(sf::Vector2f(144.f, 82.f));
    m_outlines.setFillColor(sf::Color(207.f, 10.f, 29.f, 128.f));
    m_outlines.setOutlineThickness(4.f);
}

void Option::enterChoice(sf::RenderWindow &window, Sound &sound, bool &m_optionOn)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_cursor == m_cursorBegin)
    {
        m_optionOn = false;
        closeOption(sound);
        sound.playSound(SELECTION_SOUND);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (m_choiceWait.getElapsedTime() >= sf::milliseconds(375) || m_releaseInput))
    {
        if (m_cursor == 3)
            m_text[3].setString(sound.setVolumeMusic((sound.getVolumeMusic() - 10.f)));
        else if (m_cursor == 2)
            m_text[2].setString(sound.setVolumeSound((sound.getVolumeSound() - 10.f)));
        sound.playSound(SELECTION_SOUND);
        m_releaseInput = false;
        m_choiceWait.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (m_choiceWait.getElapsedTime() >= sf::milliseconds(375) || m_releaseInput))
    {
        if (m_cursor == 3)
            m_text[3].setString(sound.setVolumeMusic((sound.getVolumeMusic() + 10.f)));
        else if (m_cursor == 2)
            m_text[2].setString(sound.setVolumeSound((sound.getVolumeSound() + 10.f)));
        sound.playSound(SELECTION_SOUND);
        m_releaseInput = false;
        m_choiceWait.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_cursor == m_cursorEnd)
        window.close();

    if(!m_releaseInput && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_releaseInput = true;
}

void Option::closeOption(Sound &sound)
{
    m_cursor = m_cursorBegin;
    m_colorAnimation = false;
    m_text[1].setColor(sf::Color::Yellow);
    for(int i = 2; i < std::size(m_text); i++)
        m_text[i].setColor(sf::Color::White);
    sound.playMusic(GAME_MUSIC);
}

void Option::draw(sf::RenderWindow &window)
{
    window.draw(m_outlines);
    for(int i = 0; i < m_text.size(); i++)
        window.draw(m_text[i]);
}

void Option::run(sf::RenderWindow &window, Sound &sound, bool &m_optionOn)
{
    enterChoice(window, sound, m_optionOn);
    colorAnimation();
    moveCursor(sound);
}