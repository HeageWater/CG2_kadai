#pragma once
#include <d3d12.h>

class Port
{
public:
	//�r���[�|�[�g�ݒ�R�}���h
	D3D12_VIEWPORT viewport{};

	//�V�U�[
	D3D12_RECT scissorRec{};

	//�|�[�g�͈�
	void DrawViewPort(ID3D12GraphicsCommandList* commandList);
	//�V�U�[�͈�
	void DrawScissor(ID3D12GraphicsCommandList* commandList);

	//������(�Œ�l)
	Port();

	//������(���)
	Port(int Width,int Height);

	//�`��͈͂̕ύX
	void ChengePort(int Width, int Height);
};