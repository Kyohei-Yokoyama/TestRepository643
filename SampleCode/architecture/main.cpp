#include<DxLib.h>
#include<iostream>
//using	namespace std;

//struct Sample
//{
//	char c;		// 8bit
//	short w;	// 16bit
//	int e;		// 32bit
//};

// 2D�x�N�g��
struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

// ��`�̍\����
struct Rect
{
	// ���S�_
	Position2 center;

	float h;	// �����̔���
	float w;	// ���̔���

	float Left()const;
	float Right()const;
	float Top()const;
	float Bottom()const;

	float Width()const;
	float Height()const;

};

// �ϐ��錾
int mSpeed;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//DxLib::SetMainWindowText(_T("2016213 ���R ����"));
	ChangeWindowMode(true);
	SetWindowText(L"2016213 ���R ����");
	SetGraphMode(640, 480, 32);

	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// �ϐ��̏�����
	Rect rcA = { 100,100,50,50 };
	//Rect rcB = { 400,200,70,70 };

	mSpeed = 5;
	char keystate[256];

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		GetHitKeyStateAll(keystate);

		// ��
		if (keystate[KEY_INPUT_LEFT])
		{
			rcA.center.x -= mSpeed;
		}
		// �E
		if (keystate[KEY_INPUT_RIGHT])
		{
			rcA.center.x += mSpeed;
		}
		// ��
		if (keystate[KEY_INPUT_UP])
		{
			rcA.center.y -= mSpeed;
		}
		// ��
		if (keystate[KEY_INPUT_DOWN])
		{
			rcA.center.y += mSpeed;
		}

		// ��`A
		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Bottom(), 0xff0000, true);
		//// ��`B
		//DrawBox(rcB.Left(), rcB.Top(),
		//	rcB.Right(), rcB.Bottom(), 0x00ff00, true);


		ScreenFlip();
	}
	DxLib_End();

}

float Rect::Left()const
{
	return center.x - w;
}
float Rect::Right()const
{
	return center.x + w;
}
float Rect::Top()const
{
	return center.y - h;
}
float Rect::Bottom()const
{
	return center.y + h;
}