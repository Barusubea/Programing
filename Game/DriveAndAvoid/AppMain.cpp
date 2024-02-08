#include "DxLib.h"
#include"Scene/SceneManager.h"

//���C���֐�
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevinstance, _In_
	LPSTR ipCmdLine, _In_ int nShowCmd)
{
	//��O�����i�ُ킪����������Acatch���ɔ�т܂��j
	try
	{
		//�V�[���}�l�[�W���[�@�\����
		SceneManager manager;

		//�V�[���}�l�[�W���[�@�\�̏���������
		manager.Initialize();

		//�V�[���}�l�[�W���[�@�\�̍X�V����
		manager.Update();

		//�V�[���}�l�[�W���[�@�\�̏I��������
		manager.Finalize();
	}
	catch (const char* err_log)
	{
		//�G���[�������e�̏o��
		OutputDebugString(err_log);

		//�G���[�I����ʒm
		return -1;
	}

	//����I����ʒm
	return 0;
}