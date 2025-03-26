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
	m_bPause(false)		//�|�[�Y����
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

	CEnemy::Create({VEC3_RESET_ZERO}, CEnemy::ENEMY_000);
	CPlayer::Create();
	CField::Create();
	
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