#pragma once
#include "string"
using namespace std;         //  ���O��Ԏw��
//�e�N�X�`���R���o�[�^�[
class TextureConverter {

private:
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const string& filePath);
	//�}���`�o�C�g����������C�h������ɕϊ�
	static wstring ConvertMultiByteStringToWideString(const string& mString);

public:
	//�e�N�X�`����WIC����DDS�ɕϊ�����
	void ConverterTextureWICToDDS(const string& filePath);
};