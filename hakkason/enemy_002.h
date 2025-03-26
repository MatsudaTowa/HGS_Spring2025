//================================
//
//enemy_002.cpp�ɕK�v�Ȑ錾[enemy_001.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_002_H_ //���̃}�N����`������Ă��Ȃ�������
#define _ENEMY_002_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"

//=============================================
//�O���錾
//=============================================
class CEnemy_002_State;

//�G�l�~�[�N���X
class CEnemy_002 : public CEnemy
{
public:

	//�����o�֐�
	CEnemy_002(int nPriority = 3);	//�R���X�g���N�^
	~CEnemy_002() override;			//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��

	void ShotBullet()override;

	void ChangeState(CEnemy_002_State* state)
	{
		//���̃X�e�[�g�����������̃X�e�[�g�ɐ؂�ւ���
		if (m_pState != nullptr)
		{
			delete m_pState;
			m_pState = state;
		}
	}

	CEnemy_002_State* m_pState;
private:
	static const int LIFE = 30;
	static const int SHOT_FRAME = 220;
	static constexpr float SPEED = 1.0f;
	static const std::string FILEPATH;					//�ǂݍ��ރt�@�C��
};

#endif