//======================================
//
//	�Q�[���̏���[game.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "game.h"
#include "manager.h"
#include "camera_game.h"
#include "player.h"
#include "field.h"
#include "enemy.h"
#include "gamemanager.h"

//�萔
const D3DXVECTOR3 CGame::TIME_POS = { SCREEN_WIDTH * 0.4f, 50.0f, 0.0f };
const std::string CGame::FILEPATH_MODEL = "data\\FILE\\model.bin";

//============================
//�Q�[���̃R���X�g���N�^
//============================
CGame::CGame() :
	m_bClear(false),	//�N���A����
	m_bPause(false),	//�|�[�Y����
	m_next_wave(),		//���̃E�F�[�u�i�[�ϐ�
	m_pWave(nullptr)	//�E�F�[�u
{
	CGameManager::GetInstance()->Init();
}

//============================
//�Q�[���̃f�X�g���N�^
//============================
CGame::~CGame()
{
	//�t�H�O�̐ݒ�
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	CGameManager::GetInstance()->Uninit();
}

//============================
//�Q�[���̏�����
//============================
HRESULT CGame::Init()
{
	//�J������؂�ւ�
	CManager::GetInstance()->ChangeCamera(new CCamera_Game());

	CPlayer::Create();
	CField::Create();

	SetWave(CWave::WAVE::ONE);

	return S_OK;
}

//============================
//�Q�[���̏I������
//============================
void CGame::Uninit()
{
	//�I������
	CScene::Uninit();
}

//============================
//�Q�[���̍X�V����
//============================
void CGame::Update()
{
	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	if (CGameManager::GetInstance()->GetEnemyManager()->GetList().size() <= 0)
	{
		switch (m_pWave->GetCurrentWave())
		{
		case CWave::WAVE::ONE:
			m_next_wave = CWave::WAVE::TWO;
			break;
		case CWave::WAVE::TWO:
			m_next_wave = CWave::WAVE::THREE;
			break;
		case CWave::WAVE::THREE:
			m_next_wave = CWave::WAVE::NONE;
			break;
		default:
			assert("�͈͊O�̃E�F�[�u�ł�");
			break;
		}

		if (m_next_wave != CWave::WAVE::NONE)
		{
			SetWave(m_next_wave);
		}
		else if (m_next_wave == CWave::WAVE::NONE)
		{
			//�}�l�[�W���[�̃C���X�^���X���擾
			CManager* pManager = CManager::GetInstance();

			//���U���g�ɉ�ʑJ��
			pManager->GetFade()->SetFade(CScene::MODE_RESULT);
		}
	}

	if (m_pWave != nullptr)
	{
		m_pWave->Update();
	}
}

//============================
//�Q�[���̕`�揈��
//============================
void CGame::Draw()
{

}

//============================
//�Q�[���̓ǂݍ���
//============================
void CGame::Load()
{

}

//============================
//�|�[�Y�̐ݒ�
//============================
void CGame::SetPause()
{
	m_bPause = m_bPause ? false : true;
}
