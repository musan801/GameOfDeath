#pragma once
#include <iostream>
using namespace std;
class Point {

	int X;
	int Y;
public:
	
	Point();
	Point(const Point& p2);
	Point(int a, int b);
	int getX() ;
	void setX(int X);
	int getY() ;
	void setY(int Y);
	bool operator ==(Point p)
	{
		if (X == p.X and Y == p.Y)
			return true;
		else
			return false;
	}
	bool operator !=(Point p) {
		if (X == p.X and Y == p.Y)
			return false;
		else
			return true;
	}

};
