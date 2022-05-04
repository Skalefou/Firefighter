/*
file: sound.hpp
author: Skalefou
description: Header managing the "Sound" class which directly or indirectly manages sound and music
*/
#ifndef SOUND_HPP
#define SOUND_HPP

#include <vector>
#include <memory>
#include <SFML/Audio.hpp>

class Sound
{
public:
    Sound();
private:
    std::vector <sf::Music*> m_music;
};

#endif