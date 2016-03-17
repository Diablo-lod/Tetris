#pragma once
#include "direction.h"

class point
{
private:
	int x = 0;
	int y = 0;
	char sym;
public:
	point();
	//����������� ������ � ��������� ���� ��������. ���������+������
	point(int konst_x, int konst_y, char konst_sym);

	//	point(point p);

	void Move(int offset, direction::Direction Dir);

	void set_x(int set_x);

	void set_y(int set_y);

	void set_sym(char set_sym);

	char get_sym();
	//������� ��������� ����� � ��������� ������������ �� � � �.
	void Draw();

	void clear();

	bool IsHit(point p);
};