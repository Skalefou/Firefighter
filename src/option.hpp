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
    void run(sf::RenderWindow &window, Sound &sound, bool &m_optionOn);
    void enterChoice(sf::RenderWindow &window, Sound &sound, bool &m_optionOn);
    void closeOption();
private:
    sf::Clock m_choiceWait;
    sf::RectangleShape m_outlines;
    bool m_releaseInput = true;
};

#endif