#pragma once

#include <DirectXMath.h>
#include <vector>
using namespace DirectX;

//���_�f�[�^�\����
struct Vertex
{
	XMFLOAT3 pos;
	XMFLOAT3 noemal;
	XMFLOAT2 uv;
};

class Vertexs
{
public:
	Vertexs();
	//���_�f�[�^
	Vertex vertices[];
};