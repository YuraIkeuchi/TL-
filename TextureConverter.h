#pragma once
#include "string"
#include <d3dx12.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;
using namespace std;         //  名前空間指定
//テクスチャコンバーター
class TextureConverter {
public:
	//使用方法を出力する
	static void OutPutUsage();
private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const string& filePath);
	//マルチバイト文字列をワイド文字列に変換
	static wstring ConvertMultiByteStringToWideString(const string& mString);
	//フォルダパスとファイル名を分離する
	void SeparateFilePath(wstring& filePath);
	//DDSテクスチャとしてファイル書き出し
	void SaveDDSTextureToFile(int numOptions, char* options[]);

public:
	//テクスチャをWICからDDSに変換する
	void ConverterTextureWICToDDS(const string& filePath,int numOptions = 0,char* options[] = nullptr);

	//メンバ変数
private:

	//画像の取得
	TexMetadata metadata_;
	//画像のイメージコンテナ
	ScratchImage scratchImage_;

	//ディレクトリパス
	wstring directoryPath_;
	//ファイル名
	wstring fileName_;
	//ファイル拡張子
	wstring fileExt_;
};