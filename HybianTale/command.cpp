#include "command.h"
void LeftCommand::Execute(TransformComponent* transform)
{
	transform->m_velocity.x = -1;
}

void UpCommand::Execute(TransformComponent* transform)
{
	transform->m_velocity.y = -1;
}

void RightCommand::Execute(TransformComponent* transform)
{
	transform->m_velocity.x = 1;
}

void DownCommand::Execute(TransformComponent* transform)
{
	transform->m_velocity.y = 1;
}
