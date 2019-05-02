#include "OBS_PATTERN.h"



OBS_PATTERN::OBS_PATTERN()
{
}


void OBS_PATTERN::init() {
	for (int i = 0; i < 3; i++)
		obs[i].init();
}


void OBS_PATTERN::set_loc(float z) {
	loc = z;
}


void OBS_PATTERN::reset_obs() {
	for (int i = 0; i<3; i++)
		arrow_stat[i] = false;

	curPattern = rand()%10;
	switch (curPattern) {
	case JUMP:
		obs[0].set_kind(rand() % 3);
		obs[0].set_loc(loc);
		break;
	case JUMP12:
		obs[0].set_kind(JUMP1);
		obs[1].set_kind(JUMP2);
		obs[0].set_loc(loc);
		loc += 40;
		obs[1].set_loc(loc);
		break;
	case JUMP13:
		obs[0].set_kind(JUMP1);
		obs[1].set_kind(JUMP3);
		obs[0].set_loc(loc);
		loc += 40;
		obs[1].set_loc(loc);
		break;
	case JUMP23:
		obs[0].set_kind(JUMP2);
		obs[1].set_kind(JUMP3);
		obs[0].set_loc(loc);
		loc += 40;
		obs[1].set_loc(loc);
		break;
	case JUMP123:
		obs[0].set_kind(JUMP1);
		obs[1].set_kind(JUMP2);
		obs[2].set_kind(JUMP3);
		obs[0].set_loc(loc);
		loc += 40;
		obs[1].set_loc(loc);
		loc += 40;
		obs[2].set_loc(loc);
		break;
	case ROTATE1:
		obs[0].set_kind(ROTATE);
		obs[0].set_loc(loc);
		break;
	case ARROW1:
		obs[0].set_kind(ARROW);
		obs[0].set_loc(loc);
		break;
	case ARROW2:
		obs[0].set_kind(ARROW);
		obs[0].set_loc(loc);
		obs[1].set_kind(ARROW);
		loc += 200;
		obs[1].set_loc(loc);
		break;
	case ARROW3:
		obs[0].set_kind(ARROW);
		obs[0].set_loc(loc);
		obs[1].set_kind(ARROW);
		loc += 200;
		obs[1].set_loc(loc);
		obs[2].set_kind(ARROW);
		loc += 200;
		obs[2].set_loc(loc);
		break;
	case RANDOM:
		for (int i = 0; i < 3; i++) {
			if (rand() % 2 == JUMP) {
				obs[i].set_kind(rand() % 3);
			}
			else {
				obs[i].set_kind(ARROW);
			}
			obs[i].set_loc(loc);
			loc += 40;
		}
		break;
	}
}


void OBS_PATTERN::draw() {
	//장애물 한개
	if (curPattern == JUMP || curPattern == ROTATE1 || curPattern == ARROW1) {
		obs[0].draw();
	}
	//장애물 두개
	else if (curPattern == JUMP12 || curPattern == JUMP13 || curPattern == JUMP23 || curPattern == ARROW2) {
		obs[1].draw();
		obs[0].draw();
	}
	//장애물 세개
	else {
		obs[2].draw();
		obs[1].draw();
		obs[0].draw();
	}
}


void OBS_PATTERN::update(POINT_F playerLoc) {
	for (int i = 0; i < 3; i++) {
		obs[i].update(playerLoc);
	}
}


bool OBS_PATTERN::collision(int currentDeg, POINT_F playerLoc) {
	//장애물 한개
	if (curPattern == JUMP || curPattern == ROTATE1 || curPattern == ARROW1) {
		return obs[0].collision(currentDeg, playerLoc);
	}
	//장애물 두개
	else if (curPattern == JUMP12 || curPattern == JUMP13 || curPattern == JUMP23 || curPattern == ARROW2) {
		for (int i = 0; i < 2; i++) {
			if (obs[i].collision(currentDeg, playerLoc))
				return true;
		}
	}
	//장애물 세개
	else {
		for (int i = 0; i < 3; i++) {
			if (obs[i].collision(currentDeg, playerLoc))
				return true;
		}
	}
	return false;
}


bool OBS_PATTERN::is_arrow_stop() {
	//장애물 한개
	if (curPattern == ARROW1) {
		if (arrow_stat[0] == false && obs[0].is_arrow_stop() == YES) {
			arrow_stat[0] = true;
			PlaySound(TEXT("sounds/Boom.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT | SND_NOWAIT);
			return true;
		}
		else if (arrow_stat[0] == false && obs[0].is_arrow_stop() == NO) {
			return false;
		}
	}
	//장애물 두개
	else if (curPattern == ARROW2) {
		for (int i = 0; i < 2; i++) {
			if (0 < i) {
				if (arrow_stat[i - 1] == false)
					return false;
			}
			if (arrow_stat[i] == false && obs[i].is_arrow_stop() == YES) {
				arrow_stat[i] = true;
				PlaySound(TEXT("sounds/Boom.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT | SND_NOWAIT);
				return true;
			}
			else if (arrow_stat[i] == false && obs[i].is_arrow_stop() == NO) {
				return false;
			}
		}
	}
	//장애물 세개
	else if (curPattern == ARROW3 || curPattern == RANDOM) {
		for (int i = 0; i < 3; i++) {
			if (0 < i) {
				if (arrow_stat[i - 1] == false)
					return false;
			}
			if (arrow_stat[i] == false && obs[i].is_arrow_stop() == YES) {
				arrow_stat[i] = true;
				PlaySound(TEXT("sounds/Boom.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT | SND_NOWAIT);
				return true;
			}
			else if (arrow_stat[i] == false && obs[i].is_arrow_stop() == NO) {
				return false;
			}
			else if (arrow_stat[i] == false && obs[0].is_arrow_stop() == NOTARROW) {
				arrow_stat[i] = true;
				return false;
			}
		}
	}
	return false;
}

OBS_PATTERN::~OBS_PATTERN()
{
}
