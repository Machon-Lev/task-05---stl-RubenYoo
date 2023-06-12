#include "Coordinate.h"

class Distance {
public:
	double euclidean(Coordinate firstPoint, Coordinate secondePoint);
	double chebyshev(Coordinate firstPoint, Coordinate secondePoint);
	double manhattan(Coordinate firstPoint, Coordinate secondePoint);

};