#pragma once
#include "basic.h"


class Character {

	enum Charst {Run = 10, Die = 11, JumpUp = 20, JumpDown = 21};
	enum st {LEFT = 1, RIGHT = 2};
	int CharState{Charst::Run};					//		ĳ���� ����
	POINT_F CharPt{ 0, 50, 0 };

	
	GLdouble armScale[3] = {4, 30, 4};
	GLfloat armColor[3] = {1.0f, 1.0f, 0.0f};

	GLdouble bodyScale[3]{ 15, 30, 5 };
	GLfloat bodyColor[3]{0.9f, 0.9f, 0.6f};
	
	GLdouble legScale[3]{5, 30, 5};
	GLfloat legColor[3]{0.1f, 0.2f, 1.0f};

	//////////////���� ���

	int buf_Armdir{ 0};
	int buf_Legdir{ 0};
	int buf_leftArmT{0};
	int buf_leftLegT{0 };
		
	int buf_rightArmT{ 0};
	int buf_rightLegT{ 0 };


	//��ȭ��
	int buf_T{ 0 };//�ȴٸ� ����
	GLdouble buf_bodyT{ 0.0f };	//���׾Ƹ� ����


	//---Run
	/////////////////////
	int Armdir{st::LEFT};
	int Legdir{ st::RIGHT };
	int leftArmT{ 20 };
	int leftLegT{ -90 };

	int rightArmT{ -50 };
	int rightLegT{-160 };
	//�ȶ�
	int foreArm{-45};
	//�����
	int thigh{ -20 };
	GLdouble thighT{ 10.0f };

	//��ȭ��
	int T{ 12 };//�ȴٸ� ����
	GLdouble bodyT{0.0f};	//���׾Ƹ� ����
	bool start{ true };
	const float goFoward = 40;	//������ �̵� �ӵ�
	const float goBack = -100;	//������������ ���ͽ� �̵��ӵ�
	//
	GLdouble footT{ 0.0f };
	POINT_F footVecPt[8];
	POINT_F footSt[8];
	POINT_F footEd[8];
	//�񵵸�
	GLfloat scaf_Color[3]{ 0.68f, 0.05f, 0.05f };
	GLfloat scaf[3][6][3];
	GLdouble scafT[2]{ 0.0f };
	int scafDir{ 1 };
	//
	/////////////////////////////////


	//---Jump
	//��ֹ� ���̸� 10������ ������.
	GLdouble Jump{ 23 };	//	�����ϴ� ��
	GLdouble JumpT{ 0.0f };//	�߷��� �����ϱ�����
	GLdouble JumpRot{ 0.0f };


	int jumploc{ 0 };
	int RotY{ 0 };
	/////////////////////

public:
	Character();
	~Character();

	void EnterInfo();
	void SaveInfo();
	void EnterParticle();	//	���ڱ� ȿ��
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
	void CharRunTimer();	//ĳ���Ͱ� �޸��� ���� ��ȭ
};