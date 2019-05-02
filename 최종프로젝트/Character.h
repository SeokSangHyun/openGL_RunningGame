#pragma once
#include "basic.h"


class Character {

	enum Charst {Run = 10, Die = 11, JumpUp = 20, JumpDown = 21};
	enum st {LEFT = 1, RIGHT = 2};
	int CharState{Charst::Run};					//		캐릭터 상태
	POINT_F CharPt{ 0, 50, 0 };

	
	GLdouble armScale[3] = {4, 30, 4};
	GLfloat armColor[3] = {1.0f, 1.0f, 0.0f};

	GLdouble bodyScale[3]{ 15, 30, 5 };
	GLfloat bodyColor[3]{0.9f, 0.9f, 0.6f};
	
	GLdouble legScale[3]{5, 30, 5};
	GLfloat legColor[3]{0.1f, 0.2f, 1.0f};

	//////////////저장 장소

	int buf_Armdir{ 0};
	int buf_Legdir{ 0};
	int buf_leftArmT{0};
	int buf_leftLegT{0 };
		
	int buf_rightArmT{ 0};
	int buf_rightLegT{ 0 };


	//변화량
	int buf_T{ 0 };//팔다리 각도
	GLdouble buf_bodyT{ 0.0f };	//몸뚱아리 각도


	//---Run
	/////////////////////
	int Armdir{st::LEFT};
	int Legdir{ st::RIGHT };
	int leftArmT{ 20 };
	int leftLegT{ -90 };

	int rightArmT{ -50 };
	int rightLegT{-160 };
	//팔뚝
	int foreArm{-45};
	//허벅지
	int thigh{ -20 };
	GLdouble thighT{ 10.0f };

	//변화량
	int T{ 12 };//팔다리 각도
	GLdouble bodyT{0.0f};	//몸뚱아리 각도
	bool start{ true };
	const float goFoward = 40;	//전진시 이동 속도
	const float goBack = -100;	//시작지점으로 복귀시 이동속도
	//
	GLdouble footT{ 0.0f };
	POINT_F footVecPt[8];
	POINT_F footSt[8];
	POINT_F footEd[8];
	//목도리
	GLfloat scaf_Color[3]{ 0.68f, 0.05f, 0.05f };
	GLfloat scaf[3][6][3];
	GLdouble scafT[2]{ 0.0f };
	int scafDir{ 1 };
	//
	/////////////////////////////////


	//---Jump
	//장애물 높이를 10번으로 나눈다.
	GLdouble Jump{ 23 };	//	점프하는 힘
	GLdouble JumpT{ 0.0f };//	중력을 적용하기위해
	GLdouble JumpRot{ 0.0f };


	int jumploc{ 0 };
	int RotY{ 0 };
	/////////////////////

public:
	Character();
	~Character();

	void EnterInfo();
	void SaveInfo();
	void EnterParticle();	//	발자국 효과
	GLdouble GetRot();

	void init();

	void arm();
	void leg();
	void body();


	POINT_F GetPt();
	void SetPt(POINT_F);


	void KeyBoard(unsigned char key);
	void draw();
	void timer();

	void make_char_die();
	void make_char_alive();
	bool is_alive();


	void ScafDraw();
	void ScafTimer();


	void ParticleDraw();
	void ParticleTimer();


	void CharJumpTimer();
	void CharRunTimer();	//캐릭터가 달릴때 상태 변화
};