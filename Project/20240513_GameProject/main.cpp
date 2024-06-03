#include "DxLib.h"//DXライブラリをインクルード（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) //Windowsのメインで動かす
{
    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DXライブラリの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(800, 600, 32);//画面の大きさ

    //DXライブラリの初期化処理
    if(DxLib_Init() == -1) 
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    //文字の位置
    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 60;
    
    //円の初期位置
    int circleX = 150;
    int circleY = 200;
    //マウスの座標
    int mouseX=0;
    int mouseY=0;
    //円の色
    int circleColor = GetColor(0, 0, 255);
    //文字の色
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 0, 0);
    //キー変数
    int key = 0;
    



    //ゲームループ
    while (ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();

        //文字の大きさの指定
        SetFontSize(32);

        //画面に文字表示
        //DrawString(10, 15, "Hello World", StringColor);
        DrawFormatString(10, 15, StringColor, "Mouse X:%d Y:%d", mouseX,mouseY);

        //画面に円を描画
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);

        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);

        //マウスがクリックされたら
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(32);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }

        DrawPixel(320, 240, GetColor(0, 0, 255));
        //テンキーの上
        if (CheckHitKey(KEY_INPUT_UP))
        {
            //円のY座標が40（円の半径）より小さくなったら押し返すよおおおおおおおお
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
            
        }
        //テンキーの下あああああああああああああああああああああああ
        if(CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }

        //テンキーの左
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }
        }

        //テンキーの右
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 760)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }

        //円のX座標に動きをつける
        //circleX += 4;
        ////円のY座標に動きをつける
        //circleY += 3;
        //if (circleX >= 800) 
        //{
        //    circleX = 0;
        //    circleY = 0;
        //}
        //裏画面の内容を表画面に反映させる
        ScreenFlip();
    }

    //画面に円を描画
   // DrawCircle(320, 240, 15, GetColor(0, 0, 255), TRUE);

    //画面に点を描画（x座標、y座標、点の色指定）
    DrawPixel(320, 240, GetColor(255, 0, 0));

    //キー入力待ち
    //WaitKey();

    //DXライブラリの終了処理
    DxLib_End();

    //ソースの終了
    return 0;
}