#include "TITLESTATE.h"



TITLESTATE::TITLESTATE()
{
}


void TITLESTATE::init() {
	frame = 0;
	stat = TITLE;

	glGenTextures(10, texture);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("texture/runanimation/run1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("texture/runanimation/run2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	pBytes = LoadDIBitmap("texture/runanimation/run3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	pBytes = LoadDIBitmap("texture/runanimation/run4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	pBytes = LoadDIBitmap("texture/runanimation/run5.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	pBytes = LoadDIBitmap("texture/runanimation/run6.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	pBytes = LoadDIBitmap("texture/runanimation/run7.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
	pBytes = LoadDIBitmap("texture/runanimation/run8.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	pBytes = LoadDIBitmap("texture/runanimation/run9.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[9]);
	pBytes = LoadDIBitmap("texture/runanimation/run10.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 320, 320, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


int TITLESTATE::update() {
	frame += 0.5;
	if (10 <= frame)
		frame = 0;
	return stat;
}


void TITLESTATE::draw() {
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, texture[int(frame)]);
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
	glEnable(GL_LIGHTING);
}


void TITLESTATE::reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -400.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
}


void TITLESTATE::key_down(int key) {
	if (key == ESC) {
		exit(-1);
	}
	else if (key == ' ') {
		stat = MAIN;
	}
}


void TITLESTATE::key_up(int key) {

}


void TITLESTATE::spkey_down(int key) {

}


void TITLESTATE::spkey_up(int key) {

}


TITLESTATE::~TITLESTATE()
{
}
