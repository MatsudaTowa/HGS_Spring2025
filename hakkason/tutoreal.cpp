//======================================
//
//	�^�C�g���̏���[title.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "tutorial.h"
#include "manager.h"
#include "tutorial_screen.h"

//============================
//�^�C�g���̃R���X�g���N�^
//============================
CTutorial::CTutorial()
{

}

//============================
//�^�C�g���̃f�X�g���N�^
//============================
CTutorial::~CTutorial()
{
	//�t�H�O�̐ݒ�
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//�^�C�g���̏�����
//============================
HRESULT CTutorial::Init()
{
	CTutorialScreen::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_GAME);
	return S_OK;
}

//============================
//�^�C�g���̏I������
//============================
void CTutorial::Uninit()
{
	CScene::Uninit();
}

//============================
//�^�C�g���̍X�V����
//============================
void CTutorial::Update()
{
	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	//�t�F�[�h���I����Ă�����X�V
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//�G���^�[�ŉ�ʑJ��
		if (pManager->GetMouse()->GetTrigger((CInputMouse::MOUSEBUTTON_LEFT)) || pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//�Q�[���ɉ�ʑJ��
			pManager->GetFade()->SetFade(CScene::MODE_GAME);
		}
	}
}

//============================
//�^�C�g���̕`�揈��
//============================
void CTutorial::Draw()
{

}