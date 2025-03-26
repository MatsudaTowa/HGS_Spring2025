//======================================
//
//	�^�C�g���̏���[title.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "title.h"
#include "manager.h"
#include "title_screen.h"

//============================
//�^�C�g���̃R���X�g���N�^
//============================
CTitle::CTitle()
{
	
}

//============================
//�^�C�g���̃f�X�g���N�^
//============================
CTitle::~CTitle()
{
	//�t�H�O�̐ݒ�
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//�^�C�g���̏�����
//============================
HRESULT CTitle::Init()
{
	CTitleScreen::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_TITLE);
	return S_OK;
}

//============================
//�^�C�g���̏I������
//============================
void CTitle::Uninit()
{
	CManager::GetInstance()->GetSound()->Stop();	//�I������
	CScene::Uninit();
}

//============================
//�^�C�g���̍X�V����
//============================
void CTitle::Update()
{
	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	//�t�F�[�h���I����Ă�����X�V
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//�G���^�[�ŉ�ʑJ��
		if (pManager->GetMouse()->GetTrigger((CInputMouse::MOUSEBUTTON_LEFT))||pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//�Q�[���ɉ�ʑJ��
			pManager->GetFade()->SetFade(CScene::MODE_TUORIAL);
		}
	}
}

//============================
//�^�C�g���̕`�揈��
//============================
void CTitle::Draw()
{
}

