//======================================
//
//	�u���b�N�̏���[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "block.h"
#include "manager.h"

//�萔�̏�����
const std::string CBlock::FILEPATH = "data\\MODEL\\block.x";

//============================
//�R���X�g���N�^
//============================
CBlock::CBlock(int nPriority) : CObjectX(nPriority)
{
	
}

//============================
//�f�X�g���N�^
//============================
CBlock::~CBlock()
{

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
CBlock* CBlock::Create(D3DXVECTOR3 pos)
{
	//�|�C���^�p�̕ϐ�
	CBlock* pBlock;

	//�������̊m��
	pBlock = new CBlock;

	//�p�����[�^�̐ݒ�
	pBlock->SetPos(pos);	//�ʒu�̐ݒ�

	//������
	pBlock->Init();

	return pBlock;
}