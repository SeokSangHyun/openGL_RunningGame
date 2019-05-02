#pragma once
#include "basic.h"
#include "OBS_PATTERN.h"
#include "Character.h"
#include "DAY.h"
#include "GAMESTATE.h"

enum VIEW { FPV = 0, TPV, CSVL, CSVR, CJVU, CJVD };
//Cam X View X

class MAINSTATE : public GAMESTATE
{
private:
	int current_view;
	basic base ;
	OBS_PATTERN obstacles[6];
	Character chmp;
	DAY dayCycle;
	int stat;

	bool Arrow;
	int ct_ShakeMotion;
	int ShakeRadian[3];
	/*/////////////////////////*/

	GLdouble camT;		//좌,우 최종 변화량
	GLdouble camJumpT;	//점프 최종 변화량
	GLdouble camT_Sidedef;	//	변화량 되는 최댓값
	GLdouble camT_Junmpdef;	//	변화량
public:
	MAINSTATE();
	void CameraLook();
	void CameraTimer();
	void JudgeShakeMotion();

	virtual void init();
	virtual int update();
	virtual void draw();
	virtual void reshape(int w, int h);
	virtual void key_down(int key);
	virtual void key_up(int key);
	virtual void spkey_down(int key);
	virtual void spkey_up(int key);
	~MAINSTATE();
};

