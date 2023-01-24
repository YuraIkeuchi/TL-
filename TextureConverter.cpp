#include "TextureConverter.h"
#include <Windows.h>
void TextureConverter::ConverterTextureWICToDDS(const string& filePath) {
	//テクスチャファイル読み込み
	LoadWICTextureFromFile(filePath);

	//DDS方式に変換して書き出す
	SaveDDSTextureToFile();
}

void TextureConverter::LoadWICTextureFromFile(const string& filePath) {
	HRESULT result;
	//ファイルパスをワイド文字列に変換する
	wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	SeparateFilePath(wfilePath);

	result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

wstring TextureConverter::ConvertMultiByteStringToWideString(const string& mString) {
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextureConverter::SeparateFilePath(wstring& filePath) {
	size_t pos1;
	wstring exceptExt;

	//区切り文字
	pos1 = filePath.rfind('.');

	//検索がヒットしたら
	if (pos1 != wstring::npos) {
		//区切り文字の後ろをファイル拡張子として保存
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
		//区切り文字の前までを抜き出す
		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		exceptExt = filePath;
	}

	pos1 = exceptExt.rfind('\\');
	if (pos1 != wstring::npos) {
		//区切り文字の前までをディレクtリパスとして保存
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		//区切り文字の後ろをファイル名として保存
		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);

		return;
	}

	pos1 = exceptExt.rfind('/');
	if (pos1 != wstring::npos) {
		//区切り文字の前までをディレクトリパスとして保存
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		//区切り文字の後ろをファイル名として保存
		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);

		return;
	}

	//区切り文字がないのでファイル名のみとして扱う
	directoryPath_ = L"";
	fileName_ = exceptExt;
}

void TextureConverter::SaveDDSTextureToFile() {
	metadata_.format = MakeSRGB(metadata_.format);

	HRESULT result;

	wstring filePath = directoryPath_ + fileName_ + L".dds";

	//DDSファイル書き出し
	result = SaveToDDSFile(scratchImage_.GetImages(), scratchImage_.GetImageCount(), metadata_,
		DDS_FLAGS_NONE, filePath.c_str());

	assert(SUCCEEDED(result));
}