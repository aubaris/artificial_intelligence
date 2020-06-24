#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

class Application
{
public:
	Application(int width, int height);
	~Application();
	void run();

private:
	void update(sf::Time elapsedTime);
	void processEvents();
	void render();
	void handleMouseButtonPress(const sf::Event& event);
	void handleKey(const sf::Event& event);

	sf::RenderWindow m_window;
	TileMap m_map;
	sf::View m_view;

	int m_currentTilePlacingValue;
	sf::RectangleShape m_selectedTilesShape;
	sf::Vector2u m_tileSize;
	bool m_showSelectedTile;
	sf::Vector2u m_mapSize;
};

#endif