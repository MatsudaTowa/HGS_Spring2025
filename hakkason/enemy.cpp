//======================================
//
//	�G�l�~�[�̏���[enemy.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"
#include "gamemanager.h"
#include "enemy_000.h"
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

	//�}�l�[�W���[�̃C���X�^���X���擾
	CManager* pManager = CManager::GetInstance();

	++m_ShotFrame_Cnt;

	if (m_ShotFrame_Cnt > m_ShotFrame)
	{
		m_ShotFrame_Cnt = 0;
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f);
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