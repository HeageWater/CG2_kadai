#pragma once
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <cassert>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

class Key
{
private:

	//�L�[�{�[�h�f�o�C�X�̐���
	IDirectInputDevice8* keyboard = nullptr;

	//DirectInput�̏�����
	IDirectInput8* directInput = nullptr;

	HRESULT result;

	BYTE key[256] = {};

	//�S�L�[�̓��͏�Ԃ�ۑ�����
	BYTE oldkey[256] = {};

public:
	//�C���X�^���X
	Key();
	Key(WNDCLASSEX a, HWND hw);
	~Key();
	//�X�V
	void Update();
	//��������
	bool PushKey(bool key);
	//�����Ă��
	bool KeepPushKey(bool key);
	//�������u��
	bool ReleaseKey(bool key);
};