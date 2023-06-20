#pragma once
#include <iostream>
#include <string>

class Coordinate {
	// private pair
	std::pair<double, double> _myCoordinate;
public:
	// constructors
	Coordinate() {}
	Coordinate(double x, double y);

	// getter
	double getX() const;
	double getY() const;
};