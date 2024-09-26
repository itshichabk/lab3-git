#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <Windows.h>
#include <stdio.h>
#include "point.h"

using namespace std;

Point::Point()
{
	_x = _y = 0;
	_color = 7;
}


Point::Point(int x, int y)
{
	_x = x;
	_y = y;
	_color = 7;
}

Point::Point(const Point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
}

Point::~Point()
{
	_color = _x = _y = 0;
}

Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;

	return *this;
}

bool Point::operator==(const Point& p) const
{
	return _x == p._x && _y == p._y;
}

bool Point::operator!=(const Point& p) const
{
	return _x != p._x || _y != p._y;
}

Point Point::operator+(const Point& p)
{
	_x += p._x;
	_y += p._y;

	return *this;
}

Point Point::operator-(const Point& p)
{
	_x -= p._x;
	_y -= p._y;

	return *this;
}

void Point::print(ostream& os)
{
	os << "(" << _x << "," << _y << ")";
}

void Point::read(istream& is)
{
	char vide;
	is >> vide >> _x >> vide >> _y >> vide >> _color;
}

void Point::draw(ostream& os) const
{
	goToXY(_x, _y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	cout << "\xFE";
}

int Point::getX() const
{
	return _x;
}

int Point::getY() const
{
	return _y;
}

int Point::getColor() const
{
	return _color;
}

Point Point::getPoint() const
{
	return *this;
}

void Point::setX(int x)
{
	assert(x >= 0);
	_x = x;
}

void Point::setY(int y)
{
	assert(y >= 0);
	_y = y;
}

void Point::setColor(int color)
{
	assert(color > 0 && color < 16);
	_color = color;
}

void Point::setPoint(Point& p)
{
	setX(p._x);
	setY(p._y);
	setColor(p._color);
}

void Point::setPosition(int x, int y)
{
	setX(x);
	setY(y);
}

void goToXY(int xPos, int yPos)
{
	assert(xPos >= 0 && yPos >= 0);

	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xPos;
	scrn.Y = yPos;

	SetConsoleCursorPosition(hOutput, scrn);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	p.draw(os);
	return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
	p.read(is);
	return is;
}

float distance(const Point& pA, const Point& pB)
{
	return sqrt(pow(pB._x - pA._x, 2) + pow(pB._y - pA._y, 2));
}
