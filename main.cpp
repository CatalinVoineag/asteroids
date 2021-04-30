#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Asteroids", Style::Fullscreen);

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("graphics/background.png");

	Texture shipTexture;
	shipTexture.loadFromFile("graphics/ship.png");

	Sprite shipSprite;
	shipSprite.setTexture(shipTexture);

	int windowHalfWidht = resolution.x / 2;
	int windowHalfHeight = resolution.y / 2;
	int shipHalfWidht = shipSprite.getGlobalBounds().width / 2;
	int shipHalfHeight = shipSprite.getGlobalBounds().height / 2;

	shipSprite.setPosition(
			windowHalfWidht - shipHalfWidht, windowHalfHeight - shipHalfHeight);
	
	Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear();

		window.draw(backgroundSprite);
		window.draw(shipSprite);

		window.display();
	}
	return 0;
}

