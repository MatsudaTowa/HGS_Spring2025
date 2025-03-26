//======================================
//
//	�e�̊Ǘ������鏈��[bulletmanager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "bulletmanager.h"
#include "manager.h"

//============================
//�R���X�g���N�^
//============================
CBulletManager::CBulletManager() :
	m_apManager()
{
	m_apManager.clear();
}

//============================
//�f�X�g���N�^
//============================
CBulletManager::~CBulletManager()
{

}

//============================
//������
//============================
HRESULT CBulletManager::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CBulletManager::Uninit()
{
	m_apManager.clear();
}

//============================
//�o�^����
//============================
void CBulletManager::Regist(CBullet* bullet)
{
	//�G�̏���o�^
	m_apManager.push_back(bullet);
}

//============================
//�폜����
//============================
void CBulletManager::Erase(CBullet* bullet)
{
	//�T�C�Y��0�Ȃ甲����
	if (m_apManager.size() == 0)
	{
		return;
	}
	//�G�̏����폜
	m_apManager.remove(bullet);
}