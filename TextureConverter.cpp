#include "TextureConverter.h"
#include <Windows.h>
void TextureConverter::ConverterTextureWICToDDS(const string& filePath) {
	//テクスチャファイル読み込み
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const string& filePath) {
	//ファイルパスをワイド文字列に変換する
	wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
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