/*
* sprite.hpp
* Author : Skalefou
* Creation date: 16/01/2022 (D/M/Y)
* Date of last update : 16/01/2022 (D/M/Y)
*
* This file describes the "Sprite" class
*/

#ifndef SPRITE_HPP
#define SPRITE_HPP
#pragma once

#define NUMBER_TEXTURE 1
enum {SUP, SLEFT, SDOWN, SRIGHT};
enum {PLAYER};

#include <array>
#include <string>
#include <SFML/Graphics.hpp>

class Sprite
{
public:
	Sprite();
	void rotatePlayer(const unsigned int dir);
	void draw(sf::RenderWindow& window, const unsigned int id);
private:
	std::array<sf::Texture, NUMBER_TEXTURE> m_texture;
	std::array<sf::Sprite, NUMBER_TEXTURE> m_sprite;
	std::array<std::string, NUMBER_TEXTURE> m_nameFileTexture {"data/player.png"};
};

#endif
