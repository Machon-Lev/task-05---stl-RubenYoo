#include <iostream>

class Coordinate {
	std::pair<double, double> _myCoordinate;

public:
	Coordinate(double x, double y) { _myCoordinate.first = x; _myCoordinate.second = y; }
	double getX() { return _myCoordinate.first; }
	double getY() { return _myCoordinate.second; }

};