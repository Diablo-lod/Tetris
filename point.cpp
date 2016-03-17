#include <Windows.h>
#include <iostream>
#include "point.h"

using namespace std;


point::point(int konst_x, int konst_y, char konst_sym)
{
	x = konst_x;
	y = konst_y;
	sym = konst_sym;
}

void point::set_x(int set_x)
{
	x = set_x;
}

void point::set_y(int set_y)
{
	y = set_y;
}

void point::set_sym(char set_sym)
{
	sym = set_sym;
}

char point::get_sym()
{
	return sym;
}
//функция отрисовки точки с заданными координатами по х и у.
void point::Draw()
{
	COORD position;                                     // Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получение дескриптора устройства стандартного вывода

	position.X = x;                                    // Установка координаты X-берем из класса
	position.Y = y;                                    // Установка координаты Y-берем из класса

	SetConsoleCursorPosition(hConsole, position);       // Перемещение каретки по заданным координатам

	cout << sym;// << endl;
}

void point::Move(int offset, direction::Direction Dir)
{
	if (Dir == direction::Direction::RIGHT)
	{
		x = x + offset;
	}
	else if (Dir == direction::Direction::LEFT)
	{
		x = x - offset;
	}
	else if (Dir == direction::Direction::UP)
	{
		y = y - offset;
	}
	else if (Dir == direction::Direction::DOWN)
	{
		y = y + offset;
	}
}

void point::clear()
{
	sym = ' ';
	Draw();
}

bool point::IsHit(point p)
{
	return x == p.x && y == p.y;
}
