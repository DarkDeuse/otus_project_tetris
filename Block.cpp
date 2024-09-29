#include "Block.hpp"


void Block::Render(sf::RenderTarget & wnd, Type type, int xPos, int yPos, int tileSize, int rota)
{
	std::vector<char> myData = GetBlockData(type, rota);

	sf::RectangleShape tile;
	tile.setSize(sf::Vector2f(tileSize, tileSize));
	tile.setFillColor(GetColor(type));
	for (int i = 0; i < 16; i++) {
		if (myData[i] == 0)
			continue;

		tile.setPosition(xPos + (i%4) * tileSize, yPos + (i/4) * tileSize);
		wnd.draw(tile);
	}
}
std::vector<char> Block::GetBlockData(Type type, int rota)
{
	static const int RotaCount[Type::Count] = {
		2,	// I
		1,	// O
		4,	// T
		2,	// S
		2,	// Z
		4,	// J
		4,	// L
	};

	static const std::vector<std::vector<char>> data = {
		// I
		{
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0 
		},
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
		},

		// O
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0,
		},

		// T
		{
			0, 0, 0, 0,
			0, 1, 1, 1,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 0,
			0, 0, 1, 1,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 0,
			0, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		},

		// S
		{
			0, 0, 0, 0,
			0, 0, 1, 1,
			0, 1, 1, 0,
			0, 0, 0, 0,
		},
		{
			0, 0, 1, 0,
			0, 0, 1, 1,
			0, 0, 0, 1,
			0, 0, 0, 0,
		},

		// Z
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 1,
			0, 0, 0, 0,
		},
		{
			0, 0, 0, 1,
			0, 0, 1, 1,
			0, 0, 1, 0,
			0, 0, 0, 0,
		},

		// J
		{
			0, 0, 0, 0,
			0, 1, 1, 1,
			0, 0, 0, 1,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 1,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 1, 0, 0,
			0, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},


		// L
		{
			0, 0, 0, 0,
			0, 1, 1, 1,
			0, 1, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 1,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 1,
			0, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		}
	};

	rota = rota % RotaCount[type];
	
	int offset = 0;
	for (int i = 0; i < type; i++) {
		offset += RotaCount[i];
	}

	
	return data[offset + rota];
}
std::vector<sf::Vector2i> Block::GetCollisionTiles(Type type, int rota)
{
	std::vector<char> data = Block::GetBlockData(type, rota);
	std::vector<sf::Vector2i> ret;

	for (int i = 0; i < 16; i++) {
		int x = i % 4;
		int y = i / 4;
		int indexBelow = (y + 1) * 4 + x;

		if (data[y * 4 + x] != 0) {
			if (indexBelow >= 16 || data[indexBelow] == 0)
				ret.push_back(sf::Vector2i(x, y + 1));
		}
	}

	return ret;
}

sf::Color Block::GetColor(Type type)
{
	static const sf::Color Colors[(int)Block::Count] = {
		sf::Color(199, 12, 12),
		sf::Color(13, 20, 214),
		sf::Color(34, 140, 7),
		sf::Color(145, 80, 4),
		sf::Color(145, 133, 17),
		sf::Color(13, 119, 143),
		sf::Color(183, 196, 195)
	};
	return Colors[type];
}

