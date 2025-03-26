//======================================
//
//	���U���g�̏���[result.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "result.h"
#include "manager.h"
#include "camera_result.h"
#include "cleartime.h"

//�萔
const D3DXVECTOR3 CResult::TIME_POS = { SCREEN_WIDTH * 0.4f, 355.0f, 0.0f };

//============================
//���U���g�̃R���X�g���N�^
//============================
CResult::CResult()
{
	
}

//============================
//���U���g�̃f�X�g���N�^
//============================
CResult::~CResult()
{
	//�t�H�O�̐ݒ�
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//���U���g�̏�����
//============================
HRESULT CResult::Init()
{
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_RESULT);

	//�J������؂�ւ�
	CManager::GetInstance()->ChangeCamera(new CCamera_Result());

	//�N���A�^�C���̏�����
	CClearTime::GetInstance()->SetPos(TIME_POS);
	CClearTime::GetInstance()->Init();
	
	return S_OK;
}

//============================
//���U���g�̏I������
//============================
void CResult::Uninit()
{
	CManager::GetInstance()->GetSound()->Stop();	//�I������

	//�I������
	CScene::Uninit();
}

//============================
//���U���g�̍X�V����
//============================
void CResult::Update()
{
	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	//�t�F�[�h���I����Ă�����X�V
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//�G���^�[�ŉ�ʑJ��
		if (pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//�^�C�g���ɉ�ʑJ��
			pManager->GetFade()->SetFade(CScene::MODE_TITLE);
		}
	}
}

//============================
//���U���g�̕`�揈��
//============================
void CResult::Draw()
{

}