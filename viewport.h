#pragma once
#include <d3d12.h>

class Port
{
public:
	//�r���[�|�[�g�ݒ�R�}���h
	D3D12_VIEWPORT viewport{};

	//�V�U�[
	D3D12_RECT scissorRec{};

	void DrawViewPort(ID3D12GraphicsCommandList* commandList);
	void DrawScissor(ID3D12GraphicsCommandList* commandList);

	Port();
	Port(int Width,int Height);
};