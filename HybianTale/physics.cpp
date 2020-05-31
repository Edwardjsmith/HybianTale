#include "physics.h"
Physics* Physics::inst = nullptr;


Physics::Physics()
{
}


Physics::~Physics()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

Physics * Physics::instance()
{
	if (inst == nullptr)
	{
		inst = new Physics();
	}

	return inst;
}

bool Physics::collidedLeft(Entity * entA, Entity * entB)
{
	return (entA->GetRight() - entB->GetX()) < (entB->GetRight() - entA->GetX()) &&
		(entA->GetRight() - entB->GetX()) < (entA->GetBottom() - entB->GetY()) &&
		(entA->GetRight() - entB->GetX()) < (entB->GetBottom() - entA->GetY());
}

bool Physics::collidedRight(Entity * entA, Entity * entB)
{
	return (entB->GetRight() - entA->GetX()) < (entA->GetRight() - entB->GetX()) &&
		(entB->GetRight() - entA->GetX()) < (entA->GetBottom() - entB->GetY()) &&
		(entB->GetRight() - entA->GetX()) < (entB->GetBottom() - entA->GetY());
}

bool Physics::collidedTop(Entity * entA, Entity * entB)
{
	return (entA->GetBottom() - entB->GetY()) < (entB->GetBottom() - entA->GetY()) &&
		(entA->GetBottom() - entB->GetY()) < (entA->GetRight() - entB->GetX()) &&
		(entA->GetBottom() - entB->GetY()) < (entB->GetRight() - entA->GetX());

}

bool Physics::collidedBottom(Entity * entA, Entity * entB)
{
	return (entB->GetBottom() - entA->GetY()) < (entA->GetBottom() - entB->GetY()) &&
		(entB->GetBottom() - entA->GetY()) < (entA->GetRight() - entB->GetX()) &&
		(entB->GetBottom() - entA->GetY()) < (entB->GetRight() - entA->GetX());

}

bool Physics::collision(Entity * a, Entity * b)
{
		if (a->GetX() + a->GetFrameWidth() < b->GetX() || a->GetX() > b->GetX() + b->GetFrameWidth() ||
			a->GetY() + a->GetFrameHeight() < b->GetY() || a->GetY() > b->GetY() + b->GetFrameHeight())
		{
			return false;
		}

		return true;
	
}
