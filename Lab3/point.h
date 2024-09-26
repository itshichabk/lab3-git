#pragma once
#include <fstream>


class Point
{
private:
	int _x, _y;
	int _color;

public:
	Point();
	Point(int x, int y);
	Point(const Point& p);
	~Point();

	Point& operator=(const Point& p);
	bool operator==(const Point& p) const;
	bool operator!=(const Point& p) const;
	Point operator+(const Point& p);
	Point operator-(const Point& p);

	void print(std::ostream& os);
	void read(std::istream& is);
	void draw(std::ostream& os) const;

	int getX() const;
	int getY() const;
	int getColor() const;
	Point getPoint() const;

	void setX(int x);
	void setY(int y);
	void setColor(int color);
	void setPoint(Point& p);
	void setPosition(int x, int y);

	friend float distance(const Point& pA, const Point& pB);

	//void setPoint(int x, int y, int color);
};

void goToXY(int xPos, int yPos);

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);
