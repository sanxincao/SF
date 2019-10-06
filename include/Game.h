#pragma once

#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>
#include<SFML/Network.hpp>
#include<SFML/Graphics.hpp>
class game
{
public:
	game();
	virtual ~game();
	void update();
	void redner();
	const bool isrunning() const;
private:
	sf::RenderWindow* window;
	sf::VideoMode vm;
	sf::Event ev;

	void InitVar();
	void InitWindow();
};

void game::InitVar()
{
	this->window = nullptr;
}
void game::InitWindow()
{
	this->vm.height = ;
	this->vm.width = ;
	this->window = new sf::RenderWindow(this->vm, "", sf::Style::Titlebar | sf::Style::Close);
}

game::game()
{
	this->InitVar();
	this->InitWindow();
}
const bool game::isrunning() const
{
	return this->window->isOpen();
}

game::~game()
{
	delete this->window;
}
