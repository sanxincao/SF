#include <SFML/Graphics.hpp>
#include <time.h>
#include"player.h"
using namespace sf;

const int W = 600;
const int H = 480;
int speed = 4;
//bool field[W][H] = { 0 };
RenderWindow window(VideoMode(W, H), "HHH");
Sprite sprite;
player p1(Color::Red, W / 2, H / 2), p2(Color::Green, W, H);
vector<CircleShape> tail;
CircleShape F(3);
CircleShape c(3);
struct Fruit
{
	int x, y;
} fruit;
void  getfruit()
{
	srand(time(0));
	fruit.x = rand() % W; fruit.y = rand() % H;
}
void initail()
{
	getfruit();
	window.setFramerateLimit(60);
	tail.push_back(c);

}
void draw()
{
	window.clear();
	
	window.draw(sprite);
	window.display();
}
void input()
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir != RIGHT) p1.dir = LEFT;
	if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir != LEFT)  p1.dir = RIGHT;
	if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir != DOWN) p1.dir = UP;
	if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir != UP) p1.dir = DOWN;

	if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir != RIGHT) p2.dir = LEFT;
	if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir != LEFT)  p2.dir = RIGHT;
	if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir != DOWN) p2.dir = UP;
	if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir != UP) p2.dir = DOWN;

}
void logic()
{
	if (p2.x[0] == fruit.x && p2.y[0] == fruit.y)
	{
		p2.eat = true;
		tail.push_back(c);
		getfruit();
	}

}
int main()
{
	

	//RenderWindow window(VideoMode(W, H), "The Tron Game!");
	
	initail();
	Texture texture;
	texture.loadFromFile("images/background.jpg");
	Sprite sBackground(texture);
	
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
	t.clear();  t.draw(sBackground);

	bool Gameover = 1;

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		//
		input();
		//if (!Gameover)    continue;

		for (int i = 0; i < speed; i++)
		{
			//t.clear();
			logic();
			p1.tick(); p2.tick();
			
			//if (field[p1.x][p1.y] == 1) Gameover = 0;
			//if (field[p2.x][p2.y] == 1) Gameover = 0;
			//field[p1.x][p1.y] = 1;
			//field[p2.x][p2.y] = 1;
			//这条蛇不能复位
			//CircleShape * c=new CircleShape(3);
			
			
			//c.setPosition(p1.x, p1.y); c.setFillColor(p1.color);    t.draw(c);
			for (size_t i = 0; i < p2.length; i++)
			{
				//c.setPosition(p2.x[i], p2.y[i]);
				//c.setFillColor(p2.color);
				//t.draw(c);
				tail[i].setPosition(p2.x[i], p2.y[i]);
				tail[i].setFillColor(p2.color);
				window.draw(tail[i]);
			}
			F.setPosition(fruit.x, fruit.y);
			F.setFillColor(Color::Red);
			window.draw(F);
			   
			window.display();
		}
		//window.draw(sBackground);
		////// draw  ///////
		draw();
	}

	return 0;
}
