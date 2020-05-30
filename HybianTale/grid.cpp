#include "grid.h"
#include "entity.h"
#include <math.h>

float grid::distance(entity * entA, entity * entB)
{
	float distX = (entB->getPosition().x - entA->getPosition().x) *  (entB->getPosition().x - entA->getPosition().x);
	float distY = (entB->getPosition().y - entA->getPosition().y) *  (entB->getPosition().y - entA->getPosition().y);

	return sqrt(distX + distY);
}
