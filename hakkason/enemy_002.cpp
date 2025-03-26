//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_002.h"
#include "bullet.h"
#include "enemy_002_state.h"

//�ÓI�����o�̏�����
const std::string CEnemy_002::FILEPATH = "data\\motion_enemy002.txt";

//================================
// �R���X�g���N�^
//================================
CEnemy_002::CEnemy_002(int nPriority) :CEnemy(nPriority),
m_pState(nullptr)
{
}

//================================
// �f�X�g���N�^
//================================
CEnemy_002::~CEnemy_002()
{
	if (m_pState != nullptr)
	{
		delete m_pState;
	}
}

//================================
// ������
//================================
HRESULT CEnemy_002::Init()
{
	//������
	CGame_Character::Init();

	//�{�X�̃X�e�[�g����
	if (m_pState == nullptr)
	{
		//�ŏ��͜p�j���
		m_pState = new CEnemy_002_Shot;
	}

	SetShotFrame(SHOT_FRAME);

	//���[�V�����̓ǂݍ���
	SetMotionInfo(FILEPATH.c_str());

	//���̃��C�t�ݒ�
	SetLife(LIFE);

	return S_OK;
}

//================================
// �I��
//================================
void CEnemy_002::Uninit()
{
	//�I��
	CGame_Character::Uninit();
}

//================================
// �X�V
//================================
void CEnemy_002::Update()
{
	//�X�V
	CEnemy::Update();

	if (m_pState != nullptr)
	{
		m_pState->Move(this);
		m_pState->Shot(this);
	}
}

//================================
// �`��
//================================
void CEnemy_002::Draw()
{
	//�L�����N�^�[�N���X�̕`��
	CCharacter::Draw();
}

//============================
//�e����
//============================
void CEnemy_002::ShotBullet()
{
	LockAtPlayer();

	int nCnt = GetShotFrameCnt();
	++nCnt;

	if (nCnt > GetShotFrame())
	{
		nCnt = 0;

		CBullet::Create(GetPos(), GetRot().y + QRTR_PI + D3DX_PI, 1.0f, false);
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, false);
		CBullet::Create(GetPos(), GetRot().y - QRTR_PI + D3DX_PI, 1.0f, false);
	}
	SetShotFrameCnt(nCnt);

}
