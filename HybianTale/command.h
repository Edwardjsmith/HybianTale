#pragma once
#include "Components.h"


class Command
{
public:

	virtual void Execute(TransformComponent* transform) = 0;
	virtual ~Command() {};
};

class LeftCommand : public Command
{
public:
	virtual void Execute(TransformComponent* transform);
};

class UpCommand : public Command
{
public:
	virtual void Execute(TransformComponent* transform);
};

class RightCommand : public Command
{
public:
	virtual void Execute(TransformComponent* transform);
};

class DownCommand : public Command
{
public:
	virtual void Execute(TransformComponent* transform);
};

