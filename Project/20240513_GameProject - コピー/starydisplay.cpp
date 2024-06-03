/*--------------------------memo-----------------------------
ゲームを作るときに考えること
〇どんなジャンルで作るか　　　　
→わかりやすく、画面の動き少ないゲームを作ろうと思った。
例：・ボタンを押し続けるだけ
    ・数回の操作で終わる
    →タイミングゲーム
↓
〇操作＆画面はどうするのか
・エンター１個で終わらせる　
・画面の設計（UIの部品）作り　→TIMEだったり％だったりアニメーションだったり。Soundだったり。操作が簡単なもの程楽しい。
↓
●コーティング（プログラミング）

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

【ソースコードが長い問題】
部品ごとにわけて、おいておく。
関数（メソッド、モジュール、ファンクション）

                        ｛スタート画面処理
  場面画面で切り分ける  ｛ゲーム画面処理
                        ｛リザルト
*/



#include "DxLib.h"
#include<math.h>
#include<stdlib.h>

//定数
#define SCREEN_X 800
#define SCREEN_Y 600
#define STRAT_STRING_X 230
#define STRAT_STRING_Y 520

//フレームカウント
double frameCount = 0;
//デルタ時間
int prevCount, nowCout;

//画像ハンドル変数
int startScreenImage;

//アルファ値
int alpha;

//メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
    //------------------------------------
    // 基本設定
    //------------------------------------
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DXライブラリの初期化
    SetMainWindowText("タイミングゲーム");
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//画面の大きさ

    //DXライブラリの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return-1;
    }

    //画像をメモリに追加
    startScreenImage = LoadGraph("img/tittle01.png");

    //文字の色
    int stringColor = GetColor(255,99,71);

    prevCount = GetNowCount();
    //------------------------------------
    // ゲームループ
    //------------------------------------
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //時間を獲得
        nowCout = GetNowCount();

        //デルタタイム
        double deltaTime = (nowCout - prevCount) / 1000.0;

        //フレームカウントに追加
        frameCount += deltaTime * 1000;

        //画面の描画
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);

        //アルファ値を計算
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.001))));

        //描画モードをブレンドモードに設定
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        SetFontSize(30);
        DrawFormatString(STRAT_STRING_X, STRAT_STRING_Y, stringColor, "Press Enter to Start");

        //描画モードを戻す
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

        prevCount == nowCout;


    }
    //DxLib終了処理
    DxLib_End();

    return 0;
}


 