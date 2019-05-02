#pragma once
#include "basic.h"

enum OBS_KID{JUMP1, JUMP2, JUMP3, ROTATE, ARROW};
enum OBS_HEIGHT{JUMP1_H = 40, JUMP2_H = 80, JUMP3_H = 120, LAND_RAIDUS = 50, CHMP_SIZE = 60};
enum ARROW_STAT{YES, NO, NOTARROW};
class OBSTACLE
{
	int kind;
	float loc;
	int ypos;
	int noKillDeg;
	int KillDeg;
	int KillDegSide;
	GLubyte * pBytes;
	BITMAPINFO * info;
	GLuint texture[3];
	float obsDeg;
	bool degPlus;
	POINT_F playerLoc;
public:
	OBSTACLE();
	OBSTACLE(int kind);
	void init();
	void set_kind(int species);
	void set_loc(float pos);
	void draw();
	void update(POINT_F playerLoc);
	int get_noKillDeg();
	bool collision(int currentDeg, POINT_F playerLoc);
	int is_arrow_stop();
	int make_killDeg_side(int killDeg);
	~OBSTACLE();
};

