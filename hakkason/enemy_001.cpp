//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_001.h"
#include "bullet.h"
#include "manager.h"

//�ÓI�����o�̏�����
const std::string CEnemy_001::FILEPATH = "data\\motion_enemy001.txt";

//================================
// �R���X�g���N�^
//================================
CEnemy_001::CEnemy_001(int nPriority) :CEnemy(nPriority),
m_nBurstDelayCnt(0),
m_nShotBullet(0)
{
}

//================================
// �f�X�g���N�^
//================================
CEnemy_001::~CEnemy_001()
{
}

//================================
// ������
//================================
HRESULT CEnemy_001::Init()
{
	//������
	CGame_Character::Init();

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
void CEnemy_001::Uninit()
{
	//�I��
	CGame_Character::Uninit();
}

//================================
// �X�V
//================================
void CEnemy_001::Update()
{
	//�X�V
	CEnemy::Update();
	ShotBullet();

}

//================================
// �`��
//================================
void CEnemy_001::Draw()
{
	//�L�����N�^�[�N���X�̕`��
	CCharacter::Draw();
}

//================================
// ���ˏ���
//================================
void CEnemy_001::ShotBullet()
{
	LockAtPlayer();

	int nCnt = GetShotFrameCnt();
	++nCnt;

	if (nCnt > GetShotFrame())
	{
		++m_nBurstDelayCnt;
		if (m_nBurstDelayCnt > BURST_DELAY_FRAME)
		{
			CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SHOT);

			m_nBurstDelayCnt = 0;
			CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, false);
			++m_nShotBullet;
			if (m_nShotBullet >= NUM_SHOT)
			{
				m_nShotBullet = 0;
				nCnt = 0;
			}
		}

	}
	SetShotFrameCnt(nCnt);
}
