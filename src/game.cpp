/*
file: game.cpp
author: Skalefou
description: file managing the functions of the Game class that manipulates the whole game.
*/

#include "game.hpp"

void Game::init(sf::Font &font, Sprite &sprite)
{
    m_option.init(font, {"Pause", "Continue", "Sound : 10", "Music : 10", "Quit"}, {46, 36, 36, 36, 36}, {sf::Vector2f(191.f, 118.f), sf::Vector2f(181.f, 173.f), sf::Vector2f(181.f, 215.f), sf::Vector2f(181.f, 257.f), sf::Vector2f(181.f, 299.f), sf::Vector2f(181.f, 341.f)}, 1, 4);
    sprite.changePosition(PLAYER_SPRITE, sf::Vector2f(224, 224));
}

void Game::keyEnter(int &stategame, Sound &sound, Sprite &sprite)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_activeKey)
    {
        if(!m_optionOn)
        {
            sound.pauseMusic(GAME_MUSIC);
            m_optionOn = true;
        }
        else if (m_optionOn)
        {
            m_optionOn = false;
            m_option.closeOption(sound);
        }
        m_activeKey = false;
        sound.playSound(PAUSE_SOUND);
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_activeKey == false)
        m_activeKey = true;
    if (!m_optionOn)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            m_map.MovePositionPlayer(sprite, RIGHT_PLAYER_MOVE);
    }
}

void Game::run(sf::RenderWindow &window, int &stategame, Sound &sound, Sprite &sprite)
{
    keyEnter(stategame, sound, sprite);
    draw(window, stategame, sprite);
    if(m_optionOn)
        m_option.run(window, sound, m_optionOn);
}

void Game::draw(sf::RenderWindow &window, int &stategame, Sprite &sprite)
{
    if(m_optionOn)
        m_option.draw(window);
    else
    {
        sprite.draw(window, PLAYER_SPRITE);
    }
}