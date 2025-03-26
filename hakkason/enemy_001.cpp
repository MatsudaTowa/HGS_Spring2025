//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_001.h"

//�ÓI�����o�̏�����
const std::string CEnemy_001::FILEPATH = "data\\motion_enemy001.txt";

//================================
// �R���X�g���N�^
//================================
CEnemy_001::CEnemy_001(int nPriority) :CEnemy(nPriority)
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
