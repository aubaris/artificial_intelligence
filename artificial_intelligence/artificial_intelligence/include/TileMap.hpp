#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();
	void changeCollisionTile(unsigned int x, unsigned int y, bool collision);
	void changeTile(unsigned int x, unsigned int y, int value);
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, int tile_gap, const bool* collisionTiles);
	void changeTileFromMousePosition(float x, float y, int value);
	void changeCollisionTileFromMousePosition(float x, float y, bool collision);
	void changeTilesFromRectangle(sf::FloatRect rect, int value);
	void changeCollisionTilesFromRectangle(sf::FloatRect rect, bool collision);
	bool reload(const std::string& tileset, sf::Vector2u tileSize, unsigned int tile_gap);

	void loadFromFile(std::ifstream *file);
	void saveToFile(std::ofstream *file) const;
	const sf::Vector2u& getTileSize() const;
	const sf::Vector2u& getMapSize() const;
	const std::string& getTexturePath() const;
	int getTileGap() const;

	void showCollisionLayer();
	void hideCollisionLayer();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void updateVertices(unsigned int x, unsigned int y);
	void updateCollisionVertices(unsigned int x, unsigned int y, bool collision);

	static void writeString(std::ofstream *file, const std::string& str);
	static std::string readString(std::ifstream *file);

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::string m_texturePath;

	int *m_tiles;
	sf::Vector2u m_tileSize;
	sf::Vector2u m_mapSize;

	unsigned int m_tileGap;

	//Collision
	sf::VertexArray m_collisionVertices;
	bool *m_collisionTiles;
	bool m_showCollisionLayer;
};

#endif