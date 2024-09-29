#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include "Field.hpp"

class Game
{
public:
	Game(int w, int h);

	void OnEvent(sf::Event e);
	void OnUpdate();
	void Render(sf::RenderTarget& wnd);

private:
	int wndWidth;
	int wndHeight;

	Field field;
	sf::Clock fieldClock;
	float updateSpeed = 0.20f;
	float timePassed = 0.0f;
};
