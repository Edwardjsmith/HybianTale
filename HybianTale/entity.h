#pragma once
#include "textureManager.h"
#include "Vector2.h"
#include "defines.h"
#include "spacialPartition.h"
#include "Components.h"

class Entity
{
	friend class SpacialPartition;
public:
	Entity(const char* filename, float x, float y, int width, int height, int framesX, int framesY, const char* tag);
	~Entity();

	void Render(SDL_Renderer* rend);
	float GetX() { return m_position.x; } 
	float GetY() { return m_position.y; }
	void SetSpeed(float val) { m_speed = val; }
	virtual void Update(float delta);

	void MoveX(float x, bool flip);
	void MoveY(float y, bool flip);

	void SetX(float x);
	void SetY(float y);

	Vector2 GetPosition() { return m_position; }

	void KnockBack();

	float GetSpeed();
	Vector2 m_oldPosition = Vector2::m_zero;

	SpacialPartition* GetPartition();
	void SetPartition(SpacialPartition* part);

	void SetActive(bool active);
	bool IsActive();

	void SetPosition(Vector2 pos);

	int GetFrameWidth();
	int GetFrameHeight();

	float GetRight();
	float GetBottom();

	float GetAttackDistance();

	bool InputDisabled() { return m_disableInput; }

	const char* GetTag() { return m_tag; }

	Vector2 GetInitialPos() { return m_initialPos; }

	void SetInitialPos(Vector2 pos) { m_initialPos = pos; }

protected:
	float m_attackDistance = 0.0f;
	const char* m_tag;
	EntityComponent* mp_entityComponent;
private:

	SDL_Texture* m_entityTexture = nullptr;
	bool m_hasCollided = false;
	SDL_Rect m_srcRect, m_destRect; //srcRect controls which frame is displayed while dest affects pos

	bool m_flipTexture = false;

	int m_frameWidth = 0;
	int m_frameHeight = 0;

	int m_textureWidth = 0;
	int m_textureHeight = 0;

	int m_framesX;
	int m_framesY;

	Vector2 m_position;
	float m_speed = 0.0f;
	float m_delta = 0.0f;

	const int m_spriteWidth, m_spriteHeight;

	SpacialPartition* mp_currentPartition = nullptr;
	bool m_active = false;

	bool m_knockedBack = false;
	bool m_disableInput = false;

	float m_knockBackTimer = 0.0f;

	Entity* mp_next = nullptr;
	Entity* mp_prev = nullptr;

	Vector2 m_initialPos;

	EntityComponentManager* m_ECSManager;
};

