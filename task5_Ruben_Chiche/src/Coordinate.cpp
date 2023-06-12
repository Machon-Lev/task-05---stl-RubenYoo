#include "Coordinate.h"

Coordinate::Coordinate(std::string coordinate)
{

}

Coordinate::Coordinate(double x, double y)
{
	_myCoordinate.first = x;
	_myCoordinate.second = y;
}

double Coordinate::getX() const
{
	return _myCoordinate.first;
}

double Coordinate::getY() const
{
	return _myCoordinate.second;
}