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
#include "effect_hit.h"

//�ÓI�����o�̏�����
const std::string CPlayer::FILEPATH = "data\\MODEL\\player001.x";

//============================
//�v���C���[�̃R���X�g���N�^
//============================
CPlayer::CPlayer(int nPriority) : CGame_Character(nPriority),
	m_nAttackCoolTime(0),		//�U���̃N�[���^�C��
	m_nAttackTrrigerCount(0),	//�U�������̃J�E���g
	m_pLifeGauge(nullptr)		//�̗̓Q�[�W�̃|�C���^
{
	CGame_Character::GetCollision()->SetRadius(13.0f);
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
	CCharacter::SetPos({ 0.0f, 0.0f, -100.0f });
	CCharacter::SetGoalRot({ 0.0f, D3DX_PI, 0.0f });

	//���[�V�����̓ǂݍ���
	SetMotionInfo("data\\playermotion000.txt");

	//�Q�[�W�̐���
	if (m_pLifeGauge == nullptr)
	{
		m_pLifeGauge = CGauge_PlayerLife::Create(MAX_LIFE);
	}

	//���̃��C�t�ݒ�
	SetLife(MAX_LIFE);

	CGameManager::GetInstance()->SetPlayer(this);

	return S_OK;
}

//============================
//�v���C���[�̏I������
//============================
void CPlayer::Uninit()
{
	//������
	CGame_Character::Uninit();

	//�Q�[�W�̏���
	if (m_pLifeGauge != nullptr)
	{
		m_pLifeGauge->Uninit();
		m_pLifeGauge = nullptr;
	}
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
	Collision();

	//�m�F
	if (m_nAttackCoolTime > 0) return;

	Move();

	Attack();

	Limit();
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
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SWING);

		SetMotion(CPlayer::PLAYERMOTION_ACTION);	//���[�V�����ݒ�
		m_nAttackCoolTime = ATTACK_COOLTIME;		//�N�[���^�C����ݒ�
		//CBullet::Create(GetPos(), GetGoalRot().y + D3DX_PI, 1.0f, true);
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

		//�U������̐���
		D3DXVECTOR3 AttackPos = GetPos();
		AttackPos += {sinf(GetRot().y + D3DX_PI)* 5.0f, 0.0f, cosf(GetRot().y + D3DX_PI)* 5.0f};

		for (auto& iter : BulletList)
		{
			float fXZ = sqrtf((iter->GetPos().x - AttackPos.x) * (iter->GetPos().x - AttackPos.x) + (iter->GetPos().z - AttackPos.z) * (iter->GetPos().z - AttackPos.z)); //�������Z�o����


			if (fXZ <= 45.0f && !iter->GetPlayerBullet())
			{
				CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_REFRECT);

				iter->GetSpeed() *= -1.3f;
				iter->GetHansya()++;
			}
		}
	}

	m_nAttackCoolTime--;

	if (m_nAttackCoolTime <= 0) m_nAttackTrrigerCount = 0;
}

//============================
//����
//============================
void CPlayer::Limit()
{
	if (GetPos().z > -100.0f)
	{
		GetPos().z = -100.0f;
	}

	if (GetPos().z < -150.0f)
	{
		GetPos().z = -150.0f;
	}

	if (GetPos().x + GetCollision()->GetRadius() > 150.0f)
	{
		GetPos().x = 150.0f - GetCollision()->GetRadius();
	}

	if (GetPos().x - GetCollision()->GetRadius() < -150.0f)
	{
		GetPos().x = -150.0f + GetCollision()->GetRadius();
	}
}

//============================
//�����蔻��
//============================
void CPlayer::Collision()
{
	//�o���b�g���X�g
	std::list<CBullet*> BulletList = CGameManager::GetInstance()->GetBulletManager()->GetList();

	for (auto& iter : BulletList)
	{
		float fXZ = sqrtf((iter->GetPos().x - GetPos().x) * (iter->GetPos().x - GetPos().x) + (iter->GetPos().z - GetPos().z) * (iter->GetPos().z - GetPos().z)); //�������Z�o����

		if (fXZ <= 15.0f && !iter->GetPlayerBullet())
		{
			CEffect_Hit::Create({ GetPos().x, 5.0f,  GetPos().z });
			iter->Uninit();
			SetDamage(1);
		}
	}
}

//============================
//�_���[�W���̏���
//============================
bool CPlayer::SetDamage(int damage)
{
	//�̗͂��Ȃ��Ȃ�X�V���Ȃ�
	if (GetLife() <= 0)
	{
		return false;
	}

	//���S�t���O�������Ă����甲����
	if (GetDeath())
	{
		return true;
	}

	//�_���[�W���󂯂�
	SetLife(GetLife() - damage);

	//�C���X�^���X�̎擾
	CGauge_PlayerLife* pGauge = GetLifeGauge();

	//�̗̓Q�[�W�ɔ��f
	if (pGauge != nullptr)
	{
		//�Q�[�W�ɔ��f
		pGauge->GetGauge()->AddGauge(-(float)damage);
	}

	//�̗̓Q�[�W��ݒ�
	SetLifeGauge(pGauge);

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