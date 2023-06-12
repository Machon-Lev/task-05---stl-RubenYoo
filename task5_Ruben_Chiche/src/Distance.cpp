#include "Distance.h"
#include <cmath>

double Distance::euclidean(Coordinate firstPoint, Coordinate secondePoint)
{
	
	return sqrt(pow(firstPoint.getX() - secondePoint.getX(), 2) + pow(firstPoint.getY() - secondePoint.getY(), 2));
}

double Distance::chebyshev(Coordinate firstPoint, Coordinate secondePoint)
{
	return std::max(abs(firstPoint.getX() - secondePoint.getX()), abs(firstPoint.getY() - secondePoint.getY()));
}

double Distance::manhattan(Coordinate firstPoint, Coordinate secondePoint)
{
	return abs(firstPoint.getX() - secondePoint.getX()) + abs(firstPoint.getY() - secondePoint.getY());
}
