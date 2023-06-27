#pragma once
#include<array>
#include<SFML/Audio.hpp>
#include "Enviromental.hpp"

class GameSound
{   
	static const int n = 5;
    std::array<sf::Sound, n> GSound; 	
		
public:
  GameSound()
	{
		std::array<std::string, n> namefilebuf{ "sound/fon.mp3" ,"sound/clearline.mp3","sound/game_over.ogg",
		"sound/movetetramino.ogg","sound/down.mp3"};
		for (int i = 0; i < n; i++) GSound[i].setBuffer(AssetManager::GetSoundBuffer(namefilebuf[i]));
		GSound[0].setLoop(true);
	};
	void play(int index);
	void stop(int index);
	void AllStop();
};