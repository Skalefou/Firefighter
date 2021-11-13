/*
* audio.hpp
* Author : Skalefou
* Creation date: 13/11/2021 (D/M/Y)
* Date of last update : 13/11/2021 (D/M/Y)
*
* The file describes the "Audio" class
*/

#ifndef AUDIO_HPP
#define AUDIO_HPP
#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class Audio
{
public:
	Audio();
	void setVolumeMusic(const float v);
	void setVolumeSound(const float v);
	void deleteMusicTheme();
	~Audio();
private:
	bool m_musicThemeUse;
	float m_volumeMusic, m_volumeSound;
	std::vector <sf::SoundBuffer> m_buffer;
	std::vector <bool> accessMusic, accessSound;
	std::vector <sf::Sound> m_sound;
	std::vector <sf::Music*> m_music;
	std::vector <std::string> m_nameFileMusic, m_nameFileSound;

	/*
	* m_musicThemeUse : If this variable is equal to "true" then, the main menu music is deleted from memory.
	* m_volumeMusic, m_volumeSound : Music/sound volume, it is fixed between 0.f and 100.f.
	* m_buffer: vector containing the audio files of the sounds.
	* accessMusic, accessSound : bool vector determining whether a music is available for playback or not. Useful when a file is deleted.
	* m_sound: vector containing the audio files of the sounds.
	* m_music: vector containing the audio files of the musics.
	* m_nameFileMusic, m_nameFileSound : vector of string containing the path of the audio files.
	*/
};

#endif
