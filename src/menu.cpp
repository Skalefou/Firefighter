/*
file: menu.cpp
author: Skalefou
description: File managing the functions of the Menu class which includes the whole program
*/

#include "firefighter.hpp"
#include "menu.hpp"

void Menu::enterChoice(sf::RenderWindow &window, int &stateGame, Sound &sound)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m_cursor == m_cursorBegin)
    {
        stateGame = PLAY;
        sound.stopMusic();
        sound.playSound(SELECTION_SOUND);
        sound.FreeMenuMusic();
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

void Menu::drawSprite(sf::RenderWindow &window, Sprite &sprite)
{
    sprite.draw(window, FIREFIGHTER_MENU_SPRITE);
}

 void Menu::run(sf::RenderWindow &window, int &stateGame, Sound &sound, Sprite &sprite)
 {
     moveCursor(sound);
     enterChoice(window, stateGame, sound);
     colorAnimation();
     draw(window);
     drawSprite(window, sprite);
 }