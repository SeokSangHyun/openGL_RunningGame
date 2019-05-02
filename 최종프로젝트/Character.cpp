#include "Character.h"

Character::Character(){

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (j == 0) {
				scaf[i][j][0] = -4 + i * 4;
				scaf[i][j][1] = legScale[1] + bodyScale[1];
				scaf[i][j][2] = 0;
			}
			else {
				scaf[i][j][0] = scaf[i][j - 1][0];
				scaf[i][j][1] = scaf[i][j - 1][1];
				scaf[i][j][2] = scaf[i][j - 1][2] - 5;
			}
		}
	}
	scafT[0] = 0;
	scafT[1] = legScale[1] + bodyScale[1];
}



Character::~Character(){}

void Character::EnterInfo()
{
	Legdir		= buf_Legdir;
	Armdir		= buf_Armdir;
				 
	leftArmT	= buf_leftArmT;
	leftLegT	= buf_leftLegT;
				
	rightArmT	= buf_rightArmT;
	rightLegT	= buf_rightLegT;
				 
	T			= buf_T;
	bodyT		= buf_bodyT;



	foreArm = -45;
	thigh = -20;
		
}

void Character::SaveInfo()
{
	buf_Legdir = Legdir;
	buf_Armdir = Armdir;

	buf_leftArmT = leftArmT;
	buf_leftLegT = leftLegT;

	buf_rightArmT = rightArmT;
	buf_rightLegT = rightLegT;

	buf_T = T;
	buf_bodyT = bodyT;
}

void Character::EnterParticle() {
	int i = 0;

	if (CharState == Charst::Run) {
		if (Legdir == st::LEFT) {
			footT = 0.0f;
			for (i = 0; i < 8; ++i) {
				footSt[i].x = -bodyScale[0] / 2 + 1;
				footSt[i].y = 0;
				footSt[i].z = 0;

				footEd[i].x = footSt[i].x + (rand() % 10 - 10);
				footEd[i].y = footSt[i].y + (rand() % 10);
				footEd[i].z = footSt[i].z + (rand() % 10 + 20);

				footVecPt[i].x = footEd[i].x - footSt[i].x;
				footVecPt[i].y = footEd[i].y - footSt[i].y;
				footVecPt[i].z = footEd[i].z - footSt[i].z;
			}
		}

		else if (Legdir == st::RIGHT) {
			footT = 0.0f;
			for (i = 0; i < 8; ++i) {
				footSt[i].x = bodyScale[0] / 2 - 1;
				footSt[i].y = 0;
				footSt[i].z = 0;

				footEd[i].x = footSt[i].x + (rand() % 10 - 10);
				footEd[i].y = footSt[i].y + (rand() % 10);
				footEd[i].z = footSt[i].z + (rand() % 10 + 20);

				footVecPt[i].x = footEd[i].x - footSt[i].x;
				footVecPt[i].y = footEd[i].y - footSt[i].y;
				footVecPt[i].z = footEd[i].z - footSt[i].z;
			}
		}
	}
	else if(CharState == Charst::Die){
		footT = 0.0f;
		for (i = 0; i < 8; ++i) {
			footSt[i].x = CharPt.x;
			footSt[i].y = CharPt.y;

			footEd[i].x = CharPt.x + rand()%20-10;
			footEd[i].y = CharPt.y + rand()%20;

			footVecPt[i].x = footEd[i].x - footSt[i].x;
			footVecPt[i].y = footEd[i].y - footSt[i].y;
		}
	}
}

GLdouble Character::GetRot()
{
	return JumpRot;
}




void Character::init() {
	CharPt.x = 0; CharPt.y = 50;  CharPt.z = 40;
	CharState = Charst::Run;
	Armdir = st::LEFT;
	Legdir = st::RIGHT;
	leftArmT = 20;
	leftLegT = -90;

	rightArmT = -50;
	rightLegT = -160;

	foreArm = -45;
	thigh = -20;
	thighT = 10.0f;

	bodyT = 0.0f;
	start = true;

	Jump = 23;
	JumpT = 0.0f;
	JumpRot = 0.0f;

	buf_Armdir = 0;
	buf_Legdir = 0;
	buf_leftArmT = 0;
	buf_leftLegT = 0;

	buf_rightArmT = 0;
	buf_rightLegT = 0;

	buf_T = 0;
	buf_bodyT = 0;
	SaveInfo();
	EnterInfo();
}




