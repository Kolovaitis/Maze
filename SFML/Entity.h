#pragma once
#include <ctime>
#include "GameObject.h"
#define ANIMATION_BACKWARD 0;
#define ANIMATION_LEFT 1;
#define ANIMATION_RIGHT 2;
#define ANIMATION_FORWARD 3;
#define STANDART_RANGE 128;
typedef struct CharacterView{
	GameObject** positions;
	float range;
	int* objCount;
} CharacterView;
class Entity: public GameObject
{
	
public:	
	float speed;	
	CharacterView characterView;
	void goForward(clock_t deltaTime);
	void goBackward(clock_t deltaTime);
	void goLeft(clock_t deltaTime);
	void goRight(clock_t deltaTime);
	void stay();
	virtual void tick(clock_t deltaTime);
	void renewFrameIndex(clock_t deltaTime);	
	virtual void endGo(int x, int y, clock_t delta_time);
	void barrierBehavior(int x, int y, GameObject* obj);
	void collisionAnalize(int x, int y);
	virtual void wallBehavior(int x, int y, GameObject* obj);
	virtual void monsterBehavior(int x, int y, GameObject* obj);
	virtual void playerBehavior(int x, int y, GameObject* obj);
	virtual void oxygenBehavior(int x, int y, GameObject* obj);
	int animationIndex;
	int frameIndex;
	int frameCount;
	clock_t timeFromLastFrame;
	float frameSpeed;	
	Entity();
	Entity(float x, float y);
	static const int WIDTH =32;
	static const int HEIGHT =32;
	
	



};

