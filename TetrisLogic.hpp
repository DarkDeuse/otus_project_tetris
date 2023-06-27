#pragma once
#include"Enviromental.hpp"
#include "GameSound.hpp"
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <math.h>

class Tetrislogic
{
public:
	enum class direction { left = -1, nuLL, right };
	enum class ch { x, y, rotation };
	explicit Tetrislogic(sf::RenderWindow&, sf::Vector2f, sf::Vector2i, float);
	void tetDirection(direction);
	void draw();
	void update(sf::Time const&);
	void rotate();
	sf::Vector2f getPositio();
	void speed();
	void restart();
	int getscore() const;
	void mustet(bool);
	void maket(sf::Vector2f);

    private:
	const int height;
	const int width;
	const  float click_dy = 1.0f;
	std::vector<std::vector<sf::Color>> square;
	std::array<std::array<int, 4>, 7> figures
	{ {{1,3,5,7},{2,4,5,7},{3,4,5,6},{3,4,5,7},{2,3,5,7},{3,5,6,7},{2,3,4,5}} };
	std::array<sf::Vector2f, 4> t;
	std::array<sf::Color, 7> tetcolor{ {sf::Color::Blue,sf::Color::Cyan,sf::Color::Yellow,
		sf::Color::Green,sf::Color::Magenta,sf::Color::Red,sf::Color::White} };
	std::unique_ptr<sf::RectangleShape> cube = std::make_unique<sf::RectangleShape>();
	long long seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rnd = std::default_random_engine(static_cast<long>(seed));
	std::uniform_int_distribution<int> d = std::uniform_int_distribution<int>(0, 6);
	sf::RenderWindow& window;
	const sf::Vector2f tet;
	sf::Time frameRate;
	sf::Vector2i typeTet;
	sf::Vector2i colTet;
	void newFigrois();
	void lineDead(int);
	bool check(ch);
	sf::Int32 delay;
	float click_dx;
	int score;
	bool playMus = false;
	GameSound mus;
	float scale;
	sf::Vector2f positionmaket= sf::Vector2f(-1, -1);
};