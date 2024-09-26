#pragma once
#include "point.h"

namespace r
{
	class Rectangle
	{
	private:
		Point _coord;
		int _h;
		int _w;

	public:
		Rectangle();
		Rectangle(int w, int h);
		Rectangle(int x, int y, int w, int h);
		Rectangle(Rectangle& rect);
		~Rectangle();

		int getHeight() const;
		int getWidth() const;
		Point& getPosition();
		const Point& getPosition() const;

		void setHeight(int h);
		void setWidth(int w);

		void setRectangle(int w, int h);
		void setRectangle(int x, int y, int w, int h);
		void setRectangle(Rectangle& rect);

		bool operator==(Rectangle& r) const;
		bool operator!=(Rectangle& r) const;
		bool operator<(Rectangle& r) const;
		bool operator<=(Rectangle& r) const;
		bool operator>(Rectangle& r) const;
		bool operator>=(Rectangle& r) const;

		friend std::ostream& operator<<(std::ostream& os, Rectangle& r);
		friend std::istream& operator>>(std::istream& is, Rectangle& r);

		friend void afficherLigne(Rectangle& r, int nbRect);
		friend void afficherTriangle(Rectangle& r, int nbRect);
		friend void afficherGrille(Rectangle& r, int nbRect);

		void print(std::ostream& os) const;
		void read(std::istream& is);
		void draw(std::ostream& os) const;

		float surface() const;
		int perimetre() const;

	};
}



