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
	if (argc < NumArgment) {
		TextureConverter::OutPutUsage();
		return 0;
	}
	assert(argc >= NumArgment);

	//Com���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^�[
	TextureConverter converter;
	//�I�v�V�����̐�
	int numOption = argc - NumArgment;
	//�I�v�V�����z��
	char** options = argv + NumArgment;


	//�e�N�X�`���ϊ�
	converter.ConverterTextureWICToDDS(argv[kFilePath],numOption,options);

	//COM���C�u�����̏I��
	CoUninitialize();
	//system("pause");
	return 0;
}