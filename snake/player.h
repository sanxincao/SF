#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
using std::vector;
using sf::Color;
using sf::Vector3f;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
class player
{
public:
	vector<int> x, y;
	eDirecton dir=LEFT;
	int width, heigh;
	int length;
	Color color;
	bool eat = false;
	//player();
	player(Color c,int W,int H)
	{
		length = 1;
		width = W;
		heigh = H;
		//x = rand() % W;
		//y = rand() % H;
		x.push_back(W / 2) ;
		y.push_back(H / 2);
		color = c;
		dir = STOP;
	}
	void tick()
	{
		for (size_t i = x.size()-1; i >0; i--)
		{
			x[i] = x[i - 1]; y[i] = y[i - 1];

		}
		if (eat == true)
		{
			x.push_back(x[x.size()]);
			y.push_back(y[y.size()]);
			eat = false;
		}
		if (dir == DOWN) y[0]++;
		if (dir == UP) y[0]--;
		if (dir == RIGHT) x[0]++;
		if (dir == LEFT) x[0]--;

		if (x[0] >= width) x[0] = 0;  if (x[0] < 0) x[0] = width - 1;
		if (y[0] >= heigh) y[0] = 0;  if (y[0] < 0) y[0] = heigh - 1;
	}
	//~player();

private:
	
	Vector3f getColor();
};

#endif // !1