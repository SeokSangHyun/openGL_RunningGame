#include "basic.h"


basic::basic() {
	isRotate = STAY;
	degreeStat = CD_O;
	ROTATETIME = 0.15;
	DELAYTIME = 0.05;
	CHTIME = 0.05;
	CHDEGREE = 45 / ROTATETIME;
}

void basic::init() {
	glGenTextures(8, texture);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("texture/road1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("texture/road2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	pBytes = LoadDIBitmap("texture/road3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	pBytes = LoadDIBitmap("texture/road4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	pBytes = LoadDIBitmap("texture/road5.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	pBytes = LoadDIBitmap("texture/road6.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[6]);
	pBytes = LoadDIBitmap("texture/road7.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
	pBytes = LoadDIBitmap("texture/road8.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}


void basic::update(float currentZ) {
	currentLoc = currentZ;
	if (isRotate == LEFT) {
		if (CHTIME < rotateTime)
			degree += CHTIME * CHDEGREE;
		if (360 <= degree)
			degree -= 360;
		
		
	}
	else if (isRotate == RIGHT) {
		if (CHTIME < rotateTime)
			degree -= CHTIME * CHDEGREE;
		if (degree < 0)
			degree += 360;
	}

	if (CHTIME< delayTime)
		delayTime -= CHTIME;
	if (CHTIME < rotateTime)
		rotateTime -= CHTIME;

	if (isRotate!= STAY && delayTime <= 0) {
		if (stopRotate) {
			isRotate = STAY;
			rotateTime = 0;
			delayTime = 0;
		}
		else {
			if (isRotate == LEFT)
				degreeStat += 1;
			else
				degreeStat -= 1;
			if (degreeStat < CD_O)
				degreeStat = CD_E;
			else if (CD_E < degreeStat)
				degreeStat = CD_O;
			rotateTime = ROTATETIME;
			delayTime = ROTATETIME + DELAYTIME;
		}
	}
}


void basic::apply() {
	glRotatef(degree, 0, 0, 1);
}


void basic::draw_way() {
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);

	float deg = 0;
	for (int i = 0; i < 8; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[i]);
		glPushMatrix();
		{
			glTranslatef(0, 0, -600);
			glRotatef(deg, 0, 0, 1);
			for (int j = 0; j < 45; j++) {
				glPushMatrix();
				{
					glTranslatef(0, 0,j * 256);
					glBegin(GL_QUADS); {
						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(- 20.75, 50, - 256);
						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(- 20.75, 50, 0);
						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(20.75, 50, 0);
						glTexCoord2f(1.0f, 1.0f);
						glVertex3f(20.75, 50, - 256);
					}
					glEnd();
				}
				glPopMatrix();
			}
		}
		deg -= 45;
		glPopMatrix();
		
	}
	glDisable(GL_TEXTURE_2D);
}


void basic::key_down(int key) {

}


void basic::key_up(int key) {

}


void basic::spkey_down(int key) {
	//delayTime �� 0�̾�� ȸ�� ����
	if (delayTime <= CHTIME) {
		if (key == GLUT_KEY_UP) { return; }
		else if (key == GLUT_KEY_DOWN) { return; }
		else if (key == GLUT_KEY_LEFT) {
			isRotate = LEFT;
			degreeStat -= 1;
		}
		else if (key == GLUT_KEY_RIGHT) {
			isRotate = RIGHT;
			degreeStat += 1;
		}
		rotateTime = ROTATETIME;
		delayTime = ROTATETIME + DELAYTIME;
		stopRotate = false;
	}
	//���ư��� ���� �Ѱ踦 ������ �ݴ������� ����
	if (degreeStat < CD_O)
		degreeStat = CD_E;
	else if (CD_E < degreeStat)
		degreeStat = CD_O;
}


void basic::spkey_up(int key) {
	//���ư��� ���̸� ���� ���� ���� �ƴϸ� �ٷ� ����
	if (0 < rotateTime) {
		if (key == GLUT_KEY_LEFT) {
			if (isRotate == LEFT)
				stopRotate = true;
		}
		else if (key == GLUT_KEY_RIGHT) {
			if (isRotate == RIGHT)
				stopRotate = true;
		}
	}
	else {
		if (key == GLUT_KEY_LEFT) {
			if (isRotate == LEFT)
				isRotate = STAY;
		}
		else if (key == GLUT_KEY_RIGHT) {
			if (isRotate == RIGHT)
				isRotate = STAY;
		}
		rotateTime = 0;
		delayTime = 0;
	}
	
}


int basic::get_degree_state() {
	return degreeStat;
}


basic::~basic() {

}


double degree_to_radian(double degree) {
	return degree * PI / 180;
}


double radian_to_degree(double radian)
{
	return radian * 180 / PI;
}


double absolute(double value) {
	if (value < 0)
		return -value;
	else
		return value;
}


void draw_xyzLines() {
	glLineWidth(2.5);
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100);
	}
	glEnd();
}


GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info)
{
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	// ���̳ʸ� �б� ���� ������ ����
	fopen_s(&fp, filename, "rb");
	if (fp == NULL)
		return NULL;
	// ��Ʈ�� ���� ����� �д´�.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) {
		fclose(fp);
		return NULL;
	}
	// ������ BMP �������� Ȯ���Ѵ�.
	if (header.bfType != 'MB') {
		fclose(fp);
		return NULL;
	}

	// BITMAPINFOHEADER ��ġ�� ����.
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	// ��Ʈ�� �̹��� �����͸� ���� �޸� �Ҵ��� �Ѵ�.
	if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
		fclose(fp);
		exit(0);
		return NULL;
	}
	// ��Ʈ�� ���� ����� �д´�.
	if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) {
		free(*info);
		fclose(fp);
		return NULL;
	}

	// ��Ʈ���� ũ�� ����
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth *
			(*info)->bmiHeader.biBitCount + 7) / 8.0 *
		abs((*info)->bmiHeader.biHeight);
	// ��Ʈ���� ũ�⸸ŭ �޸𸮸� �Ҵ��Ѵ�.
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp);
		return NULL;
	}
	// ��Ʈ�� �����͸� bit(GLubyte Ÿ��)�� �����Ѵ�.
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) {
		free(*info); free(bits);
		fclose(fp);
		return NULL;
	}
	fclose(fp);
	return bits;
}