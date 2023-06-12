#include <iostream>
#include <string>

class Coordinate {
	std::pair<double, double> _myCoordinate;

public:
	Coordinate(std::string coordinate);
	Coordinate(double x, double y);
	double getX() const;
	double getY() const;
};