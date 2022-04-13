#include <Windows.h>

LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//������

	//�E�B���h�E�T�C�Y
	const int window_width = 1280;
	const int window_height = 720;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXGame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	//�E�B���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);

	//�E�B���h�E�T�C�Y{x,y,����,�c��}
	RECT wrc = { 0,0,window_width,window_height };

	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	HWND hwnd = CreateWindow(w.lpszClassName, //�N���X��
		L"DirectXGame",						  //�^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,				  //�W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,						  //�\��x���W(OS�ɔC����)
		CW_USEDEFAULT,						  //�\��y���W(OS�ɔC����)
		wrc.right - wrc.left,				  //�E�B���h�E����
		wrc.bottom - wrc.top,				  //�E�B���h�E�c��
		nullptr,							  //�e�E�B���h�E�n���h��
		nullptr,							  //���j���[�n���h��
		w.hInstance,						  //�Ăяo���A�v���P�[�V����
		nullptr);							  //�I�v�V����

	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);

	//OutputDebugStringA("Hello,DirectX!!\n");

	MSG msg{};

	//�Q�[�����[�v
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//x�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT)
		{
			break;
		}
	}

	//�I������

	//�E�B���h�E�N���X��o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);

	return 0;
}