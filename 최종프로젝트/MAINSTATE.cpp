#include "MAINSTATE.h"



MAINSTATE::MAINSTATE()
{
	current_view = TPV;
	camT = 0.0f;
	camJumpT = 0.0f;
	camT_Sidedef = 5.0f;
	camT_Junmpdef = 6.0f;
}

void MAINSTATE::CameraTimer()
{
	if (current_view == CSVL) {
		camT -= 1.0f;

		if (camT <= 0.0f) {
			current_view = TPV;
			camT = 0.0f;
		}
	}

	if (current_view == CSVR) {
		camT -= 1.0f;

		if (camT <= 0.0f) {
			current_view = VIEW::TPV;
			camT = 0.0f;
		}
	}


	if (current_view == CJVU) {
		camJumpT += camT_Junmpdef;

		if (camJumpT >= 60.0f) {
			current_view = VIEW::CJVD;
		}
	}
	else if (current_view == CJVD) {
		camJumpT -= camT_Junmpdef;

		if (camJumpT <= 0.0f) {
			current_view = VIEW::TPV;
			camJumpT = 0.0f;
		}
	}
	////////

}



void MAINSTATE::JudgeShakeMotion() {

	if (Arrow == true) {
		if (0 < ct_ShakeMotion && ct_ShakeMotion <= 5) {
			ShakeRadian[0] = rand() % 80 - 40;
			ShakeRadian[1] = rand() % 80 - 40;
			ShakeRadian[2] = rand() % 50 - 25;
		}
		else if (5 < ct_ShakeMotion) {
			ct_ShakeMotion = 0;
			ShakeRadian[0] = 0;
			ShakeRadian[1] = 0;
			ShakeRadian[2] = 0;
			Arrow = false;
		}

		ct_ShakeMotion++;
	}
}





void MAINSTATE::CameraLook() {

	//¿·À¸·Î
	if (current_view == CSVL) {
		gluLookAt(
			camT, chmp.GetPt().y + 77, chmp.GetPt().z,			// EYE
			0, chmp.GetPt().y - 277, chmp.GetPt().z + 1400,			//AT
			0, 1, 0		//UP
		);
	}
	else if (current_view == CSVR) {
		gluLookAt(
			-camT, chmp.GetPt().y + 77, chmp.GetPt().z,			// EYE
			0, chmp.GetPt().y - 277, chmp.GetPt().z + 1400,			//AT
			0, 1, 0		//UP
		);
	}
	//Á¡ÇÁ
	else if (current_view == CJVU || current_view == CJVD) {
		glTranslatef(0.0, -camJumpT, camJumpT*0.5);
		gluLookAt(
			0, chmp.GetPt().y + 77, chmp.GetPt().z,			// EYE
			0, chmp.GetPt().y - 277, chmp.GetPt().z + 1400,			//AT
			0, 1, 0		//UP
		);
	}
	/////////////////
	else if (current_view == TPV) {
		gluLookAt(
			ShakeRadian[0], chmp.GetPt().y + 77 + ShakeRadian[1], chmp.GetPt().z + ShakeRadian[2],			// EYE
			0, chmp.GetPt().y - 277, chmp.GetPt().z + 1400,			//AT
			0, 1, 0		//UP
		);
	}
	else if (current_view == FPV) {
		gluLookAt(
			ShakeRadian[0] * 0.5, chmp.GetPt().y + 77 + ShakeRadian[1] * 0.5, chmp.GetPt().z + ShakeRadian[2] * 0.5,		// EYE
			0, chmp.GetPt().y + 77, chmp.GetPt().z + 1400,			//AT
			0, 1, 0		//UP
		);
	}
}



void MAINSTATE::init() {
	stat = MAIN;
	base.init();
	dayCycle.init();
	dayCycle.set_light();
	//set obstacles
	for (int i = 0; i < 6; i++) {
		obstacles[i].set_loc(1300 * (i + 1));
		obstacles[i].reset_obs();
		obstacles[i].init();
	}
	chmp.init();

	Arrow = false;
	ct_ShakeMotion = 0;

	ShakeRadian[0] = 0;
	ShakeRadian[1] = 0;
	ShakeRadian[2] = 0;
}


int MAINSTATE::update() { 
	base.update(chmp.GetPt().z);
	chmp.timer();
	CameraTimer();
	JudgeShakeMotion();

	if ( chmp.GetPt().z < 40) {
		//set obstacles
		for (int i = 0; i < 6; i++) {
			obstacles[i].set_loc(1300 * (i + 1));
			obstacles[i].reset_obs();
		}
	}
	dayCycle.update(chmp.GetPt().z);
	for (int i = 0; i < 6; i++) {
		obstacles[i].update(chmp.GetPt());
		if ( chmp.is_alive() && obstacles[i].collision(base.get_degree_state(), chmp.GetPt()) && 500 < chmp.GetPt().z) {
			chmp.make_char_die();
		}
		if (obstacles[i].is_arrow_stop()) {
			if (Arrow == false)
				Arrow = true;
		}
	}
	if (stat == TITLE)
		return TITLE;
	return MAIN;
}


void MAINSTATE::draw() {
	glLoadIdentity();
	CameraLook();

	
	
	//draw sun
	dayCycle.set_shiny();
	dayCycle.draw();
	glPushMatrix();
	{
		base.apply();

		base.draw_way();

		for (int i = 5; 0 <= i; i--) {
			obstacles[i].draw();
		}
	}
	glPopMatrix();

	glPushMatrix();
	{
		chmp.draw();
	}
	glPopMatrix();
}


void MAINSTATE::reshape(int w, int h) {
	if (current_view == TPV) {
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, w / h, 1.0, 1400.0);
		glTranslatef(0.0, -50.0, -400);
		glMatrixMode(GL_MODELVIEW);
	}
	else if (current_view == FPV) {
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, w / h, 1.0, 1400.0);
		glTranslatef(0.0, 0.0, -32);
		glMatrixMode(GL_MODELVIEW);
	}
}


void MAINSTATE::key_down(int key) {
	if (key == ESC) {
		stat = TITLE;
	}
	else if (key == 'f' || key == 'F') {
		current_view = FPV;
		reshape(800, 800);
	}
	else if (key == 't' || key == 'T') {
		current_view = TPV;
		reshape(800, 800);
	}
	else if (key == 'a') {
		chmp.SetPt(POINT_F(chmp.GetPt().x, chmp.GetPt().y, chmp.GetPt().z + 40));
	}
	else if (key == 's') {
		chmp.SetPt(POINT_F(chmp.GetPt().x, chmp.GetPt().y, chmp.GetPt().z - 40));
	}
	else {
		if (key == ' ')
			if (current_view == TPV)
				current_view = CJVU;
		chmp.KeyBoard(key);
	}
}


void MAINSTATE::key_up(int key) {

}


void MAINSTATE::spkey_down(int key) {
	base.spkey_down(key);

	if (key == GLUT_KEY_LEFT) {
		if (current_view == TPV) {
			camT = camT_Sidedef;
			current_view = CSVL;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		if (current_view == TPV) {
			camT = camT_Sidedef;
			current_view = CSVR;
		}
	}
}


void MAINSTATE::spkey_up(int key) {

}


MAINSTATE::~MAINSTATE()
{
}
