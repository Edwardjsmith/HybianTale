#pragma once
#include "entity.h"
#include <iostream>

class command
{
public:

	virtual void execute(entity& Entity) = 0;
	virtual ~command() {};
};

class LeftCommand : public command
{
public:
	virtual void execute(entity& Entity)
	{
		Entity.moveX(-Entity.getSpeed(), Entity.getPartition(), false);
	}
};

class UpCommand : public command
{
public:
	virtual void execute(entity& Entity)
	{
		Entity.moveY(-Entity.getSpeed(), Entity.getPartition(), true);
	}
};

class RightCommand : public command
{
public:
	virtual void execute(entity& Entity)
	{
		Entity.moveX(Entity.getSpeed(), Entity.getPartition(), true);
	}
};

class DownCommand : public command
{
public:
	virtual void execute(entity& Entity)
	{
		Entity.moveY(Entity.getSpeed(), Entity.getPartition(), false);
	}
};

