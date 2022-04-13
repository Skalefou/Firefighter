/*
file: menu.hpp
author: Skalefou
description: Header managing the "Menu" class which directly or indirectly manages the menu and option.
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu
{
public:
    void init(sf::Font &font, const std::vector<std::string> textString, const std::vector<int> characterSize);
    void draw(sf::RenderWindow &window);
private:
    std::vector<sf::Text> m_text;
};

#endif