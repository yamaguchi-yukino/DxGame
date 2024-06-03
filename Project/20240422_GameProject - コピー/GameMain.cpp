/*
* �G���g���[�|�C���g���Q�[�����[�v
*/
#include "GameData.h"
#include "GameFunctuion.h"

//�G���g���[�|�C���g
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

    //�~�̑傫�����w��
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;


    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�t���[���J�E���g������
    nowCout = prevCount = GetNowCount();
    //---------------------------//
    // �Q�[�����[�v
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //���Ԃ��l��
        nowCout = GetNowCount();
        //�f���^�^�C������
        double deltaTime = (nowCout - prevCount) / 1000.0f;
        //�t���[���J�E���g�𑝉�
        frameCount += deltaTime;

        //�G���^�[�L�[�������ꂽ�����L��������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        //�G���^�[�L�[�������ꂽ�񐔂ŕύX����
        //0��i�X�^�[�g��ʂ̕\���j
        if (!gameStartFlag && !gameEndFlag)
        {
            //�X�^�[�g��ʊ֐����Ăяo��
            StartScreen(deltaTime);
        }
        //1�񂩂�3��i�Q�[����ʁj
        else if (gameStartFlag && !gameEndFlag)
        {
            //�Q�[����ʊ֐����Ăяo��
            GameProcessing(deltaTime);
        }
        //3��ȍ~�i���U���g��ʁj
        else if (gameEndFlag)
        {
            ResultScreen();
        }

        //���������t���[���̎���
        prevCount = nowCout;


    }


    //Dxlib�I������
    DxLib_End();

    return 0;
}