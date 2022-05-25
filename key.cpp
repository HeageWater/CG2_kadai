#include "key.h"

Key::Key(WNDCLASSEX a, HWND hw)
{
	result = DirectInput8Create(
		a.hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	result = directInput->CreateDevice(GUID_SysKeyboard,
		&keyboard, NULL);

	//���̓f�[�^�`���̃Z�b�g
	//�W���`��
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	//�r�����䃌�x���̃Z�b�g
	result = keyboard->SetCooperativeLevel(
		hw, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

Key::~Key()
{

}

//�X�V
void Key::Update()
{
	//�S�L�[�̓��͏�Ԃ�ۑ�����
	for (int i = 0; i < sizeof(oldkey); i++)
	{
		oldkey[i] = keys[i];
	}

	//�L�[�{�[�h���̎擾�J�n
	keyboard->Acquire();

	keyboard->GetDeviceState(sizeof(keys), keys);
}

//�������u��
bool Key::PushKey(uint8_t key)
{
	if (keys[key] != false &&
		oldkey[key] == false)
	{
		return true;
	}
	return false;
}

//�����Ă��
bool  Key::KeepPushKey(uint8_t key)
{
	if (keys[key] != false)
	{
		return true;
	}
	return false;
}

//�������u��
bool Key::ReleaseKey(uint8_t key)
{
	if (keys[key] == false &&
		oldkey[key] != false)
	{
		return true;
	}
	return false;
}