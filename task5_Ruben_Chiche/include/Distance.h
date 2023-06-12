#include "Coordinate.h"

class Distance {
public:
	double euclidean(Coordinate firstPoint, Coordinate secondePoint) const;
	double chebyshev(Coordinate firstPoint, Coordinate secondePoint) const;
	double manhattan(Coordinate firstPoint, Coordinate secondePoint) const;

};