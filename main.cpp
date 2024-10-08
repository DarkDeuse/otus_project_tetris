#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	srand(time(NULL));

	sf::RenderWindow wnd(sf::VideoMode(600, 760), "Tetris", sf::Style::Titlebar | sf::Style::Close);
	wnd.setFramerateLimit(30);
	sf::Event e;

	Game game(wnd.getSize().x, wnd.getSize().y);

	while (wnd.isOpen()) {
		while (wnd.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				wnd.close();
			game.OnEvent(e);
		}

		game.OnUpdate();

		wnd.clear();
		game.Render(wnd);
		wnd.display();
	}


	return 0;
}