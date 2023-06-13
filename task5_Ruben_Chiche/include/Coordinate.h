#pragma once
#include <iostream>
#include <string>

class Coordinate {
	std::pair<double, double> _myCoordinate;

public:
	Coordinate() {}
	Coordinate(std::string coordinate);
	Coordinate(double x, double y);
	double getX() const;
	double getY() const;

	friend std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate) {
		os << "[" << coordinate.getX() << ", " << coordinate.getY() << "]";
		return os;
	}
};