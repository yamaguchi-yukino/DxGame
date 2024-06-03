/*
�Q�[���֐���`
*/
#include "GameData.h"
#include "GameFunctuion.h"

//�X�^�[�g��ʂ̏���

void StartScreen(double deltaTime)
{
    //���C������t���[�������l��
    frameCount += deltaTime;

    //�摜�n���h���ϐ�
    int startScreenImage;
    //�A���t�@�l
    int alpha;

    //�摜���������ɒǉ�
    startScreenImage = LoadGraph("img/tittle01.png");

    //�����̐F
    int stringColor = GetColor(255, 99, 71);


    //�G���^�[�L�[�������ăQ�[���X�^�[�g
    if (enterPressAllowed && CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
    {
        gameStartFlag = true;
    }
    else
    {
        //�摜�̕`��
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //�A���t�@�l���v�Z
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

        //�`�惂�[�h���u�����h���[�h�ɐݒ�
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        SetFontSize(30);
        DrawFormatString(STRAT_STRING_X, STRAT_STRING_Y, stringColor, "Press Enter to Start");
        //�`�惂�[�h��߂�
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }


}

void GameProcessing(double deltaTime)
{

}

void ResultScreen()
{

}