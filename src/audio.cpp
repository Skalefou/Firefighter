/*
* audio.cpp
* Author : Skalefou
* Creation date: 13/11/2021 (D/M/Y)
* Date of last update : 31/12/2021 (D/M/Y)
*
* This file has all the methods of the "Audio" class.
*/

#include "audio.hpp"

//Initializes the attributes of the Audio class
Audio::Audio() : m_nameFileMusic{ "data/mainTheme.ogg", "data/game.ogg", "data/gameOver.ogg" }, m_nameFileSound{ "data/selectionSound.ogg", "data/dead.ogg", "data/selectionSound.ogg" },
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
	for (unsigned int i = 0; i < std::size(m_music); i++)
		if (m_nameFileMusic[i] != "data/gameOver.ogg")
			m_music[i]->setLoop(true);
	
	//Loads Buffer file
	for (unsigned int i = 0; i < std::size(m_nameFileSound); i++)
	{
		m_buffer.push_back(sf::SoundBuffer{});
		if (!m_buffer[i].loadFromFile(m_nameFileSound[i]))
			accessSound[i] = false;
	}

	//Loads Sound file
	for (unsigned int i = 0; i < std::size(m_buffer); i++)
	{
		m_sound.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
		if (accessSound[i])
			m_sound[i]->setBuffer(m_buffer[i]);
	}
	//Fix the volume of the sound files.
	setVolumeSound(m_volumeSound);
	//If the main menu music file is available then play the music file.
	if (accessMusic[0])
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
		m_sound[i]->setVolume(v);
}

//returns the attribute "m_volumeSound"
float Audio::getVolumeSound() const
{
	return m_volumeSound;
}

//returns the attribute "m_volumeMusic"
float Audio::getVolumeMusic() const
{
	return m_volumeMusic;
}

//Play a particular sound according to the "soundExecute" variable
void Audio::playSound(const unsigned int soundExecute)
{
	stopSound();
	if (soundExecute < std::size(m_sound))
		if (accessSound[soundExecute])
			m_sound[soundExecute]->play();
}

//stop all music.
void Audio::stopMusic()
{
	for (unsigned int i = 0; i < std::size(m_music); i++)
		m_music[i]->stop();
}

//Stop all sound.
void Audio::stopSound()
{
	for (unsigned int i = 0; i < std::size(m_sound); i++)
		m_sound[i]->stop();
}

//Free dynamically allocated variables in memory.
Audio::~Audio()
{
	for (unsigned int i = 0; i < std::size(m_nameFileMusic); i++)
		delete m_music[i];

}