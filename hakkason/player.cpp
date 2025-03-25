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

//�ÓI�����o�̏�����
const std::string CPlayer::FILEPATH = "data\\MODEL\\player001.x";

//============================
//�v���C���[�̃R���X�g���N�^
//============================
CPlayer::CPlayer(int nPriority) : CGame_Character(nPriority)
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
	//���ʏ����̍X�V
	CGame_Character::Update();
}

//============================
//�_���[�W���̏���
//============================
bool CPlayer::SetDamage(int damage, float angle)
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