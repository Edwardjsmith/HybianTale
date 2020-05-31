#pragma once
#include "entity.h"
#include <iostream>

class Command
{
public:

	virtual void Execute(Entity& Entity) = 0;
	virtual ~Command() {};
};

class LeftCommand : public Command
{
public:
	virtual void Execute(Entity& Entity)
	{
		Entity.MoveX(-Entity.GetSpeed(), false);
	}
};

class UpCommand : public Command
{
public:
	virtual void Execute(Entity& Entity)
	{
		Entity.MoveY(-Entity.GetSpeed(), true);
	}
};

class RightCommand : public Command
{
public:
	virtual void Execute(Entity& Entity)
	{
		Entity.MoveX(Entity.GetSpeed(), true);
	}
};

class DownCommand : public Command
{
public:
	virtual void Execute(Entity& Entity)
	{
		Entity.MoveY(Entity.GetSpeed(), false);
	}
};

