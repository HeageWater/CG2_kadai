#include "viewport.h"

Port::Port()
{
	//�r���[�ݒ�
	viewport.Width = 1280;
	viewport.Height = 720;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	//�V�U�[�ݒ�
	scissorRec.left = 0;				 //�؂蔲�����W��
	scissorRec.right = 1280;	 //�؂蔲�����W�E
	scissorRec.top = 0;				 //�؂蔲�����W��
	scissorRec.bottom = 720;	 //�؂蔲�����W��
}

Port::Port(int Width, int Height)
{
	viewport.Width = Width;
	viewport.Height = Height;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	scissorRec.left = 0;				 //�؂蔲�����W��
	scissorRec.right = Width;	 //�؂蔲�����W�E
	scissorRec.top = 0;				 //�؂蔲�����W��
	scissorRec.bottom = Height;	 //�؂蔲�����W��
}

void Port::DrawViewPort(ID3D12GraphicsCommandList* commandList)
{
	//�r���[�|�[�g�ݒ�R�}���h���A�R�}���h���X�g�ɐς�
	commandList->RSSetViewports(1, &viewport);
}

void Port::DrawScissor(ID3D12GraphicsCommandList* commandList)
{
	//�V�U�[��`�ݒ�R�}���h���A�R�}���h���X�g�ɐς�
	commandList->RSSetScissorRects(1, &scissorRec);
}

