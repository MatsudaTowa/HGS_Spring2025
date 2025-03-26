//======================================
//
//	�u���b�N�̏���[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "block_normal.h"
#include "manager.h"

//�萔�̏�����
const std::string CBlock::FILEPATH = "data\\MODEL\\akarenga.x";

//============================
//�R���X�g���N�^
//============================
CBlock::CBlock(int nPriority) : CBlock(nPriority)
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
	CObjectX::Draw(FILEPATH.c_str());
}