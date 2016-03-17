#include <iostream>
#include <Windows.h>

using namespace std;

void placeKurs(int x, int y)
{
	COORD position;                                     // Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получение дескриптора устройства стандартного вывода

	position.X = x;                                    // Установка координаты X-берем из класса
	position.Y = y;                                    // Установка координаты Y-берем из класса

	SetConsoleCursorPosition(hConsole, position);       // Перемещение каретки по заданным координатам
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Конструкция для изменения размера окна консоли и ликвидации полос прокрутки на WinApi
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 20, 20 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	
	for (int i = 0; i < 20; i++)
	{
		placeKurs(10, i);
		cout << "*";
	}

	placeKurs(4, 19);
	cout << "#";
	placeKurs(6, 19);
	cout << "#";
	placeKurs(5, 18);
	cout << "#";
	placeKurs(5, 17);
	cout << "#";
	placeKurs(5, 16);
	cout << "#";
	placeKurs(4, 17);
	cout << "#";
	placeKurs(6, 17);
	cout << "#";

	placeKurs(13, 5);
	cout << "Счет";

	int Score = 250;
	placeKurs(13, 6);
	cout << Score;

	cin.get();
	return 0;
}