void Character::arm()
{
	//왼팔
	glPushMatrix();
	{
		glTranslatef(-bodyScale[0]/2, bodyScale[1]/2, 0.0);
		glRotatef(leftArmT, 1.0, 0.0, 0.0);
		glRotatef(-30, 0.0, 0.0, 1.0);
		glTranslatef(0.0, -armScale[1]/4, 0);
		glPushMatrix();
		{
			glScalef(armScale[0], armScale[1]/2, armScale[2]);
			glColor3fv(armColor);
			glutSolidCube(1.0);
			glColor3f(0.0, 0.0, 0.0);
			glutWireCube(1.0);
		}
		glPopMatrix();

		glTranslatef(0, -armScale[1]/4, 0);
		glRotatef(30, 0.0, 0.0, 1.0);
		glRotatef(foreArm, 1.0, 0.0, 0.0);
		glTranslatef(0, -armScale[1] / 4, 0);

		glScalef(armScale[0], armScale[1] / 2, armScale[2]);
		glColor3fv(armColor);
		glutSolidCube(1.0f);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCube(1.0);
	}
	glPopMatrix();

	//오른팔
	glPushMatrix();
	{
		glTranslatef(bodyScale[0] / 2, bodyScale[1] / 2, 0.0);
		glRotatef(rightArmT, 1.0, 0.0, 0.0);
		glRotatef(30, 0.0, 0.0, 1.0);
		glTranslatef(0.0, -armScale[1] / 4, 0);
		glPushMatrix();
		{
			glScalef(armScale[0], armScale[1] / 2, armScale[2]);
			glColor3fv(armColor);
			glutSolidCube(1.0);
			glColor3f(0.0, 0.0, 0.0);
			glutWireCube(1.0);
		}
		glPopMatrix();

		glTranslatef(0, -armScale[1] / 4, 0);
		glRotatef(-30, 0.0, 0.0, 1.0);
		glRotatef(foreArm, 1.0, 0.0, 0.0);
		glTranslatef(0, -armScale[1] / 4, 0);

		glScalef(armScale[0], armScale[1] / 2, armScale[2]);
		glColor3fv(armColor);
		glutSolidCube(1.0f);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCube(1.0);
	}
	glPopMatrix();
}

void Character::leg()
{
	//왼 다리
	glPushMatrix();
	{
		glTranslatef(0.0, legScale[1], 0.0);
		glRotatef(thigh, 1.0, 0.0, 0.0);
		glTranslatef(-bodyScale[0]/2+1, -legScale[1]/2, 0);

		//
		glPushMatrix();
		{
			glRotatef(leftLegT, 1.0, 0.0, 0.0);
			glTranslatef(0,legScale[1] / 4, 0);
			glScalef(legScale[0], legScale[1]/2, legScale[2]);
			glColor3fv(legColor);
			glutSolidCube(1.0);
			glColor3f(0.0, 0.0, 0.0);
			glutWireCube(1.0);
		}
		glPopMatrix();

		glTranslatef(0.0, legScale[1] / 4, 0.0);
		glScalef(legScale[0], legScale[1] / 2, legScale[2]);
		glColor3fv(legColor);
		glutSolidCube(1.0);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCube(1.0);

	}
	glPopMatrix();

	//오른 다리
	glPushMatrix();
	{
		glTranslatef(0.0, legScale[1], 0.0);
		glRotatef(thigh, 1.0, 0.0, 0.0);
		glTranslatef(bodyScale[0] / 2 - 1, -legScale[1] / 2, 0);

		//
		glPushMatrix();
		{
			glRotatef(rightLegT, 1.0, 0.0, 0.0);
			glTranslatef(0, legScale[1] / 4, 0);
			glScalef(legScale[0], legScale[1] / 2, legScale[2]);
			glColor3fv(legColor);
			glutSolidCube(1.0);
			glColor3f(0.0, 0.0, 0.0);
			glutWireCube(1.0);
		}
		glPopMatrix();

		glTranslatef(0.0, legScale[1] / 4, 0.0);
		glScalef(legScale[0], legScale[1] / 2, legScale[2]);
		glColor3fv(legColor);
		glutSolidCube(1.0);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCube(1.0);

	}
	glPopMatrix();
}

