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
	eDirecton dir=STOP;
	Color color;
	//player();
	player(Color c,int W,int H)
	{
		//x = rand() % W;
		//y = rand() % H;
		x = W / 2;
		y = H / 2;
		color = c;
		dir = STOP;
	}
	void tick()
	{
		if (dir == DOWN) y--;
		if (dir == UP) y++;
		if (dir == RIGHT) x++;
		if (dir == LEFT) x--;

		//if (x >= W) x = 0;  if (x < 0) x = W - 1;
		//if (y >= H) y = 0;  if (y < 0) y = H - 1;
	}
	//~player();

private:
	Vector3f getColor();
};

#endif // !1