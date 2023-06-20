#include "Distance.h"
#include <cmath>

// calculate euclidean distance
double Distance::euclidean(Coordinate firstPoint, Coordinate secondPoint)
{
	return sqrt(pow(firstPoint.getX() - secondPoint.getX(), 2) + pow(firstPoint.getY() - secondPoint.getY(), 2));
}

// calculate chebyshev distance
double Distance::chebyshev(Coordinate firstPoint, Coordinate secondPoint)
{
	return std::max(abs(firstPoint.getX() - secondPoint.getX()), abs(firstPoint.getY() - secondPoint.getY()));
}

// calculate manhattan distance
double Distance::manhattan(Coordinate firstPoint, Coordinate secondPoint)
{
	return abs(firstPoint.getX() - secondPoint.getX()) + abs(firstPoint.getY() - secondPoint.getY());
}
