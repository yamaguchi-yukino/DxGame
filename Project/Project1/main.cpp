#include"DxLib.h"//��Dx���C�u�����[�i����j���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//��Windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);//��Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//��DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//����ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//����ʂ̑傫��

    //��DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //���G���[���N�����璼���ɏI��
        return -1;
    }
    //�~�̏����ʒu ����̍��W���O�C�O�@�E�ɍs���قǂ����W���A���ɍs���قǂ����W��������
    int circleX = 0;
    int circleY = 0;

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
        //�~��X���W�ɓ���������
        circleX += 2;
        circleY += 1;
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();
    }

    //��ʂɉ~��`�悳����
    DrawCircle(320, 240,30, GetColor(0, 0, 255), TRUE);

    //����ʂɓ_��`�悳���ĂˁiX���W�AY���W�A�_�̐F�w��j
    DrawPixel(320, 240, GetColor(255, 0, 0));
  
    //���L�[���͑҂��@���������̓L�[���͂������܂ő҂��Ă���I
    WaitKey();

    //��DxLib�g�p�̏I������
    DxLib_End();

    //���\�[�X�̏I��
    return 0;
}