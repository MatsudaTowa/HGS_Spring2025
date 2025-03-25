//======================================
//
//	�G�l�~�[�̏���[enemy.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"
#include "gamemanager.h"

//============================
//�G�l�~�[�̃R���X�g���N�^
//============================
CEnemy::CEnemy(int nPriority) : 
	CGame_Character(nPriority)	//�e�̃R���X�g���N�^
{
	//�}�l�[�W���[�ɓo�^
	CGameManager::GetInstance()->GetEnemyManager()->Regist(this);
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
CEnemy* CEnemy::Create(D3DXVECTOR3 pos)
{
	//��ނɉ����ē��I�m��
	CEnemy* pEnemy = nullptr;

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
bool CEnemy::SetDamage(int damage, float angle)
{
	//�_���[�W�̐ݒ�
	CGame_Character::SetDamage(damage, angle);

	return true;
}