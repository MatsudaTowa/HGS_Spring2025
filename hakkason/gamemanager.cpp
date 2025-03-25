//======================================
//
//	�Q�[���}�l�[�W���[�̏���[manager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "gamemanager.h"

//============================
//�R���X�g���N�^
//============================
CGameManager::CGameManager() :
	m_pEnemyManager(nullptr)	//�Q�[���}�l�[�W���[
{

}

//============================
//�f�X�g���N�^
//============================
CGameManager::~CGameManager()
{

}

//============================
//����������
//============================
void CGameManager::Init()
{
	//�t�F�[�h�̐���
	m_pEnemyManager = new CEnemyManager();		//�������m��
	m_pEnemyManager->Init();					//�����ݒ�
}

//============================
//�I������
//============================
void CGameManager::Uninit()
{
	//�G�l�~�[�}�l�[�W���[�̔j��
	if (m_pEnemyManager != nullptr)
	{
		//�I��������ɊJ��
		m_pEnemyManager->Uninit();
		delete m_pEnemyManager;
		m_pEnemyManager = nullptr;
	}
}