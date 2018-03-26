/*
 * Structure2D.h
 *
 *  Created on: 26 бер. 2018 р.
 *      Author: atischenko
 */

#ifndef STRUCTURE2D_H_
#define STRUCTURE2D_H_

#include <vector>

class Structure2D {
	public:
		Structure2D(int x, int y);
		virtual ~Structure2D();
	protected:
		int x;
		int y;
};

class Dimension : Structure2D {
	public:
		int getWidth() {return x;};
		int getHeight() {return y;};
};

class Point : Structure2D {
	public:
		int getX() {return x;};
		int getY() {return y;};
};

class Object2D : Structure2D {
	public:
		Object2D();
		virtual ~Object2D() {
			size = nullptr;
			points.~vector();
		};
		Dimension& getSize() {return *size;};
		std::vector<Point> getPoints() {return points;};
	private:
		Dimension* size;
		std::vector<Point> points;
};

#endif /* STRUCTURE2D_H_ */
