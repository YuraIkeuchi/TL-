#pragma once
#include "string"
using namespace std;         //  名前空間指定
//テクスチャコンバーター
class TextureConverter {

private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const string& filePath);
	//マルチバイト文字列をワイド文字列に変換
	static wstring ConvertMultiByteStringToWideString(const string& mString);

public:
	//テクスチャをWICからDDSに変換する
	void ConverterTextureWICToDDS(const string& filePath);
};