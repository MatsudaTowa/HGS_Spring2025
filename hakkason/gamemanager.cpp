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
	m_pEnemyManager(nullptr),	//�G�l�~�[�}�l�[�W���[
	m_pBulletmanager(nullptr),	//�o���b�g�}�l�[�W���[
	m_pBlockManager(nullptr)	//�u���b�N�}�l�[�W���[
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
	//�G�l�~�[�}�l�[�W���[�̐���
	m_pEnemyManager = new CEnemyManager();		//�������m��
	m_pEnemyManager->Init();					//�����ݒ�

	//�o���b�g�}�l�[�W���[����
	m_pBulletmanager = new CBulletManager();	//�������m��
	m_pBulletmanager->Init();					//�����ݒ�

	//�u���b�N�}�l�[�W���[����
	m_pBlockManager = new CBlockManager();		//�������m��
	m_pBlockManager->Init();					//�����ݒ�
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

	//�G�l�~�[�}�l�[�W���[�̔j��
	if (m_pBulletmanager != nullptr)
	{
		//�I��������ɊJ��
		m_pBulletmanager->Uninit();
		delete m_pBulletmanager;
		m_pBulletmanager = nullptr;
	}

	//�G�l�~�[�}�l�[�W���[�̔j��
	if (m_pBlockManager != nullptr)
	{
		//�I��������ɊJ��
		m_pBlockManager->Uninit();
		delete m_pBlockManager;
		m_pBlockManager = nullptr;
	}
}