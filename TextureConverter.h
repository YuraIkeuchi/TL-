#pragma once
#include "string"
#include <d3dx12.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;
using namespace std;         //  ���O��Ԏw��
//�e�N�X�`���R���o�[�^�[
class TextureConverter {
public:
	//�g�p���@���o�͂���
	static void OutPutUsage();
private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const string& filePath);
	//�}���`�o�C�g����������C�h������ɕϊ�
	static wstring ConvertMultiByteStringToWideString(const string& mString);
	//�t�H���_�p�X�ƃt�@�C�����𕪗�����
	void SeparateFilePath(wstring& filePath);
	//DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	void SaveDDSTextureToFile(int numOptions, char* options[]);

public:
	//�e�N�X�`����WIC����DDS�ɕϊ�����
	void ConverterTextureWICToDDS(const string& filePath,int numOptions = 0,char* options[] = nullptr);

	//�����o�ϐ�
private:

	//�摜�̎擾
	TexMetadata metadata_;
	//�摜�̃C���[�W�R���e�i
	ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	wstring directoryPath_;
	//�t�@�C����
	wstring fileName_;
	//�t�@�C���g���q
	wstring fileExt_;
};