#pragma once
#include "GAMESTATE.h"

class TITLESTATE : public GAMESTATE
{
	float frame;
	int stat;
public:
	TITLESTATE();
	virtual void init();
	virtual int update();
	virtual void draw();
	virtual void reshape(int w, int h);
	virtual void key_down(int key);
	virtual void key_up(int key);
	virtual void spkey_down(int key);
	virtual void spkey_up(int key);
	~TITLESTATE();
};

