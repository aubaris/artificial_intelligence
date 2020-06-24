#include "Application.hpp"
#include <iostream>
#include <fstream>

Application::Application(int width, int height)
	:
	m_window(sf::VideoMode(width, height), "artificial intelligence", sf::Style::Default),
	m_currentTilePlacingValue(-1),
	m_showSelectedTile(false)
{
	m_window.setFramerateLimit(60);

	m_selectedTilesShape.setFillColor(sf::Color(255, 100, 100, 180));
}

Application::~Application()
{

}

void Application::run()
{
	sf::Clock clock;
	while(m_window.isOpen())
	{
		processEvents();
		update(clock.restart());
		render();
	}
}

void Application::update(sf::Time elapsedTime)
{
}

void Application::processEvents()
{
	sf::Event event;
	while(m_window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseMoved:
				break;
			case sf::Event::MouseButtonPressed:
				handleMouseButtonPress(event);
				break;
			case sf::Event::MouseButtonReleased:
				break;
			case sf::Event::MouseWheelScrolled:
				break;
			case sf::Event::KeyPressed:
				handleKey(event);
				break;
			case sf::Event::Resized:
				break;
			default:
				;
		}
	}
}

void Application::handleKey(const sf::Event& event)
{
	switch (event.key.code)
	{
		case sf::Keyboard::Add:
			m_view.zoom(0.95f);
			break;
		case sf::Keyboard::Subtract:
			m_view.zoom(1.05f);
			break;
		//case sf::Keyboard::Up:
		//case sf::Keyboard::W:
		//	m_view.move(0, -cfg::MAP_SCROLL_OFFSET);
		//	break;
		//case sf::Keyboard::Down:
		//case sf::Keyboard::S:
		//	m_view.move(0, cfg::MAP_SCROLL_OFFSET);
		//	break;
		//case sf::Keyboard::Left:
		//case sf::Keyboard::A:
		//	m_view.move(-cfg::MAP_SCROLL_OFFSET, 0);
		//	break;
		//case sf::Keyboard::Right:
		//case sf::Keyboard::D:
		//	m_view.move(cfg::MAP_SCROLL_OFFSET, 0);
		//	break;
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		default:
			break;
	}
}

void Application::render()
{
	m_window.clear(sf::Color(100, 100, 100));

	//TileMap
	m_window.setView(m_view);
	m_window.draw(m_map);
	if (m_showSelectedTile)
		m_window.draw(m_selectedTilesShape);

	m_window.display();
}

void Application::handleMouseButtonPress(const sf::Event& event)
{
}
