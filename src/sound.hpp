/*
file: sound.hpp
author: Skalefou
description: Header managing the "Sound" class which directly or indirectly manages sound and music
*/
#ifndef SOUND_HPP
#define SOUND_HPP

#include <vector>
#include <memory>
#include <string>
#include <SFML/Audio.hpp>

enum {MAIN_THEME_MUSIC, GAME_MUSIC, GAME_OVER_MUSIC};
enum {SELECTION_SOUND, DEAD_SOUND};

class Sound
{
public:
    Sound();
    std::string setVolumeMusic(const float v);
    std::string setVolumeSound(const float v);
    void stopMusic();
    void stopSound();
    void playMusic(const int id);
    void playSound(const int id);
    float getVolumeMusic() const;
    float getVolumeSound() const;
    void FreeMenuMusic();
private:
    std::vector <sf::Music*> m_music;
    const std::vector <std::string> m_nameMusicFile {"data/mainTheme.ogg", "data/game.ogg", "data/gameOver.ogg"}, m_nameSoundFile {"data/selectionSound.ogg", "data/dead.ogg"};
    float m_volumeSound = 100.f, m_volumeMusic = 100.f;
    std::vector <sf::SoundBuffer> m_buffer;
    std::vector <std::shared_ptr<sf::Sound>> m_sound;
};

#endif