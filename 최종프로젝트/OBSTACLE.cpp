#include "OBSTACLE.h"



OBSTACLE::OBSTACLE()
{
	kind = JUMP1;
	noKillDeg = NONE;
}


void OBSTACLE::init() {
	obsDeg = rand() % 360;
	degPlus = rand() % 2;

	glGenTextures(3, texture);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("texture/stoneWall.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("texture/door.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	pBytes = LoadDIBitmap("texture/roof.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}


OBSTACLE::OBSTACLE(int obsKind) {
	kind = obsKind;
	if (kind == ROTATE) {
		noKillDeg = rand() % 8 + 1;
	}
	else if (kind == ARROW) {
		ypos = 1200;
		KillDeg = rand() % 8 + 1;
		KillDegSide = make_killDeg_side(KillDeg);
	}
	else {
		noKillDeg = NONE;
	}
}


void OBSTACLE::set_kind(int species) {
	kind = species;
	if (kind == ROTATE) {
		noKillDeg =  rand()%8 + 1;
	}
	else if (kind == ARROW) {
		ypos = 1200;
		KillDeg = rand() % 8 + 1;
		KillDegSide = make_killDeg_side(KillDeg);
	}
	else {
		noKillDeg = NONE;
	}
}


void OBSTACLE::set_loc(float pos) {
	loc = pos;
}


void OBSTACLE::draw() {
	if (playerLoc.z + 1300 < loc || loc < playerLoc.z - 800)
		return;
	if (degPlus) {
		obsDeg += 20;
		if (360 < obsDeg)
			obsDeg -= 360;
	}
	else {
		obsDeg -= 20;
		if (obsDeg < 0)
			obsDeg += 360;
	}
	
	float deg ;
	glDisable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	{
		glTranslatef(0, 0, loc);
		switch (kind) {
		case JUMP1:
			deg = 0;
			for (int i = 0; i < 8; i++) {
				glPushMatrix();
				{
					glColor4ub(116, 211, 109, 255);
					glRotatef(deg, 0, 0, 1);
					glTranslatef(-30, 85, 0);
					glRotatef(obsDeg, 1, 0, 0);
					for (int i = 0; i < 8; i++) {
						glPushMatrix();
						{
							glScalef(5, rand()%30+10, rand() %30 + 10);
							glutSolidCube(1);
						}
						glPopMatrix();
						glTranslatef(10, 0, 0);
					}
				}
				deg -= 45;
				glPopMatrix();
			}
			glColor4ub(116, 211, 109, 130);
			glScalef(1, 1, 0.1);
			glutSolidTorus(40, LAND_RAIDUS + JUMP1_H, 24, 24);
			break;
		case JUMP2:
			deg = 0;
			for (int i = 0; i < 8; i++) {
				glPushMatrix();
				{
					glColor4ub(250, 237, 125, 255);
					glRotatef(deg, 0, 0, 1);
					glTranslatef(-50, 125, 0);
					glRotatef(obsDeg, 1, 0, 0);
					for (int i = 0; i < 12; i++) {
						glPushMatrix();
						{
							glScalef(5, rand() % 30 + 10, rand() % 30 + 10);
							glutSolidCube(1);
						}
						glPopMatrix();
						glTranslatef(10, 0, 0);
					}
				}
				deg -= 45;
				glPopMatrix();
			}
			glColor4ub(250, 237, 125, 130);
			glScalef(1, 1, 0.1);
			glutSolidTorus(40, LAND_RAIDUS + JUMP2_H, 24, 24);
			break;
		case JUMP3:
			deg = 0;
			for (int i = 0; i < 8; i++) {
				glPushMatrix();
				{
					glColor4ub(255, 90, 90, 255);
					glRotatef(deg, 0, 0, 1);
					glTranslatef(-70, 165, 0);
					glRotatef(obsDeg, 1, 0, 0);
					for (int i = 0; i < 16; i++) {
						glPushMatrix();
						{
							glScalef(5, rand() % 30 + 10, rand() % 30 + 10);
							glutSolidCube(1);
						}
						glPopMatrix();
						glTranslatef(10, 0, 0);
					}
				}
				deg -= 45;
				glPopMatrix();
			}
			glColor4ub(255, 90, 90, 130);
			glScalef(1, 1, 0.1);
			glutSolidTorus(40, LAND_RAIDUS + JUMP3_H, 24, 24);
			break;
		case ROTATE:
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glRotatef(45 * (noKillDeg - 1), 0, 0, 1);
			//draw wall
			glPushMatrix();
			{
				glScalef(1, 1, 0.1);
				glColor4ub(210, 210, 210, 130);
				glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
				glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
				glBindTexture(GL_TEXTURE_2D, texture[0]);
				glScalef(450, 450, 30);
				glutSolidCube(1);
			}
			glPopMatrix();
			//draw door
			glPushMatrix();
			{
				glColor4ub(210, 210, 90, 130);
				glBindTexture(GL_TEXTURE_2D, texture[1]);
				glTranslatef(0, 100, 0);
				glScalef(90, 145, 40);

				glutSolidCube(1);
			}
			glPopMatrix();

			glDisable(GL_TEXTURE_GEN_S);
			glDisable(GL_TEXTURE_GEN_T);

			deg = 0;
			for (int i = 0; i < 8; i++) {
				glBindTexture(GL_TEXTURE_2D, texture[2]);
				glPushMatrix();
				{
					glColor4ub(90, 90, 210, 230);
					glRotatef(deg, 0, 0, 1);
					glBegin(GL_QUADS); {
						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(135, 320, -20);
						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(135, 190, -20);
						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(-135, 190, -20);
						glTexCoord2f(1.0f, 1.0f);
						glVertex3f(-135, 320, -20);
					}
					glEnd();
				}
				deg -= 45;
				glPopMatrix();
			}

			glDisable(GL_TEXTURE_2D);
			break;
		case ARROW:
			glRotatef(45 * (KillDeg - 1), 0, 0, 1);
			glTranslatef(0, ypos, 0);
			//body
			glPushMatrix();
			{
				glColor4ub(99, 84, 0, 255);
				glScalef(3, 40, 3);
				glutSolidSphere(10, 16, 16);
			}
			glPopMatrix();
			//head
			glPushMatrix();
			{
				glColor4ub(30, 30, 30, 255);
				glTranslatef(0, -300, -10);
				glRotatef(90, 1, 0, 0);
				glScalef(1, 0.1,1);
				glutSolidCone(50, 100, 16, 16);
			}
			glPopMatrix();
			//wing
			glPushMatrix();
			{
				glColor4ub(232, 255, 255, 255);
				glTranslatef(0, 340, -10);
				glPushMatrix();
				{
					glRotatef(90, 1, 0, 0);
					glScalef(1, 0.1, 1);
					glutSolidCone(70, 100, 16, 16);
					glScalef(0.1, 10, 1);
					glutSolidCone(70, 100, 16, 16);
				}
				glPopMatrix();
			}
			glPopMatrix();
			break;
		}
	}
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}


void OBSTACLE::update(POINT_F playerLoc) {
	this->playerLoc = playerLoc;
	if (loc < playerLoc.z + 1300 && 0 < ypos) {
		ypos -= 70;
		if (ypos < 0)
			ypos = 0;
	}
}


int OBSTACLE::get_noKillDeg() {
	return noKillDeg;
}


bool OBSTACLE::collision(int currentDeg, POINT_F playerLoc) {
	if (playerLoc.z < loc - 20 || loc + 20 < playerLoc.z)
		return false;
	switch (kind) {
	case JUMP1:
		if (LAND_RAIDUS + JUMP1_H + 10 < playerLoc.y)
			return false;
		break;
	case JUMP2:
		if (playerLoc.y + CHMP_SIZE  <LAND_RAIDUS + JUMP1_H - 10 || LAND_RAIDUS + JUMP2_H + 10 < playerLoc.y)
			return false;
		break;
	case JUMP3:
		if (playerLoc.y + CHMP_SIZE  <LAND_RAIDUS + JUMP2_H - 10 || LAND_RAIDUS + JUMP2_H + 10 < playerLoc.y)
			return false;
		break;
	case ROTATE:
		if (currentDeg == noKillDeg && playerLoc.y + CHMP_SIZE  < 200)
			return false;
		break;
	case ARROW:
		if (currentDeg != KillDeg && currentDeg != KillDegSide)
			return false;
		break;
	}
	return true;
}


int OBSTACLE::is_arrow_stop() {
	if (kind == ARROW) {
		if (ypos == 0) {
			return YES;
		}
		return NO;
	}
	return NOTARROW;
}


int OBSTACLE::make_killDeg_side(int killDeg) {
	switch (killDeg) {
	case 1:
		return 5;
	case 2:
		return 6;
	case 3:
		return 7;
	case 4:
		return 8;
	case 5:
		return 1;
	case 6:
		return 2;
	case 7:
		return 3;
	case 8:
		return 4;
	}
	return 0;
}


OBSTACLE::~OBSTACLE()
{
}
