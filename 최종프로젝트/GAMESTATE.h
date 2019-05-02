#pragma once
#include "basic.h"
#include "DAY.h"

enum STATE{LOGO, TITLE, MAIN};

class GAMESTATE
{
private:
	float logo_time;
protected:
	DAY lights;
	float light_pos;
	GLubyte * pBytes;
	BITMAPINFO * info;
	GLuint texture[10];
public:
	GAMESTATE();
	virtual void init();
	virtual int update();
	virtual void draw();
	virtual void reshape(int w, int h);
	virtual void key_down(int key);
	virtual void key_up(int key);
	virtual void spkey_down(int key);
	virtual void spkey_up(int key);
	~GAMESTATE();
};

