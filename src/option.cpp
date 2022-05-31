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

void Option::draw(sf::RenderWindow &window)
{
    window.draw(m_outlines);
    for(int i = 0; i < m_text.size(); i++)
        window.draw(m_text[i]);
}