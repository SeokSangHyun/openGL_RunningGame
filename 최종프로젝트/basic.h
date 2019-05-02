#pragma once
#include <gl/glut.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <thread>

#pragma comment(lib, "glut32.lib")

using namespace std;

#define PI 3.1415926535



enum CHANGE_DEGREE { CD_O = 1, CD_T, CD_Th, CD_F, CD_Fv, CD_S, CD_Sv, CD_E, NONE};
enum ROTATE_STAT{STAY, LEFT, RIGHT};
enum TIMER_NAME{SURROUND};
enum KEY{ESC=27, ENTER=32};

typedef struct POINT_F {
	POINT_F() {}
	POINT_F(double new_x, double new_y, double new_z) {
		x = new_x; y = new_y; z = new_z;
	}
	POINT_F operator+(POINT_F point) { return POINT_F(point.x + x, point.y + y, point.z + z); }
	POINT_F operator-(POINT_F point) { return POINT_F(point.x - x, point.y - y, point.z - z); }
	POINT_F operator*(POINT_F point) { return POINT_F(point.x * x, point.y * y, point.z * z); }
	POINT_F operator/(POINT_F point) { return POINT_F(point.x / x, point.y / y, point.z / z); }
	double x, y, z;
}POINT_F;

typedef struct POINT_I {
	POINT_I() {}
	POINT_I(int new_x, int new_y, int new_z) {
		x = new_x; y = new_y; z = new_z;
	}
	POINT_I operator+(POINT_I point) { return POINT_I(point.x + x, point.y + y, point.z + z); }
	POINT_I operator-(POINT_I point) { return POINT_I(point.x - x, point.y - y, point.z - z); }
	POINT_I operator*(POINT_I point) { return POINT_I(point.x * x, point.y * y, point.z * z); }
	POINT_I operator/(POINT_I point) { return POINT_I(point.x / x, point.y / y, point.z / z); }
	int x, y, z;
}POINT_I;


class basic
{
private:
	float degree;
	int isRotate;
	float ROTATETIME;
	float DELAYTIME;
	float CHTIME;
	float CHDEGREE; 
	float rotateTime;
	float delayTime;
	bool stopRotate;
	int degreeStat;
	GLubyte * pBytes;
	BITMAPINFO * info;
	GLuint texture[8];
	float currentLoc;
public:
	basic();	
	void init();
	void update(float currentZ);
	void apply();
	void draw_way();
	void key_down(int key);
	void key_up(int key);
	void spkey_down(int key);
	void spkey_up(int key);
	int get_degree_state();
	~basic();
};


double degree_to_radian(double degree);
double radian_to_degree(double radian);	
double absolute(double value);
void draw_xyzLines();

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);