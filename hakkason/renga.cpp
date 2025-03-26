//======================================
//
//	�o���b�g�̏���[renga.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "renga.h"
#include "manager.h"

//�萔�̏�����
const std::string CRenga::FILEPATH = "data\\MODEL\\renga.x";

//============================
//�R���X�g���N�^
//============================
CRenga::CRenga(int nPriority) : CObjectX(nPriority)
{
	
}

//============================
//�f�X�g���N�^
//============================
CRenga::~CRenga()
{
	
}

//============================
//������
//============================
HRESULT CRenga::Init()
{
	CObjectX::Init();

	return S_OK;
}

//============================
//�I������
//============================
void CRenga::Uninit()
{
	CObjectX::Uninit();
}

//============================
//�X�V
//============================
void CRenga::Update()
{
	CObjectX::Update();
}

//============================
//�`��
//============================
void CRenga::Draw()
{
	CObjectX::Draw(FILEPATH.c_str());
}

//============================
//�N���G�C�g
//============================
CRenga* CRenga::Create(D3DXVECTOR3 pos)
{
	//�|�C���^�p�̕ϐ�
	CRenga* pObjectX;

	//�������̊m��
	pObjectX = new CRenga;

	//�p�����[�^�̐ݒ�
	pObjectX->SetPos(pos);					//�ʒu�̐ݒ�
	
	//������
	pObjectX->Init();

	return pObjectX;
}