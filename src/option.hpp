/*
file: option.hpp
author: Skalefou
description: Header managing the Option class that handles in-game configuration.
*/

#ifndef OPTION_HPP
#define OPTION_HPP

#include "configuration.hpp"

class Option : public Configuration
{
public:
    Option();
    void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape m_outlines;
};

#endif