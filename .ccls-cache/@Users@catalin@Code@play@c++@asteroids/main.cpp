#include <sstream>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

using namespace sf;
using namespace std;

float distanceBetweenTwoVectors(Vector2f origin, Vector2f destination);

int main()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width / 2;
	resolution.y = VideoMode::getDesktopMode().height / 2;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Asteroids");

  CircleShape circle(100.f);
  circle.setOutlineThickness(10.f);
  circle.setFillColor(Color(0, 0, 0, 0));
  circle.setOutlineColor(Color(100, 250, 50));
  circle.setOrigin(circle.getRadius(), circle.getRadius());
  circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);

  CircleShape ship(10.f);
  ship.setFillColor(Color(255, 0, 0));
  ship.setOrigin(ship.getRadius(), ship.getRadius());
	ship.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

	Clock clock;

  float movementSpeed = 0.10f;

  while (window.isOpen())
  {
    window.clear();

    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

    if (Keyboard::isKeyPressed(Keyboard::A)) {
        ship.move(-movementSpeed, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        ship.move(movementSpeed, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        ship.move(0.f, -movementSpeed);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        ship.move(0.f, movementSpeed);
    }

    float distance = distanceBetweenTwoVectors(ship.getPosition(), circle.getPosition());
    cout << distance << endl;

    if (distance < circle.getRadius()) {
      circle.setOutlineColor(Color(255, 0, 0));
    } else {
      circle.setOutlineColor(Color(100, 250, 50));
    }

		window.draw(ship);
		window.draw(circle);
		window.display();

    Time dt = clock.restart();
	}
	return 0;
}

float distanceBetweenTwoVectors(Vector2f origin, Vector2f destination) {

  Vector2f diff = destination - origin;

  return sqrt( (diff.x * diff.x) + (diff.y * diff.y) );
}
