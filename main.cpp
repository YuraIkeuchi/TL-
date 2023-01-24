#include <cstdio>
#include <cstdlib>
#include "TextureConverter.h"
#include <cassert>
#include "Windows.h"
//コマンドライン引数
enum Argment {
	kApplicationPath,//アプリケーションのパス
	kFilePath,//渡されたファイルのパス

	NumArgment
};

int main(int argc, char* argv[]) {
	/*for (int i = 0; i < argc; i++) {
		printf(argv[i]);
		printf("\n");
	}*/
	assert(argc >= NumArgment);

	//Comライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバーター
	TextureConverter converter;

	//テクスチャ変換
	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();
	system("pause");
	return 0;
}