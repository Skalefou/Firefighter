/*
file: menu.cpp
author: Skalefou
description: file managing the functions of the Menu class which includes everything directly or indirectly related to the options and the menu.
*/

#include "menu.hpp"

void Menu::init(sf::Font &font, const std::vector<std::string> textString, const std::vector<int> characterSize)
{
    for(int i = 0; i < textString.size(); i++)
    {
        m_text.push_back(sf::Text{});
        m_text[i].setFont(font);
        m_text[i].setString(textString[i]);
        m_text[i].setCharacterSize(characterSize[i]);
    }
    m_text[0].setPosition(sf::Vector2f(0.f, 0.f));
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(m_text[0]);
}