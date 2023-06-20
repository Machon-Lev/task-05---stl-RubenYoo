#pragma once
#include "Coordinate.h"

class Distance {
public:
	// static methods
	static double euclidean(Coordinate firstPoint, Coordinate secondePoint);
	static double chebyshev(Coordinate firstPoint, Coordinate secondePoint);
	static double manhattan(Coordinate firstPoint, Coordinate secondePoint);
};