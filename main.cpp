// �w�b�_�[�t�@�C���̓ǂݍ���
#include "DxLib.h"	//DxLib���g���Ƃ��͕K�v

// �}�N����`
#define GAME_TITLE	"�Q�[���^�C�g��"	// �Q�[���^�C�g��
#define GAME_WIDTH	1280				// �Q�[����ʂ̕�(�E�B�h�X)
#define GAME_HEIGHT	720					// �Q�[����ʂ̍���(�n�C�g)
#define GAME_COLOR	32					// �Q�[���̐F��

#define GAME_ICON_ID	333				// �Q�[����ICON��ID

#define GAME_WINDOW_BAR 0				// �E�B���h�E�o�[�̎��	

// �v���O������ WinMain ����n�܂�܂�
// windows�̃v���O���~���O���@ = (WinAPI)�œ����Ă���I
// DxLib�́ADirectX�Ƃ����A�Q�[���v���O���~���O���ȒP�Ɏg����d�g��
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{

	ChangeWindowMode(TRUE);								// �E�B���h�E���[�h�ɐݒ�
	SetMainWindowText(GAME_TITLE);						// �E�B���h�E�̃^�C�g���̕���
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	// �E�B���h�E�̉𑜓x��ݒ�
	SetWindowSize(GAME_WIDTH, GAME_HEIGHT);				// �E�B���h�E�̑傫����ݒ�
	SetBackgroundColor(255, 255, 255);					// �f�t�H���g�̔w�i�̐F
	SetWindowIconID(GAME_ICON_ID);						// �A�C�R���t�@�C����ǂݍ���
	SetWindowStyleMode(GAME_WINDOW_BAR);				// �E�B���h�E�o�[�̏��
	SetWaitVSyncFlag(TRUE);								// �f�B�X�v���C�̐���������L���ɂ���
	SetAlwaysRunFlag(TRUE);								// �E�B���h�E�������ƃA�N�e�B�u�ɂ���


	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	// �l�p�̈ʒu�����߂�
	int x = GAME_WIDTH / 2;
	int y = GAME_HEIGHT / 2;

	// ���x
	int xspeed = 10;
	int yspeed = 4;

	// �l�p�̑傫�������߂�
	int width = 32;		// ��
	int height = 32;	// ����

	// �~�̔��a�����߂�
	int radius = 100;

	// �_�u���o�b�t�@�����O�L����
	SetDrawScreen(DX_SCREEN_BACK);

	// �������[�v
	while (1)
	{
		// ��������L�[�������ꂽ�Ƃ�
		if (CheckHitKeyAll() != 0)
		{
			// �������[�v���ʂ���
			break;
		}

		// ���b�Z�[�W���󂯎�葱����
		if (ProcessMessage() != 0)	// -1�̂Ƃ��A�G���[��E�B���h�E������ꂽ
		{
			// �������[�v���ʂ���
			break;
		}

		// ��ʂ���������
		if (ClearDrawScreen() != 0) { break; }

		// �l�p��`��
		DrawBox(
			x, y, width, height,
			GetColor(255, 0, 0),	// �F���擾
			true					// �h��Ԃ��H
		);

		// �~��`��
		//DrawCircle(
		//	x, y, radius,
		//	GetColor(0, 255, 0),
		//	FALSE, 5
		//);

		x += xspeed;				// �l�p�̈ʒu���E�ɂ��炷
		y += yspeed;	

		if (x < 0 || x + width > GAME_WIDTH)
		{
			xspeed = -xspeed;
		}
		if (y < 0 || y + height > GAME_HEIGHT)
		{
			yspeed = -yspeed;
		}

		//if (x - radius < 0 || x + radius > GAME_WIDTH)
		//{
		//	xspeed = -xspeed;
		//}
		//if (y - radius < 0 || y + radius > GAME_HEIGHT)
		//{
		//	yspeed = -yspeed;
		//}

		ScreenFlip();				// �_�u���o�b�t�@�����O����ʂ�`��
		
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0; 
}