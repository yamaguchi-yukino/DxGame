#include "DxLib.h"//DX���C�u�������C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) //Windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DX���C�u�����̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    //DX���C�u�����̏���������
    if(DxLib_Init() == -1) 
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�����̈ʒu
    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 60;
    
    //�~�̏����ʒu
    int circleX = 150;
    int circleY = 200;
    //�}�E�X�̍��W
    int mouseX=0;
    int mouseY=0;
    //�~�̐F
    int circleColor = GetColor(0, 0, 255);
    //�����̐F
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 0, 0);
    //�L�[�ϐ�
    int key = 0;
    



    //�Q�[�����[�v
    while (ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();

        //�����̑傫���̎w��
        SetFontSize(32);

        //��ʂɕ����\��
        //DrawString(10, 15, "Hello World", StringColor);
        DrawFormatString(10, 15, StringColor, "Mouse X:%d Y:%d", mouseX,mouseY);

        //��ʂɉ~��`��
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);

        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);

        //�}�E�X���N���b�N���ꂽ��
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(32);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }

        DrawPixel(320, 240, GetColor(0, 0, 255));
        //�e���L�[�̏�
        if (CheckHitKey(KEY_INPUT_UP))
        {
            //�~��Y���W��40�i�~�̔��a�j��菬�����Ȃ����牟���Ԃ��您��������������
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
            
        }
        //�e���L�[�̉�����������������������������������������������
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

        //�e���L�[�̍�
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

        //�e���L�[�̉E
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

        //�~��X���W�ɓ���������
        //circleX += 4;
        ////�~��Y���W�ɓ���������
        //circleY += 3;
        //if (circleX >= 800) 
        //{
        //    circleX = 0;
        //    circleY = 0;
        //}
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();
    }

    //��ʂɉ~��`��
   // DrawCircle(320, 240, 15, GetColor(0, 0, 255), TRUE);

    //��ʂɓ_��`��ix���W�Ay���W�A�_�̐F�w��j
    DrawPixel(320, 240, GetColor(255, 0, 0));

    //�L�[���͑҂�
    //WaitKey();

    //DX���C�u�����̏I������
    DxLib_End();

    //�\�[�X�̏I��
    return 0;
}