#include <cassert>
#include <iostream>
#include "Rectangle.h"

using namespace std;
using namespace r;

Rectangle::Rectangle()
{
	_h = 0;
	_w = 0;
}

Rectangle::Rectangle(int w, int h)
{
	setHeight(w);
	setWidth(h);
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
	_coord.setX(x);
	_coord.setY(y);
	setHeight(h);
	setWidth(w);
}

Rectangle::Rectangle(Rectangle& rect)
{
	setRectangle(rect);
}

Rectangle::~Rectangle()
{
	_h = 0;
	_w = 0;
}

int Rectangle::getHeight() const
{
	return _h;
}

int Rectangle::getWidth() const
{
	return _w;
}

Point& Rectangle::getPosition()
{
	return _coord;
}

const Point& Rectangle::getPosition() const
{
	return _coord;
}

void Rectangle::setHeight(int h)
{
	assert(h >= 0);
	_h = h;
}

void Rectangle::setWidth(int w)
{
	assert(w >= 0);
	_w = w;
}

void Rectangle::setRectangle(int w, int h)
{
	setHeight(h);
	setWidth(w);
}

void Rectangle::setRectangle(int x, int y, int w, int h)
{
	_coord.setX(x);
	_coord.setY(y);
	setHeight(h);
	setWidth(w);
}

void Rectangle::setRectangle(Rectangle& rect)
{
	setRectangle(rect.getPosition().getX(), rect.getPosition().getY(), rect.getHeight(), rect.getWidth());
}

bool Rectangle::operator==(Rectangle& r) const
{
	return (_h == r._h && _w == r._w);
}

bool Rectangle::operator!=(Rectangle& r) const
{
	return !(_h == r._h && _w == r._w);
}

bool Rectangle::operator<(Rectangle& r) const
{
	return perimetre() < r.perimetre();
}

bool Rectangle::operator<=(Rectangle& r) const
{
	return perimetre() <= r.perimetre();
}

bool Rectangle::operator>(Rectangle& r) const
{
	return perimetre() > r.perimetre();
}

bool Rectangle::operator>=(Rectangle& r) const
{
	return perimetre() >= r.perimetre();
}

void Rectangle::print(std::ostream& os) const
{
	os << "(" << _coord.getX() << "," << _coord.getY() << ") " << _w << " X " << _h;
}

void Rectangle::read(std::istream& is)
{
	char vide;
	int x, y, w, h;

	is >> vide >> x >> vide >> y >> vide >> w >> vide >> h;

	_coord.setX(x);
	_coord.setY(y);

	setWidth(w);
	setHeight(h);
}

void Rectangle::draw(std::ostream& os) const
{
	int xPos = _coord.getX(),
		yPos = _coord.getY();

	// ligne horizontale haut
	goToXY(xPos, yPos);
	for (int i = 0; i < _w; i++)
	{
		os << "*";
	}

	// ligne horizontale bas
	goToXY(xPos, yPos + _h - 1);
	for (int i = 0; i < _w; i++)
	{
		os << "*";
	}

	// ligne verticale gauche
	for (int i = 0; i < _h; i++)
	{
		goToXY(xPos, yPos + i);
		os << "*";
	}

	// ligne verticale droite
	for (int i = 0; i < _h; i++)
	{
		goToXY(xPos + _w - 1, yPos + i);
		os << "*";
	}
}

float Rectangle::surface() const
{
	return _h * _w;
}

int Rectangle::perimetre() const
{
	return (_w + _h) * 2;
}

std::ostream& r::operator<<(std::ostream& os, Rectangle& r)
{
	r.print(os);
	return os;
}

std::istream& r::operator>>(std::istream& is, Rectangle& r)
{
	r.read(is);
	return is;
}

void r::afficherLigne(Rectangle& r, int nbRect)
{
	int posX = r.getPosition().getX();

	for (int i = 0; i < nbRect; i++)
	{
		r.draw(cout);
		r.getPosition().setX(r.getPosition().getX() + r.getWidth());
	}

	r.getPosition().setX(posX);
}

void r::afficherTriangle(Rectangle& r, int nbRect)
{
	int posX = r.getPosition().getX(),
		posY = r.getPosition().getY();

	for (int i = 0; i < nbRect; i++)
	{
		afficherLigne(r, i + 1);

		r.getPosition().setX(posX);
		r.getPosition().setY(r.getPosition().getY() + r.getHeight());
	}

	r.getPosition().setY(posY);
}

void r::afficherGrille(Rectangle& r, int nbRect)
{
	int posX = r.getPosition().getX(),
		posY = r.getPosition().getY();

	for (int i = 0; i < nbRect; i++)
	{
		afficherLigne(r, nbRect);

		r.getPosition().setX(posX);
		r.getPosition().setY(r.getPosition().getY() + r.getHeight());
	}

	r.getPosition().setY(posY);
}

