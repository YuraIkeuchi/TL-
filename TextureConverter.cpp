#include "TextureConverter.h"
#include <Windows.h>
void TextureConverter::ConverterTextureWICToDDS(const string& filePath) {
	//�e�N�X�`���t�@�C���ǂݍ���
	LoadWICTextureFromFile(filePath);

	//DDS�����ɕϊ����ď����o��
	SaveDDSTextureToFile();
}

void TextureConverter::LoadWICTextureFromFile(const string& filePath) {
	HRESULT result;
	//�t�@�C���p�X�����C�h������ɕϊ�����
	wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	SeparateFilePath(wfilePath);

	result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
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

void TextureConverter::SeparateFilePath(wstring& filePath) {
	size_t pos1;
	wstring exceptExt;

	//��؂蕶��
	pos1 = filePath.rfind('.');

	//�������q�b�g������
	if (pos1 != wstring::npos) {
		//��؂蕶���̌����t�@�C���g���q�Ƃ��ĕۑ�
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
		//��؂蕶���̑O�܂ł𔲂��o��
		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		exceptExt = filePath;
	}

	pos1 = exceptExt.rfind('\\');
	if (pos1 != wstring::npos) {
		//��؂蕶���̑O�܂ł��f�B���Nt���p�X�Ƃ��ĕۑ�
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		//��؂蕶���̌����t�@�C�����Ƃ��ĕۑ�
		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);

		return;
	}

	pos1 = exceptExt.rfind('/');
	if (pos1 != wstring::npos) {
		//��؂蕶���̑O�܂ł��f�B���N�g���p�X�Ƃ��ĕۑ�
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		//��؂蕶���̌����t�@�C�����Ƃ��ĕۑ�
		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);

		return;
	}

	//��؂蕶�����Ȃ��̂Ńt�@�C�����݂̂Ƃ��Ĉ���
	directoryPath_ = L"";
	fileName_ = exceptExt;
}

void TextureConverter::SaveDDSTextureToFile() {
	metadata_.format = MakeSRGB(metadata_.format);

	HRESULT result;

	wstring filePath = directoryPath_ + fileName_ + L".dds";

	//DDS�t�@�C�������o��
	result = SaveToDDSFile(scratchImage_.GetImages(), scratchImage_.GetImageCount(), metadata_,
		DDS_FLAGS_NONE, filePath.c_str());

	assert(SUCCEEDED(result));
}