//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_002.h"

//�ÓI�����o�̏�����
const std::string CEnemy_002::FILEPATH = "data\\motion_enemy002.txt";

//================================
// �R���X�g���N�^
//================================
CEnemy_002::CEnemy_002(int nPriority) :CEnemy(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CEnemy_002::~CEnemy_002()
{
}

//================================
// ������
//================================
HRESULT CEnemy_002::Init()
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
}

//================================
// �`��
//================================
void CEnemy_002::Draw()
{
	//�L�����N�^�[�N���X�̕`��
	CCharacter::Draw();
}
