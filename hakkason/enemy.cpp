//======================================
//
//	�G�l�~�[�̏���[enemy.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"
#include "player.h"
#include "gamemanager.h"
#include "enemy_000.h"
#include "enemy_001.h"
#include "enemy_002.h"
#include "manager.h"

//============================
//�G�l�~�[�̃R���X�g���N�^
//============================
CEnemy::CEnemy(int nPriority) :
	CGame_Character(nPriority),	//�e�̃R���X�g���N�^
	m_ShotFrame(0),				//���˃t���[��
	m_ShotFrame_Cnt(0)			//���˃J�E���g
{
	//�}�l�[�W���[�ɓo�^
	CGameManager::GetInstance()->GetEnemyManager()->Regist(this);

	CGame_Character::GetCollision()->SetRadius(13.0f);
}

//============================
//�G�l�~�[�̃f�X�g���N�^
//============================
CEnemy::~CEnemy()
{
	//�}�l�[�W���[����폜
	if (CGameManager::GetInstance()->GetEnemyManager() != nullptr)
	{
		CGameManager::GetInstance()->GetEnemyManager()->Erase(this);
	}
}

//============================
//�G�l�~�[�̏�����
//============================
HRESULT CEnemy::Init()
{
	//������
	CGame_Character::Init();

	return S_OK;
}

//============================
//�G�l�~�[�̏I������
//============================
void CEnemy::Uninit()
{
	//���S�t���O�������Ă����甲����
	if (GetDeath())
	{
		return;
	}

	//������
	CCharacter::Uninit();
}

//============================
//�G�l�~�[�̍X�V
//============================
void CEnemy::Update()
{
	//���ʏ����̍X�V
	CGame_Character::Update();

	LockAtPlayer();

	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	++m_ShotFrame_Cnt;

	if (m_ShotFrame_Cnt > m_ShotFrame)
	{
		m_ShotFrame_Cnt = 0;
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, false);
	}

#ifdef _DEBUG
	if (pManager->GetKeyboard()->GetTrigger(DIK_TAB))
	{
		SetDamage(1);
	}

#endif // _DEBUG
}

//============================
//�G�l�~�[�̕`��
//============================
void CEnemy::Draw()
{
	CGame_Character::Draw();
}

//============================
//�G�l�~�[�̃N���G�C�g
//============================
CEnemy* CEnemy::Create(D3DXVECTOR3 pos, ENEMY_TYPE type)
{
	//��ނɉ����ē��I�m��
	CEnemy* pEnemy = nullptr;

	switch (type)
	{
	case CEnemy::ENEMY_000:
		pEnemy = new CEnemy_000;
		break;
	case CEnemy::ENEMY_001:
		pEnemy = new CEnemy_001;
		break;
	case CEnemy::ENEMY_002:
		pEnemy = new CEnemy_002;
		break;
	default:
		assert("�͈͊O�̃G�l�~�[�^�C�v�ł�");
		break;
	}

	//�ʒu�̐ݒ�
	pEnemy->SetPos(pos);

	//������
	pEnemy->Init();

	//�ݒ肵������Ԃ�
	return pEnemy;
}

//============================
//�_���[�W�̐ݒ�
//============================
bool CEnemy::SetDamage(int damage)
{
	//�_���[�W�̐ݒ�
	CGame_Character::SetDamage(damage);

	return true;
}

//============================
//�v���C���[�̂ق�������
//============================
void CEnemy::LockAtPlayer()
{
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//�v���C���[�Ƃ̋����Z�o
	D3DXVECTOR3 Distance = pPlayer->GetPos() - GetPos();

	//�v���C���[�Ɍ�����p�x���Z�o
	float fAngle = atan2f(Distance.x, Distance.z);

	//�e�N���X����rot���擾
	D3DXVECTOR3 rot = GetRot();

	rot.y = fAngle + D3DX_PI;

	SetRot(rot);
}