void Character::body()
{
	/////
	glTranslatef(0.0, legScale[1], 0.0);
	glTranslatef(0.0, bodyScale[1]/2, 0.0);
	glRotatef(6, 1.0, 0.0, 0.0);
	
		glRotatef(bodyT, 0.0, 1.0, 0.0);
		glRotatef(bodyT, 0.0, 0.0, 1.0);
	
	//////
	glPushMatrix();
	{

		glScalef(bodyScale[0], bodyScale[1], bodyScale[2]);
		glColor3fv(bodyColor);
		glutSolidCube(1.0f);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCube(1.0f);
	}
	glPopMatrix();
}








POINT_F Character::GetPt()
{
	return CharPt;
}
void Character::SetPt(POINT_F _pt)
{
	CharPt.x = _pt.x;
	CharPt.y = _pt.y;
	CharPt.z = _pt.z;
}










void Character::KeyBoard(unsigned char key)
{
	if (key == ' ') {
		if (CharState == Charst::Run) {
			for (int i = 0; i < 5; ++i) {
				footVecPt[i].x = 0;
				footVecPt[i].y = 0;
				footVecPt[i].z = 0;
			}
			CharState = Charst::JumpUp;
			SaveInfo();
			PlaySound(TEXT("sounds/Jump.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
		}
	}
	else if (key == 'y' || key == 'Y') {
		RotY++;
	}

}

void Character::draw()
{
	glPushMatrix();
	{
		//
		glTranslatef(0, CharPt.y, CharPt.z);
		//
		if (CharState != Charst::Die) {
			glRotatef(RotY, 0.0, 1.0, 0.0);
			ParticleDraw();
			leg();
			body();
			arm();
			ScafDraw();
		}
		else {
			ParticleDraw();
		}
	}
	glPopMatrix();
}



void Character::timer()
{
	if (CharState == Charst::Die) {
		CharPt.z += goBack;
		if (CharPt.z < 40) {
			init();
		}
	}
	else {
		CharPt.z += goFoward;
		if (8200 < CharPt.z) {
			CharPt.z = 0;
		}
	}



	if (CharState == Charst::Run) {
		ParticleTimer();
		ScafTimer();
		CharRunTimer();
	}
	else if (CharState == Charst::Die) {
		ParticleTimer();
	}
	else {
		ScafTimer();
		CharJumpTimer();
	}
}



/*/////////////////////////////////////*/


void Character::make_char_die() {
	CharState = Charst::Die;
	EnterParticle();
	PlaySound(TEXT("sounds/Dead.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
}


void Character::make_char_alive() {
	CharState = Charst::Run;
}


bool Character::is_alive() {
	if (CharState == Charst::Die)
		return false;
	return true;
}

/*/////////////////////////////////////*/




void Character::ScafDraw()
{

	glColor3fv(scaf_Color);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 6, 0.0, 1.0, 18, 3, &scaf[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);

	glEvalMesh2(GL_FILL, 0, 10, 0, 10);

	glColor3fv(scaf_Color);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 6, 0.0, 1.0, 18, 3, &scaf[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);

	glEvalMesh2(GL_LINE, 0, 10, 0, 10);
}


/*/////////////////////////////////////*/


void Character::ScafTimer()
{
	if (CharState == Charst::JumpDown)
		jumploc =40;
	else if (CharState == Charst::JumpUp)
		jumploc = -20;
	else if (CharState == Charst::Run)
		jumploc = 0;

	scafT[0] += scafDir;
	scafT[1] += scafDir;

	if (scafT[0] > 20)
		scafDir *= -1;
	else if (scafT[0] < -20)
		scafDir *= -1;


	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (j == 0) {
				scaf[i][j][0] = -4 + i * 4;
				scaf[i][j][1] = bodyScale[1]/2;
			}
			else if (j == 1) {
				scaf[i][j][0] = rand() % 5-10;
				scaf[i][j][1] = rand() % 10 + 5;
			}
			else if (j == 2) {
				scaf[i][j][0] = scafT[0] + scafDir;
				scaf[i][j][1] =-scafT[1] - scafDir + jumploc;
			}
			else if (j == 3) {
				scaf[i][j][0] = scafT[0] + scafDir;
				scaf[i][j][1] = scafT[1] + scafDir + jumploc;
			}
			else if (j == 4) {
				scaf[i][j][0] = rand() % 10 - 10+scafT[0] + scafDir;
				scaf[i][j][1] = -scafT[1] - scafDir + jumploc/2;
			}
			else if (j ==5) {
				scaf[i][j][0] = rand() % 10 - 10;
				scaf[i][j][1] = rand() % 20-20 + 2.5*jumploc;
			}
		}
	}

}


/*//////////////////////////////////////////*/				



void Character::ParticleDraw() {
	POINT_F Pt;

	if (CharState == Charst::Run) {
		glPushMatrix();
		{
			glColor3f(1.0, 1.0, 1.0);
			for (int i = 0; i < 8; ++i) {
				Pt.x = footSt[i].x + footT*footVecPt[i].x;
				Pt.y = footSt[i].y + footT*footVecPt[i].y;
				Pt.z = footSt[i].z + footT*footVecPt[i].z;
				glPointSize(5.0);
				glBegin(GL_POINTS);
				{
					glVertex3f(Pt.x, Pt.y, -Pt.z);
				}
				glEnd();
			}
		}
		glPopMatrix();
	}
	else if (CharState == Charst::Die) {
		glColor3f(0.8, 0.5, 0.7);
		for (int i = 0; i < 8; ++i) {
			if (i<4)
				glColor3fv(bodyColor);
			else
				glColor3fv(legColor);

			Pt.x = footSt[i].x + footT* footVecPt[i].x;
			Pt.y = footSt[i].y + footT* footVecPt[i].y;

			glPushMatrix();
			{
				glTranslatef(Pt.x, Pt.y, 0);
				glScalef(2, 4, 2);
				glutSolidSphere(1.0, 20, 20);
			}
			glPopMatrix();
		}
	}
}






void Character::ParticleTimer() {


	if (CharState == Charst::Die) {
		footT += 0.05;
	}
	else
		footT += 0.15;
}



/*//////////////////////////////////*/



void Character::CharJumpTimer()
{
	if (CharState == Charst::JumpUp) {
		JumpT += 1.0;
		CharPt.y += (Jump - JumpT);

		if (CharPt.y <= legScale[1] / 2) {
			thigh = -20;
			leftLegT = -90;		rightLegT = -90;
		}
		else if (CharPt.y > legScale[1]) {
			thigh -= thighT;
			leftLegT += T;		rightLegT += T;
			leftArmT = 30;		rightArmT = 30;
			foreArm = -80;
			if (CharPt.y > 220) {
				leftArmT = 180;		rightArmT = 180;
				CharState = Charst::JumpDown;
			}
		}
	}
	else if (CharState == Charst::JumpDown) {
		JumpT -= 1.0;
		CharPt.y -= (Jump - JumpT);

		if (CharPt.y > legScale[1]) {
			thigh += thighT;
			foreArm = rand() % 60 - 30;
			leftLegT -= T;		rightLegT -= T;
		}
		else if (CharPt.y <= legScale[1]) {

			if (CharPt.y <= 50) {
				JumpT = 0.0;
				glLoadIdentity();
				CharPt.y = 50;
				EnterInfo();
				CharState = Charst::Run;
			}
		}
	}
}


void Character::CharRunTimer()
{
	if (Armdir == st::LEFT) {
		if (leftArmT < 20) {
			leftArmT += T;
			rightArmT -= T;
		}
		else if (leftArmT >= 20) {
			Armdir = st::RIGHT;
		}
	}
	else if (Armdir == st::RIGHT) {
		if (rightArmT < 20) {
			rightArmT += T;
			leftArmT -= T;
		}
		else if (rightArmT >= 20)
			Armdir = st::LEFT;
	}


	///
	if (Legdir == st::RIGHT) {//오른발 뒤로가는 상태
		if (leftLegT < -90) {
			leftLegT += T;
			rightLegT -= T;
		}
		else if (leftLegT >= -90) {
			Legdir = st::LEFT;
			EnterParticle();
		}
	}
	else if (Legdir == st::LEFT) {//왼발이 뒤로가는 상태
		if (rightLegT < -90) {
			rightLegT += T;
			leftLegT -= T;
		}
		else if (rightLegT >= -90) {
			Legdir = st::RIGHT;
			EnterParticle();
		}
	}



	////몸통
	//더하는 숫자 : T / 팔,다리 최대최소 사잇각
	if (Armdir == st::LEFT) {
		start = false;
		bodyT -= 0.8;
	}
	else if (Armdir == st::RIGHT) {
		if (start == true)
			bodyT += 0.4;
		else
			bodyT += 0.8;
	}
}
