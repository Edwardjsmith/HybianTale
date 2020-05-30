#include "physics.h"
physics* physics::inst = nullptr;


physics::physics()
{
}


physics::~physics()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

physics * physics::instance()
{
	if (inst == nullptr)
	{
		inst = new physics();
	}

	return inst;
}

bool physics::collidedLeft(entity * entA, entity * entB)
{
	return (entA->getRight() - entB->getX()) < (entB->getRight() - entA->getX()) &&
		(entA->getRight() - entB->getX()) < (entA->getBottom() - entB->getY()) &&
		(entA->getRight() - entB->getX()) < (entB->getBottom() - entA->getY());
}

bool physics::collidedRight(entity * entA, entity * entB)
{
	return (entB->getRight() - entA->getX()) < (entA->getRight() - entB->getX()) &&
		(entB->getRight() - entA->getX()) < (entA->getBottom() - entB->getY()) &&
		(entB->getRight() - entA->getX()) < (entB->getBottom() - entA->getY());
}

bool physics::collidedTop(entity * entA, entity * entB)
{
	return (entA->getBottom() - entB->getY()) < (entB->getBottom() - entA->getY()) &&
		(entA->getBottom() - entB->getY()) < (entA->getRight() - entB->getX()) &&
		(entA->getBottom() - entB->getY()) < (entB->getRight() - entA->getX());

}

bool physics::collidedBottom(entity * entA, entity * entB)
{
	return (entB->getBottom() - entA->getY()) < (entA->getBottom() - entB->getY()) &&
		(entB->getBottom() - entA->getY()) < (entA->getRight() - entB->getX()) &&
		(entB->getBottom() - entA->getY()) < (entB->getRight() - entA->getX());

}

bool physics::collision(entity * a, entity * b)
{
		if (a->getX() + a->getFrameWidth() < b->getX() || a->getX() > b->getX() + b->getFrameWidth() ||
			a->getY() + a->getFrameHeight() < b->getY() || a->getY() > b->getY() + b->getFrameHeight())
		{
			return false;
		}

		return true;
	
}
