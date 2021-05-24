#include<DxLib.h>
#include<iostream>
//using	namespace std;

//struct Sample
//{
//	char c;		// 8bit
//	short w;	// 16bit
//	int e;		// 32bit
//};

// 2Dベクトル
struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

// 矩形の構造体
struct Rect
{
	// 中心点
	Position2 center;

	float h;	// 高さの半分
	float w;	// 幅の半分

	float Left()const;
	float Right()const;
	float Top()const;
	float Bottom()const;

	float Width()const;
	float Height()const;

};

// 変数宣言
int mSpeed;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//DxLib::SetMainWindowText(_T("2016213 横山 恭兵"));
	ChangeWindowMode(true);
	SetWindowText(L"2016213 横山 恭兵");
	SetGraphMode(640, 480, 32);

	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// 変数の初期化
	Rect rcA = { 100,100,50,50 };
	//Rect rcB = { 400,200,70,70 };

	mSpeed = 5;
	char keystate[256];

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		GetHitKeyStateAll(keystate);

		// 左
		if (keystate[KEY_INPUT_LEFT])
		{
			rcA.center.x -= mSpeed;
		}
		// 右
		if (keystate[KEY_INPUT_RIGHT])
		{
			rcA.center.x += mSpeed;
		}
		// 上
		if (keystate[KEY_INPUT_UP])
		{
			rcA.center.y -= mSpeed;
		}
		// 下
		if (keystate[KEY_INPUT_DOWN])
		{
			rcA.center.y += mSpeed;
		}

		// 矩形A
		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Bottom(), 0xff0000, true);
		//// 矩形B
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