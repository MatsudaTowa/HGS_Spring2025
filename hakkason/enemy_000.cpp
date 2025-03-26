//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_000.h"

//�ÓI�����o�̏�����
const std::string CEnemy_000::FILEPATH = "data\\motion_enemy000.txt";

//================================
// �R���X�g���N�^
//================================
CEnemy_000::CEnemy_000(int nPriority):CEnemy(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CEnemy_000::~CEnemy_000()
{
}

//================================
// ������
//================================
HRESULT CEnemy_000::Init()
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
void CEnemy_000::Uninit()
{
	//�I��
	CGame_Character::Uninit();
}

//================================
// �X�V
//================================
void CEnemy_000::Update()
{
	//�X�V
	CEnemy::Update();
}

//================================
// �`��
//================================
void CEnemy_000::Draw()
{
	//�L�����N�^�[�N���X�̕`��
	CCharacter::Draw();
}
