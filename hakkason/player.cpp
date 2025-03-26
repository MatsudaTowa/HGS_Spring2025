//======================================
//
//	�v���C���[�̏���[player.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "player.h"
#include "manager.h"
#include "game.h"
#include "modelparts.h"
#include "camera.h"
#include "bullet.h"
#include "gamemanager.h"

//�ÓI�����o�̏�����
const std::string CPlayer::FILEPATH = "data\\MODEL\\player001.x";

//============================
//�v���C���[�̃R���X�g���N�^
//============================
CPlayer::CPlayer(int nPriority) : CGame_Character(nPriority),
m_nAttackCoolTime(0),	//�U���̃N�[���^�C��
m_nAttackTrrigerCount(0)//�U�������̃J�E���g
{

}

//============================
//�v���C���[�̃f�X�g���N�^
//============================
CPlayer::~CPlayer()
{

}

//============================
//�v���C���[�̏�����
//============================
HRESULT CPlayer::Init()
{
	//������
	CGame_Character::Init();

	//�p�����[�^�̏�����
	CCharacter::SetRot({ 0.0f, 0.0f, 0.0f });
	CCharacter::SetPos({ 0.0f, 0.0f, 0.0f });
	CCharacter::SetGoalRot({ 0.0f, D3DX_PI, 0.0f });

	//���[�V�����̓ǂݍ���
	SetMotionInfo("data\\playermotion000.txt");

	//���̃��C�t�ݒ�
	SetLife(MAX_LIFE);

	return S_OK;
}

//============================
//�v���C���[�̏I������
//============================
void CPlayer::Uninit()
{
	//������
	CGame_Character::Uninit();
}

//============================
//�v���C���[�̍X�V
//============================
void CPlayer::Update()
{
	//�N�[���^�C���̍X�V
	UpdateCoolTime();

	//����̏���
	UpdateOperation();

	//���ʏ����̍X�V
	CGame_Character::Update();
}

//============================
//����̍X�V
//============================
void CPlayer::UpdateOperation()
{
	//�m�F
	if (m_nAttackCoolTime > 0) return;

	Move();

	Attack();
}

//============================
//�ړ�����
//============================
void CPlayer::Move()
{
	//����p
	bool bPressKey = false;
	CCamera* pCamera = CManager::GetInstance()->GetCamera();
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 Rotgoal = GetGoalRot();

	if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_A))
	{//A�L�[�������ꂽ�ꍇ
		if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
		{
			move.x += sinf(D3DX_PI * -0.75f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * -0.75f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * 0.75f/* + pCamera->GetRot().y*/;
		}
		else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
		{
			move.x += sinf(D3DX_PI * -0.25f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * -0.25f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * 0.25f/* + pCamera->GetRot().y*/;
		}
		else
		{
			move.x += sinf(D3DX_PI * -0.5f + pCamera->GetRot().y) * 1.0f;
			move.z += cosf(D3DX_PI * -0.5f + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = -(D3DX_PI * -0.5f/* - pCamera->GetRot().y*/);
		}

		bPressKey = true;	//�L�[�{�[�h��G���Ă���
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_D))
	{//D�L�[�������ꂽ�ꍇ

		if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
		{
			move.x += sinf(D3DX_PI * 0.75f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * 0.75f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * -0.75f/* + pCamera->GetRot().y*/;
		}
		else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
		{
			move.x += sinf(D3DX_PI * 0.25f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * 0.25f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * -0.25f/* + pCamera->GetRot().y*/;
		}
		else
		{
			move.x += sinf(D3DX_PI * 0.5f + pCamera->GetRot().y) * 1.0f;
			move.z += cosf(D3DX_PI * 0.5f + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = -(D3DX_PI * 0.5f/* - pCamera->GetRot().y*/);
		}

		bPressKey = true;	//�L�[�{�[�h��G���Ă���
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
	{//W�L�[�������ꂽ�ꍇ
		{
			move.z -= cosf(D3DX_PI + pCamera->GetRot().y) * 1.0f;
			move.x -= sinf(D3DX_PI + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI/* + pCamera->GetRot().y*/;
		}

		bPressKey = true;	//�L�[�{�[�h��G���Ă���
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
	{//S�L�[�������ꂽ�ꍇ
		{
			move.z -= cosf(pCamera->GetRot().y) * 1.0f;
			move.x -= sinf(pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = pCamera->GetRot().y;
		}

		bPressKey = true;	//�L�[�{�[�h��G���Ă���
	}

	SetMove(move);
	SetGoalRot(Rotgoal);

	//���[�V������ݒ�
	if (bPressKey)
	{
		if (GetMotionState() != CPlayer::PLAYERMOTION_WALK)
		{
			SetMotion(CPlayer::PLAYERMOTION_WALK);
		}
	}
	else
	{
		if (GetMotionState() != CPlayer::PLAYERMOTION_NORMAL)
		{
			SetMotion(CPlayer::PLAYERMOTION_NORMAL);
		}
	}
}

//============================
//�U������
//============================
void CPlayer::Attack()
{
	//�U������������
	if (CManager::GetInstance()->GetMouse()->GetTrigger(CInputMouse::MOUSEBUTTON_LEFT))
	{
		SetMotion(CPlayer::PLAYERMOTION_ACTION);	//���[�V�����ݒ�
		m_nAttackCoolTime = ATTACK_COOLTIME;		//�N�[���^�C����ݒ�
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, true);
	}
}

//============================
//�N�[���^�C���̍X�V
//============================
void CPlayer::UpdateCoolTime()
{
	//�N�[���^�C�������炷
	if (m_nAttackCoolTime <= 0) return;

	m_nAttackTrrigerCount++;

	if (m_nAttackTrrigerCount == ATTACK_TRRIGER)
	{
		//�o���b�g���X�g
		std::list<CBullet*> BulletList = CGameManager::GetInstance()->GetBulletManager()->GetList();

		for (auto& iter : BulletList)
		{
			float fXZ = sqrtf((iter->GetPos().x - GetPos().x) * (iter->GetPos().x - GetPos().x) + (iter->GetPos().z - GetPos().z) * (iter->GetPos().z - GetPos().z)); //�������Z�o����


			if (fXZ <= 30.0f && !iter->GetPlayerBullet())
			{
				iter->GetSpeed() *= -1.0f;
			}
		}
	}

	m_nAttackCoolTime--;

	if (m_nAttackCoolTime <= 0) m_nAttackTrrigerCount = 0;
}

//============================
//�_���[�W���̏���
//============================
bool CPlayer::SetDamage(int damage)
{
	//�_���[�W���󂯂�
	SetLife(GetLife() - damage);

	//�_���[�W�̐ݒ�
	return true;
}

//============================
//�v���C���[�̕`��
//============================
void CPlayer::Draw()
{
	//�L�����N�^�[�N���X�̕`��
	CCharacter::Draw();
}

//============================
//�v���C���[�̃N���G�C�g
//============================
CPlayer* CPlayer::Create()
{
	//�|�C���^�p�̕ϐ�
	CPlayer* pPlayer;

	//�������̊m��
	pPlayer = new CPlayer;

	//������
	pPlayer->Init();

	return pPlayer;
}