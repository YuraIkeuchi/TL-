#include <cstdio>
#include <cstdlib>
#include "TextureConverter.h"
#include <cassert>
#include "Windows.h"
//�R�}���h���C������
enum Argment {
	kApplicationPath,//�A�v���P�[�V�����̃p�X
	kFilePath,//�n���ꂽ�t�@�C���̃p�X

	NumArgment
};

int main(int argc, char* argv[]) {
	/*for (int i = 0; i < argc; i++) {
		printf(argv[i]);
		printf("\n");
	}*/
	assert(argc >= NumArgment);

	//Com���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^�[
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConverterTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();
	system("pause");
	return 0;
}