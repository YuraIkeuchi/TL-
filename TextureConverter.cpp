#include "TextureConverter.h"
#include <Windows.h>
void TextureConverter::ConverterTextureWICToDDS(const string& filePath) {
	//�e�N�X�`���t�@�C���ǂݍ���
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const string& filePath) {
	//�t�@�C���p�X�����C�h������ɕϊ�����
	wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
}

wstring TextureConverter::ConvertMultiByteStringToWideString(const string& mString) {
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}