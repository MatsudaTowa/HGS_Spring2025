//======================================
//
//	�^�C�g���̏���[gameover.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "gameover.h"
#include "manager.h"
#include "gameover_bg.h"

//============================
//�^�C�g���̃R���X�g���N�^
//============================
CGameover::CGameover()
{

}

//============================
//�^�C�g���̃f�X�g���N�^
//============================
CGameover::~CGameover()
{
	//�t�H�O�̐ݒ�
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//�^�C�g���̏�����
//============================
HRESULT CGameover::Init()
{
	CGameOver_Bg::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_GAMEOVER);

	return S_OK;
}

//============================
//�^�C�g���̏I������
//============================
void CGameover::Uninit()
{
	CManager::GetInstance()->GetSound()->Stop();	//�I������

	//�I������
	CScene::Uninit();
}

//============================
//�^�C�g���̍X�V����
//============================
void CGameover::Update()
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
			pManager->GetFade()->SetFade(CScene::MODE_TITLE);
		}
	}
}

//============================
//�^�C�g���̕`�揈��
//============================
void CGameover::Draw()
{

}