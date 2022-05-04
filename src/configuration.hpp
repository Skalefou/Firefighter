/*
file: configuration.hpp
author: Skalefou
description: Header managing the "Configuration" class which directly or indirectly manages the menu and option.
*/

#ifndef CONFIGURATON_HPP
#define CONFIGURATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Configuration
{
public:
    void init(sf::Font &font, const std::vector<std::string> textString, const std::vector<int> characterSize, const std::vector<sf::Vector2f> position, int cursorBegin, int cursorEnd);
    void colorAnimation();
    void selectionCursor(const bool dir);
    void moveCursor(); 
    void draw(sf::RenderWindow &window);
protected:
    std::vector<sf::Text> m_text;
    int m_cursor, m_cursorBegin, m_cursorEnd;
    bool m_colorAnimation = true, m_releaseInput = true;
    sf::Clock m_keyWait, m_colorAnimationWait;
};

#endif