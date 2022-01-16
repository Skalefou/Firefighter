/*
* sprite.cpp
* Author : Skalefou
* Creation date: 16/01/2022 (D/M/Y)
* Date of last update : 16/01/2022 (D/M/Y)
*
* This file has all the methods of the "Sprite" class.
*/

#include "sprite.hpp"

Sprite::Sprite()
{
	for (unsigned int i = 0; i < NUMBER_TEXTURE; i++)
	{
		m_texture[i].loadFromFile(m_nameFileTexture[i]);
		m_sprite[i].setTexture(m_texture[i]);
	}
}

void Sprite::rotatePlayer(const unsigned int dir)
{
	m_sprite[0].setRotation(dir * 90.f);
}

void Sprite::draw(sf::RenderWindow &window, const unsigned int id)
{
	window.draw(m_sprite[id]);
}
