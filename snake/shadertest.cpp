#include"player.h"
using namespace sf;
const int Width = 600;
const int Heigh = 480;
int speed = 4;
bool field[Width][Heigh] = { 0 };
bool gameover;
RenderWindow window(VideoMode(Width, Heigh), "snake with shader");
Texture tex;
Sprite background(tex);
player snake(Color::Red, Width, Heigh);
Sprite sprite;
RenderTexture t;
void Initial()
{
	//srand(time(0));
	bool gameover = true;
	window.setFramerateLimit(60);
	tex.loadFromFile("background.jpg");
	t.create(Width, Heigh);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
	t.clear();  t.draw(background);
}

void Input()
{
	Event e;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
			window.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) if (snake.dir != RIGHT) snake.dir = LEFT;
	if (Keyboard::isKeyPressed(Keyboard::D)) if (snake.dir != LEFT)  snake.dir = RIGHT;
	if (Keyboard::isKeyPressed(Keyboard::W)) if (snake.dir != DOWN) snake.dir = UP;
	if (Keyboard::isKeyPressed(Keyboard::S)) if (snake.dir != UP) snake.dir = DOWN;
}

void Logic()
{
	if (snake.x >= Width) snake.x = 0;  if (snake.x < 0) snake.x = Width - 1;
	if (snake.y >= Heigh) snake.y = 0;  if (snake.y < 0) snake.y = Heigh - 1;
}

void draw()
{
	for (size_t i = 0; i < speed; i++)
	{
		CircleShape c(3);
		c.setPosition(snake.x, snake.y);
		c.setFillColor(snake.color);
		t.draw(c);
	}
	window.clear();
	window.draw(sprite);
	window.display();
}
int main()
{
	Initial();
	while (window.isOpen())
	{
		Input();
		Logic();
		draw();
	}
	return 0;
}

