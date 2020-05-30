#pragma once
#include "textureManager.h"
#include "Vector2.h"
#include "defines.h"
#include "spacialPartition.h"
class entity
{
	friend class spacialPartition;
public:
	entity(const char* filename, float x, float y, int width, int height, int framesX, int framesY);
	~entity();

	void render(SDL_Renderer* rend);
	float getX() { return m_position.x; } 
	float getY() { return m_position.y; }
	void setSpeed(float val) { m_speed = val; }
	virtual void update(float delta);

	void moveX(float x, bool flip);
	void moveY(float y, bool flip);

	void setX(float x);
	void setY(float y);

	Vector2 getPosition() { return m_position; }

	void knockBack();

	float getSpeed();
	Vector2 m_oldPosition = zero;

	entity* next = nullptr;
	entity* prev = nullptr;

	spacialPartition* getPartition();
	void setPartition(spacialPartition* part);

	void setActive(bool active);
	bool isActive();

	void setPos(Vector2 pos);

	std::string tag;
	Vector2 zero = { 0, 0 };

	int getFrameWidth();
	int getFrameHeight();

	float getRight();
	float getBottom();

	float getAttackDistance();

	bool InputDisabled() { return disableInput; }

protected:
	enum type {player, enemy, terrain, pickup};
	type Type;
	float m_attackDistance = 0.0f;
private:

	SDL_Texture* m_entityTexture = nullptr;
	bool m_hasCollided = false;
	SDL_Rect srcRect, destRect; //srcRect controls which frame is displayed while dest affects pos

	bool m_flipTexture = false;

	int m_frameWidth = 0;
	int m_frameHeight = 0;

	int m_textureWidth = 0;
	int m_textureHeight = 0;

	int m_framesX;
	int m_framesY;

	Vector2 m_position = zero;
	float m_speed = 0.0f;
	float m_delta = 0.0f;

	const int m_spriteWidth, m_spriteHeight;

	Vector2 up = { 0, 1 };
	Vector2 right = { 1, 0 };
	Vector2 down = { 0, -1 };
	Vector2 left = { -1, 0 };


	spacialPartition* currentPartition;
	bool m_active = false;

	bool knockedBack = false;
	bool disableInput = false;

	float knockBackTimer = 0.0f;
	
};

