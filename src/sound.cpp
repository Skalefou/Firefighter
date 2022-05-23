/*
file: menu.cpp
author: Skalefou
description: File managing the functions of the Sound class which directly or indirectly manages sound and music
*/
#include "sound.hpp"

Sound::Sound()
{
   for(int i = 0; i < std::size(m_nameMusicFile); i++)
    {
        m_music.push_back(new sf::Music);
        m_music[i]->openFromFile(m_nameMusicFile[i]);
        m_music[i]->setLoop(true);
    }

    for(int i = 0; i < std::size(m_nameSoundFile); i++)
    {
        m_buffer.push_back(sf::SoundBuffer{});
        m_buffer[i].loadFromFile(m_nameSoundFile[i]);
    }

    for(int i = 0; i < std::size(m_buffer); i++)
    {
        m_sound.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
        m_sound[i]->setBuffer(m_buffer[i]);
    }

    m_music[MAIN_THEME_MUSIC]->play();
}

std::string Sound::setVolumeMusic(const float v)
{
    if(v >= 0.f && v <= 100.f)
    {
        m_volumeMusic = v;
        for(int i = 0; i < std::size(m_music); i++)
           m_music[i]->setVolume(m_volumeMusic);
    }
     return "Music : " + std::to_string((int)(m_volumeMusic/10));
}

std::string Sound::setVolumeSound(const float v)
{
    if(v >= 0.f && v <= 100.f)
    {
        m_volumeSound = v;
        for(int i = 0; i < std::size(m_sound); i++)
            m_sound[i]->setVolume(m_volumeSound);
    }
    return "Sound : " + std::to_string((int)(m_volumeSound/10));
}

void Sound::stopMusic()
{
    for(int i = 0; i < std::size(m_music); i++)
        m_music[i]->stop();
}

void Sound::stopSound()
{
    for(int i = 0; i < std::size(m_sound); i++)
        m_sound[i]->stop();
}
    
void Sound::playMusic(const int id)
{
    m_music[id]->play();
}

void Sound::playSound(const int id)
{
    m_sound[id]->play();
}

float Sound::getVolumeMusic() const
{
    return m_volumeMusic;
}

float Sound::getVolumeSound() const
{
    return m_volumeSound;
}

void Sound::FreeMenuMusic()
{
    delete m_music[MAIN_THEME_MUSIC];
}