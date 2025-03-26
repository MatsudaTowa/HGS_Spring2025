//======================================
//
//	�u���b�N�̊Ǘ������鏈��[blockmanager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "blockmanager.h"
#include "manager.h"

//============================
//�R���X�g���N�^
//============================
CBlockManager::CBlockManager() :
	m_apManager()
{
	m_apManager.clear();
}

//============================
//�f�X�g���N�^
//============================
CBlockManager::~CBlockManager()
{

}

//============================
//������
//============================
HRESULT CBlockManager::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CBlockManager::Uninit()
{
	m_apManager.clear();
}

//============================
//�o�^����
//============================
void CBlockManager::Regist(CBlock* block)
{
	//�G�̏���o�^
	m_apManager.push_back(block);
}

//============================
//�폜����
//============================
void CBlockManager::Erase(CBlock* block)
{
	//�T�C�Y��0�Ȃ甲����
	if (m_apManager.size() == 0)
	{
		return;
	}
	//�G�̏����폜
	m_apManager.remove(block);
}