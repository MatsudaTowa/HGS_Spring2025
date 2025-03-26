//================================
//
//gamemanager.cpp�ɕK�v�Ȑ錾[gamemanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAMEMANAGER_H_ //���̃}�N����`������Ă��Ȃ�������
#define _GAMEMANAGER_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "enemymanager.h"
#include "bulletmanager.h"

//�}�l�[�W���[�N���X
class CGameManager
{

private:

	//�����o�֐�
	CGameManager();								//�R���X�g���N�^

public:

	//�����o�֐�
	~CGameManager();						//�f�X�g���N�^
	void Init();							//������
	void Uninit();							//�I������

	//�C���X�^���X�̐���
	static CGameManager* GetInstance()
	{
		static CGameManager instance;	//�ÓI�C���X�^���X
		return &instance;
	}

	CEnemyManager* GetEnemyManager() { return m_pEnemyManager; }	//�G�l�~�[�}�l�[�W���[�̎擾
	CBulletManager* GetBulletManager() { return m_pBulletmanager; }	//�o���b�g�}�l�[�W���[�̎擾

private:

	//�ϐ�
	CEnemyManager* m_pEnemyManager;
	CBulletManager* m_pBulletmanager;
};

#endif