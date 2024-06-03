#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200
#define RESULT_STRING_X 15
#define RESULT_STRING_Y 15

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//�Q�[���t���O
bool enterPressedLastFrame = false;     //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;             //�Q�[���J�n�t���O
bool circleGenerationFlag = true;       //�~�̐����t���O
bool gameEndFlag = false;               //�Q�[���I���t���O
bool enterPressAllowed = true;          //�G���^�[�L�[��������Ă��邩��������t���O

//�Q�[���J�E���g
int enterPressCount;
//�\���̂�ϐ��ɂ���
circle Circle;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//�~�̖ʐϊ���
double circlePorpotoin = 0.0f;


//�t���[���J�E���g
double frameCount = 0;
//�f���^����
int prevCount, nowCout;
//���C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---------------------------//
    // ��{�ݒ�
    //---------------------------//
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//��ʂ̑傫��

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�F�w��
    int CircleColor = GetColor(128, 128, 128);
    int resultColor = GetColor(255, 255, 255);
    //�~�̑傫�����w��
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;
    //�t���[���J�E���g������
    nowCout = prevCount = GetNowCount();

    //---------------------------//
    // �Q�[�����[�v
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //���Ԃ��l��
        nowCout = GetNowCount();
        //�f���^�^�C��
        double deltaTime = (nowCout - prevCount) / 1000.0f;

        //�t���[���J�E���g�ɒǉ�
        frameCount += deltaTime;

        //��ʂ̏�����
        ClearDrawScreen();

        //�G���^�[�L�[�������ăQ�[�����X�^�[�g

        if (enterPressAllowed && CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            enterPressCount++;
            if (enterPressCount % 2 == 1)
            {
                //�Q�[���̊J�n
                gameStartFlag = true;
                gameEndFlag = false;
            }
            else
            {
                //�Q�[���̏I���t���O
                gameEndFlag = true;
                gameStartFlag = false;
                enterPressAllowed = false;
            }
        }
        //�G���^�[�L�[�������ꂽ�����L��������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);
        //�I���t���O��false�ł����
        if (!gameEndFlag)
        {
            //�~�̕ω�������
            if (gameStartFlag)
            {
                if (frameCount >= 1.0f / 60.f)
                {
                    frameCount = 0;
                    //�傫������
                    if (circleGenerationFlag)
                    {
                        //���a��5�����₷
                        Circle.radius += 5;
                        //���a���ő�l�ɂȂ����Ƃ��t���O��ϊ�
                        if (Circle.radius >= CIRCLE_RADIUS_MAX)
                        {
                            circleGenerationFlag = false;
                        }
                    }
                    //���a��5�����炷
                    else
                    {
                        Circle.radius -= 5;
                        //���a���ŏ��l�ɂȂ�����t���O��ϊ�
                        if (Circle.radius <= CIRCLE_RADIUS_START)
                        {
                            circleGenerationFlag = true;
                        }

                    }

                }
            }
        }
        else
        {
            //���U���g���o��
            Circle.area = M_PI * (double)Circle.radius * (double)Circle.radius;
            //�ʐς̊����v�Z
            circlePorpotoin = Circle.area / circleAreaMax * 100;
            //��ʂɕ`��
            SetFontSize(30);
            DrawFormatString(RESULT_STRING_X, RESULT_STRING_Y, resultColor, "�~�̊�����%.1f%%�ł�", circlePorpotoin);

        }


        //�~�̕`��
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CircleColor);


        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();
        //���������t���[���̎���
        prevCount = nowCout;



    }

    //Dxlib�I������
    DxLib_End();

    return 0;
}

