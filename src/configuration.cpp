/*
file: configuration.cpp
author: Skalefou
description: file managing the functions of the Configuration class which includes everything directly or indirectly related to the options and the menu.
*/

#include "configuration.hpp"

void Configuration::init(sf::Font &font, const std::vector<std::string> textString, const std::vector<int> characterSize, const std::vector<sf::Vector2f> position, int cursorBegin, int cursorEnd)
{
    m_cursorBegin = cursorBegin;
    m_cursorEnd = cursorEnd;
    m_cursor = m_cursorBegin;
    for(int i = 0; i < textString.size(); i++)
    {
        m_text.push_back(sf::Text{});
        m_text[i].setFont(font);
        m_text[i].setString(textString[i]);
        m_text[i].setCharacterSize(characterSize[i]);
        m_text[i].setPosition(position[i]);
    }
    m_text[m_cursorBegin].setColor(sf::Color::Yellow);
}

 void Configuration::colorAnimation()
 {
     if(m_colorAnimationWait.getElapsedTime() >= sf::milliseconds(500))
     {
        m_colorAnimation = !m_colorAnimation;
        if(m_colorAnimation)
            m_text[m_cursor].setColor(sf::Color::Yellow);
        else
            m_text[m_cursor].setColor(sf::Color(192, 192, 192));
        m_colorAnimationWait.restart();
     }
 }

void Configuration::selectionCursor(const bool dir, Sound &sound)
{
    sound.playSound(SELECTION_SOUND);
    m_releaseInput = false;
    m_text[m_cursor].setColor(sf::Color::White);
    if(dir && m_cursor < m_cursorEnd)
        m_cursor++;
    else if (dir && m_cursor == m_cursorEnd)
        m_cursor = m_cursorBegin;
    else if (!dir && m_cursor == m_cursorBegin)
        m_cursor = m_cursorEnd;
    else
        m_cursor--;
    m_text[m_cursor].setColor(sf::Color::Yellow);
    m_keyWait.restart();
}

void Configuration::moveCursor(Sound &sound)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (m_keyWait.getElapsedTime() > sf::milliseconds(375) || m_releaseInput))
        selectionCursor(true, sound);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (m_keyWait.getElapsedTime() > sf::milliseconds(375) || m_releaseInput))
        selectionCursor(false, sound);
    
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_releaseInput = true;
} 

void Configuration::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < m_text.size(); i++)
        window.draw(m_text[i]);
}