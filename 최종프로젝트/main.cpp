#include "GAMESTATE.h"
#include "MAINSTATE.h"
#include "TITLESTATE.h"



bool state = false;
int current_theme = LOGO;
GAMESTATE logo_state;
MAINSTATE main_state;
TITLESTATE title_state;
GAMESTATE *gameStat = &logo_state;


GLvoid drawScene(GLvoid) {
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (state) {
		gameStat->draw();
	}

	glutSwapBuffers();
}


GLvoid reshape(int w, int h) {
	gameStat->reshape(w, h);
}


GLvoid timerFunc(int value) {
	int theme;
	switch (value) {
	case SURROUND:
		if (state == false) {
			gameStat->init();
			reshape(800, 800);
			state = true;
		}
		theme = gameStat->update();
		if (theme != current_theme) {
			switch (theme) {
			case LOGO:
				gameStat = &logo_state;
				current_theme = LOGO;
				break;
			case TITLE:
				gameStat = &title_state;
				current_theme = TITLE;
				break;
			case MAIN:
				gameStat = &main_state;
				current_theme = MAIN;
				break;
			}
			state = false;
		}

		
		glutTimerFunc(50, timerFunc, SURROUND);
		break;
	}
	glutPostRedisplay();
}


GLvoid keyDown(unsigned char key, int x, int y) {
	gameStat->key_down(key);
	
}


GLvoid keyUp(unsigned char key, int x, int y) {
	gameStat->key_up(key);
}


GLvoid specialKeyDown(int key, int x, int y) {
	gameStat->spkey_down(key);
}


GLvoid specialKeyUp(int key, int x, int y) {
	gameStat->spkey_up(key);
}


void mouseFunc(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {

	}
	glutPostRedisplay();
}


void menuFunc(int button) {

}


int main(void) {
	mciSendString(TEXT("open sounds/background.mp3 type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("sounds/background.mp3"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3 repeat"), NULL, 0, NULL);
	mciSendString(TEXT("setaudio MP3 volume to 300"), NULL, 0, NULL);
	srand((unsigned)time(NULL));
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(500, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("´Þ·Á¶ó");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutMouseFunc(mouseFunc);


	

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_BLEND);

	glutTimerFunc(50, timerFunc, SURROUND);
	glutMainLoop();
	return 0;
}