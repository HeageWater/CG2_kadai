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
	delete keyboard;
	delete directInput;
}

//�X�V
void Key::Update()
{
	//�L�[�{�[�h���̎擾�J�n
	keyboard->Acquire();

	//�S�L�[�̓��͏�Ԃ�ۑ�����
	for (int i = 0; i < sizeof(oldkey); i++)
	{
		oldkey[i] = key[i];
	}

	keyboard->GetDeviceState(sizeof(key), key);

}

//�������u��
bool Key::PushKey(bool key)
{
	if (key == true)
	{
		return true;
	}
	return false;
}