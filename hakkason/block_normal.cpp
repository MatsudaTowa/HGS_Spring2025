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
const std::string CBlock_Normal::FILEPATH = "data\\MODEL\\akarenga.x";

//============================
//�R���X�g���N�^
//============================
CBlock_Normal::CBlock_Normal(int nPriority) : CBlock(nPriority)
{

}

//============================
//�f�X�g���N�^
//============================
CBlock_Normal::~CBlock_Normal()
{

}

//============================
//������
//============================
HRESULT CBlock_Normal::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CBlock_Normal::Uninit()
{
	//����
	SetDeath();
}

//============================
//�X�V
//============================
void CBlock_Normal::Update()
{

}

//============================
//�`��
//============================
void CBlock_Normal::Draw()
{
	CObjectX::Draw(FILEPATH.c_str());
}