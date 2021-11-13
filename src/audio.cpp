/*
* audio.cpp
* Author : Skalefou
* Creation date: 13/11/2021 (D/M/Y)
* Date of last update : 13/11/2021 (D/M/Y)
* 
* This file has all the methods of the "Audio" class.
*/

#include "audio.hpp"

//Initializes the attributes of the Audio class
Audio::Audio() : m_nameFileMusic{ "data/mainTheme.ogg", "data/game.ogg", "data/gameOver.ogg" }, m_nameFileSound{ "data/selectionSound.ogg", "data/dead.ogg" },
m_musicThemeUse(true), m_volumeMusic(100.f), m_volumeSound(100.f)
{
	//Fill the values of accessMusic and accessSound to "true"
	accessMusic.assign(std::size(m_nameFileMusic), true);
	accessSound.assign(std::size(m_nameFileSound), true);

	//Loads music files.
	for (unsigned int i = 0; i < std::size(m_nameFileMusic); i++)
	{
		m_music.push_back(new sf::Music);
		if (!m_music[i]->openFromFile(m_nameFileMusic[i]))
			accessMusic[i] = false;
	}

	//Set the music files by setting the volume to them and activating repeat when the music files are finished.
	setVolumeMusic(m_volumeMusic);
	for(unsigned int i = 0; i < std::size(m_music); i++)
		if(m_nameFileMusic[i] != "data/gameOver.ogg")
			m_music[i]->setLoop(true);

	//Load sound files.
	const sf::SoundBuffer a;
	const sf::Sound b;
	for (unsigned int i = 0; i < std::size(m_nameFileSound); i++)
	{
		m_buffer.push_back(a);
		m_sound.push_back(b);
		if (!m_buffer[i].loadFromFile(m_nameFileSound[i]))
			accessSound[i] = false;
		else
			m_sound[i].setBuffer(m_buffer[i]);
	}
	//Fix the volume of the sound files.
	setVolumeSound(m_volumeSound);
	//If the main menu music file is available then play the music file.
	if(accessMusic[0])
		m_music[0]->play();
}

//setVolumeMusic(float) : allows you to change the volume of the music.
void Audio::setVolumeMusic(const float v)
{
	m_volumeMusic = v;
	for (unsigned int i = 0; i < std::size(m_music); i++)
		m_music[i]->setVolume(v);
}

//setVolumeSound(float) : allows you to change the sound volume.
void Audio::setVolumeSound(const float v)
{
	m_volumeSound = v;
	for (unsigned int i = 0; i < std::size(m_sound); i++)
		m_sound[i].setVolume(v);
}

//deleteMusicTheme() : Allows you to delete the music file from the main menu from memory.
void Audio::deleteMusicTheme()
{
	m_musicThemeUse = false;
	m_music[0]->stop();
	delete m_music[0];
}

//Frees dynamically allocated variables in memory.
Audio::~Audio()
{
	for (unsigned int i = !m_musicThemeUse; i < std::size(m_nameFileMusic); i++)
		delete m_music[i];
}