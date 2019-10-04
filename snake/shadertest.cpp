#include <SFML/Graphics.hpp>
#include <time.h>
#include"player.h"
using namespace sf;

const int W = 600;
const int H = 480;
int speed = 4;
bool field[W][H] = { 0 };

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(W, H), "The Tron Game!");
	window.setFramerateLimit(60);

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

	player p1(Color::Red,W/2,H/2), p2(Color::Green,W,H);

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
	t.clear();  t.draw(sBackground);

	bool Game = 1;

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir != RIGHT) p1.dir = LEFT;
		if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir != LEFT)  p1.dir = RIGHT;
		if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir != DOWN) p1.dir = UP;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir != UP) p1.dir = DOWN;

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir != RIGHT) p2.dir = LEFT;
		if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir != LEFT)  p2.dir = RIGHT;
		if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir != DOWN) p2.dir = UP;
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir != UP) p2.dir = DOWN;

		//if (!Game)    continue;

		for (int i = 0; i < speed; i++)
		{
			p1.tick(); p2.tick();
			if (field[p1.x][p1.y] == 1) Game = 0;
			if (field[p2.x][p2.y] == 1) Game = 0;
			field[p1.x][p1.y] = 1;
s			field[p2.x][p2.y] = 1;

			CircleShape c(3);
			c.setPosition(p1.x, p1.y); c.setFillColor(p1.color);    t.draw(c);
			c.setPosition(p2.x, p2.y); c.setFillColor(p2.color);    t.draw(c);
			t.display();
		}

		////// draw  ///////
		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}
