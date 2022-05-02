/*
file: menu.cpp
author: Skalefou
description: file managing the functions of the Menu class which includes the whole program
*/
#include "menu.hpp"

 void Menu::run(sf::RenderWindow &window)
 {
     moveCursor();
     colorAnimation();
     draw(window);
 }