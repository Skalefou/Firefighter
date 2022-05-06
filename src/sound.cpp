/*
file: menu.cpp
author: Skalefou
description: File managing the functions of the Sound class which directly or indirectly manages sound and music
*/
#include "sound.hpp"

Sound::Sound()
{
   /* for(int i = 0; i < std::size(m_nameMusicFile); i++)
        m_music.push_back(new sf::Music);

    m_music[0]->play();*/
    f.openFromFile("data/mainTheme.ogg");
    f.play();
}