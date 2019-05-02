#include "GAMESTATE.h"



GAMESTATE::GAMESTATE()
{
	logo_time = 0.0;
}


void GAMESTATE::init() {
	lights.change_light_deg(30.0);
	lights.set_light();
	light_pos = -500;
	glGenTextures(1, texture);
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("texture/kpu_credit.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 800, 800, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


int GAMESTATE::update() {
	lights.update(light_pos); 
	light_pos += 20;
	logo_time += 0.05;
	if (3.0 < logo_time)
		return TITLE;
	return LOGO;
}


void GAMESTATE::draw() {
	lights.set_shiny();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-400, 400, 0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-400, -400, 0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(400, -400, 0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(400, 400, 0);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void GAMESTATE::reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -400.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
}


void GAMESTATE::key_down(int key){
	if (key == ESC) {
		exit(-1);
	}
}


void GAMESTATE::key_up(int key) {

}


void GAMESTATE::spkey_down(int key) {
	
}


void GAMESTATE::spkey_up(int key) {

}


GAMESTATE::~GAMESTATE()
{
}
