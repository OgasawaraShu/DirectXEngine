#pragma once



#include <windows.h>
#include<wrl.h>
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800//DirectInput�̃o�[�W�����w��
#include<dinput.h>

#pragma comment (lib, "xinput.lib")
#include <xinput.h>


//����
class Input
{
public:
	//namespace�ȗ�
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public://�����o�֐�
    //������
	void Intialize(WinApp* winApp);
	//�X�V
	void Update();

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

//	�Q�[���p�b�h

	void PadUpdate();

	
	//XINPUT_STATE state;

	//XINPUT_VIBRATION vibration;

private://�����o�ϐ�
	//�L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> devkeyboard;
	//�Q�[���p�b�h
	//DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> dinput;
	//�Q�[���p�b�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> gamepad;


	//�S�L�[�̏��
	BYTE key[256] = {};
	//�O��̑S�L�[�̏��
	BYTE oldkey[256] = {};
	//�p�b�h

private:
	//WindowsAPI
	WinApp* winApp = nullptr;

};

