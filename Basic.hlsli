//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}

//�}�e���A��
cbuffer ConstBufferDataMaterial : register(b0)
{
	float4 color;
};

struct VSOutput
{
	//�V�X�e���p���_���W
	float4 svpos : SV_POSITION;

	//uv�l
	float2 uv :TEXCOORD;
};