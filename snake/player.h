#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <time.h>
using sf::Color;
using sf::Vector3f;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
class player
{
public:
	int x, y;
	eDirecton dir=LEFT;
	int width, heigh;
	Color color;
	//player();
	player(Color c,int W,int H)
	{
		width = W;
		heigh = H;
		//x = rand() % W;
		//y = rand() % H;
		x = W / 2;
		y = H / 2;
		color = c;
		dir = STOP;
	}
	void tick()
	{
		if (dir == DOWN) y++;
		if (dir == UP) y--;
		if (dir == RIGHT) x++;
		if (dir == LEFT) x--;

		if (x >= width) x = 0;  if (x < 0) x = width - 1;
		if (y >= heigh) y = 0;  if (y < 0) y = heigh - 1;
	}
	//~player();

private:
	Vector3f getColor();
};

#endif // !1