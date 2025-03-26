//======================================
//
//	�u���b�N�̏���[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "block.h"
#include "block_normal.h"
#include "manager.h"
#include "gamemanager.h"

//�萔�̏�����
const std::string CBlock::FILEPATH = "data\\MODEL\\block.x";

//============================
//�R���X�g���N�^
//============================
CBlock::CBlock(int nPriority) : CObjectX(nPriority),
	m_BlockType(CBlock::BLOCKTYPE_NORMAL)
{
	//�}�l�[�W���[�ɓo�^
	CGameManager::GetInstance()->GetBlockManager()->Regist(this);
}

//============================
//�f�X�g���N�^
//============================
CBlock::~CBlock()
{
	//�}�l�[�W���[����폜
	if (CGameManager::GetInstance()->GetBlockManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBlockManager()->Erase(this);
	}
}

//============================
//������
//============================
HRESULT CBlock::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CBlock::Uninit()
{
	//����
	SetDeath();
}

//============================
//�X�V
//============================
void CBlock::Update()
{

}

//============================
//�`��
//============================
void CBlock::Draw()
{
	
}

//============================
//�N���G�C�g
//============================
CBlock* CBlock::Create(D3DXVECTOR3 pos, BLOCKTYPE type)
{
	//�|�C���^�p�̕ϐ�
	CBlock* pBlock = nullptr;

	switch (type)
	{
	case BLOCKTYPE::BLOCKTYPE_NORMAL:
		pBlock = new CBlock_Normal;
		break;

	default:
		assert("�u���b�N�͈͊O");
		break;

	}

	//�������̊m��
	pBlock = new CBlock;
	pBlock->m_BlockType = type;

	//�p�����[�^�̐ݒ�
	pBlock->SetPos(pos);	//�ʒu�̐ݒ�

	//������
	pBlock->Init();

	return pBlock;
}