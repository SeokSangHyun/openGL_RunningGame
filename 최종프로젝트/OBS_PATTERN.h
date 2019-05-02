#pragma once
#include "OBSTACLE.h"

enum PAT{JUMP, JUMP12, JUMP13, JUMP23, JUMP123, ROTATE1, ARROW1,  ARROW2, ARROW3, RANDOM};

class OBS_PATTERN
{
	int curPattern;
	float loc;
	OBSTACLE obs[3];
	bool arrow_stat[3];
public:
	OBS_PATTERN();
	void init();
	void set_loc(float z);
	void reset_obs();
	void draw();
	void update(POINT_F playerLoc);
	bool collision(int currentDeg, POINT_F playerLoc);
	bool is_arrow_stop();
	~OBS_PATTERN();
};

