#include "Basic.hlsli"

//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
Texture2D<float4> tex : register(t0);

//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v���[
SamplerState smp : register(s0);

float4 main(VSOutput input) : SV_TARGET
{
	//�E���������̃��C�g
	float3 light = normalize(float3(1,-1,1));
	//
	float diffuse = saturate(dot(-light, input.normal));
	//�����ւ̃x�N�g���Ɩ@���x�N�g���̓���
	//float brightness = dot(-light,input.normal);
	float brightness = diffuse + 0.3f;


	float4 texcolor = float4(tex.Sample(smp, input.uv));

	//�P�x��RGB�ɑ�����ďo��
	return float4(texcolor.rgb * brightness, texcolor.a) * color;
	//return float4(brightness, brightness, brightness, 1);


	//rgb�̖@����xyz,a��1�ŏo��
	//return float4(input.normal,1);

	//�摜
	//return float4(tex.Sample(smp,input.uv));

	//�F�t��
	//return float4(tex.Sample(smp,input.uv)) * color;

	//�^����
	//return float4(1,1,1,1);
}