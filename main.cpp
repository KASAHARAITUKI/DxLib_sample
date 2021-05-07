// ヘッダーファイルの読み込み
#include "DxLib.h"	//DxLibを使うときは必要

// マクロ定義
#define GAME_TITLE	"ゲームタイトル"	// ゲームタイトル
#define GAME_WIDTH	1280				// ゲーム画面の幅(ウィドス)
#define GAME_HEIGHT	720					// ゲーム画面の高さ(ハイト)
#define GAME_COLOR	32					// ゲームの色域

#define GAME_ICON_ID	333				// ゲームのICONのID

#define GAME_WINDOW_BAR 0				// ウィンドウバーの種類	

// プログラムは WinMain から始まります
// windowsのプログラミング方法 = (WinAPI)で動いている！
// DxLibは、DirectXという、ゲームプログラミングを簡単に使える仕組み
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{

	ChangeWindowMode(TRUE);								// ウィンドウモードに設定
	SetMainWindowText(GAME_TITLE);						// ウィンドウのタイトルの文字
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	// ウィンドウの解像度を設定
	SetWindowSize(GAME_WIDTH, GAME_HEIGHT);				// ウィンドウの大きさを設定
	SetBackgroundColor(255, 255, 255);					// デフォルトの背景の色
	SetWindowIconID(GAME_ICON_ID);						// アイコンファイルを読み込み
	SetWindowStyleMode(GAME_WINDOW_BAR);				// ウィンドウバーの状態
	SetWaitVSyncFlag(TRUE);								// ディスプレイの垂直同期を有効にする
	SetAlwaysRunFlag(TRUE);								// ウィンドウをずっとアクティブにする


	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	// 四角の位置を決める
	int x = GAME_WIDTH / 2;
	int y = GAME_HEIGHT / 2;

	// 速度
	int xspeed = 10;
	int yspeed = 4;

	// 四角の大きさを決める
	int width = 32;		// 幅
	int height = 32;	// 高さ

	// 円の半径を決める
	int radius = 100;

	// ダブルバッファリング有効化
	SetDrawScreen(DX_SCREEN_BACK);

	// 無限ループ
	while (1)
	{
		// 何かしらキーがおされたとき
		if (CheckHitKeyAll() != 0)
		{
			// 無限ループをぬける
			break;
		}

		// メッセージを受け取り続ける
		if (ProcessMessage() != 0)	// -1のとき、エラーやウィンドウが閉じられた
		{
			// 無限ループをぬける
			break;
		}

		// 画面を消去する
		if (ClearDrawScreen() != 0) { break; }

		// 四角を描写
		DrawBox(
			x, y, width, height,
			GetColor(255, 0, 0),	// 色を取得
			true					// 塗りつぶし？
		);

		// 円を描画
		//DrawCircle(
		//	x, y, radius,
		//	GetColor(0, 255, 0),
		//	FALSE, 5
		//);

		x += xspeed;				// 四角の位置を右にずらす
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

		ScreenFlip();				// ダブルバッファリング下画面を描画
		
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0; 
}