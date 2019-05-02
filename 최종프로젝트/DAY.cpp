#include "DAY.h"



DAY::DAY()
{
	diffuse[0] = 1.0; diffuse[1] = 1.0; diffuse[2] = 1.0; diffuse[3] = 1.0;
	specular[0] = 1.0; specular[1] = 1.0; specular[2] = 1.0; specular[3] = 1.0;
	ambient[0] = 0.2; ambient[1] = 0.2; ambient[2] = 0.2; ambient[3] = 1.0;
	light_pos[0] = 0; light_pos[1] = 900; light_pos[2] = 200; light_pos[3] = 1.0;
	light_deg = 0.0;	
	change_deg = 2.5;
}


void DAY::change_light_deg(float deg) {
	change_deg = deg;
}


void DAY::set_shiny() {
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
}


void DAY::set_light() {
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glEnable(GL_LIGHT0);
}


void DAY::update(float currentLoc) {
	this->currentLoc = currentLoc;
	light_deg += change_deg;
	if (360 < light_deg)
		light_deg -= 360;
	light_pos[0] = 900 * sin(degree_to_radian(light_deg));
	light_pos[1] = 900 * cos(degree_to_radian(light_deg));
	light_pos[2] = currentLoc + 500;
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}


void DAY::draw() {
	glEnable(GL_TEXTURE_2D);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glColor3ub(255, 255, 255);
	//draw sun
	glPushMatrix();
	{
		glTranslatef(500 * sin(degree_to_radian(light_deg+ 100)), 500 * cos(degree_to_radian(light_deg+ 100)), currentLoc+500);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(50, 50, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(50, -50, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-50, -50, 0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-50, 50, 0);
		}
		glEnd();
	}
	glPopMatrix();
	//draw moon
	glPushMatrix();
	{
		glTranslatef(500 * sin(degree_to_radian(light_deg + 280)), 500 * cos(degree_to_radian(light_deg + 280)), currentLoc + 500);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(50, 50, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(50, -50, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-50, -50, 0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-50, 50, 0);
		}
		glEnd();
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void DAY::init() {
	glGenTextures(8, texture);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("texture/sun.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("texture/moon.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}


DAY::~DAY()
{
}
