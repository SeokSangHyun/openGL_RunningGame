#pragma once
#include "basic.h"

class DAY
{
	GLfloat diffuse[4];
	GLfloat specular[4] ;
	GLfloat ambient[4] ;
	GLfloat light_pos[4];
	float light_deg ;
	float change_deg;
	float currentLoc;
	GLubyte * pBytes;
	BITMAPINFO * info;
	GLuint texture[2];
public:
	DAY();
	void change_light_deg(float deg);
	void set_shiny();
	void set_light();
	void update(float currentLoc);
	void draw();
	void init();
	~DAY();
};

