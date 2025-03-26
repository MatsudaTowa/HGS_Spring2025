//======================================
//
//	�t�B�[���h�̏���[field.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "field.h"
#include "manager.h"

//�萔
const const std::string FILEPATH = "";
static const D3DXVECTOR3 SIZE = {200.0f, 0.0f, 200.0f};	//�T�C�Y
static const D3DXVECTOR3 POS = {0.0f, 0.0f, 0.0f};		//�ʒu

//============================
//�R���X�g���N�^
//============================
CField::CField(int nPriority) : CObject3D(nPriority)
{
	
}

//============================
//�f�X�g���N�^
//============================
CField::~CField()
{
	
}

//============================
//������
//============================
HRESULT CField::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CField::Uninit()
{
	CObject3D::Uninit();
}

//============================
//�X�V
//============================
void CField::Update()
{

}

//============================
//�`��
//============================
void CField::Draw()
{
	//CObject3D::Draw(FILEPATH.c_str());
}

//============================
//�N���G�C�g
//============================
CField* CField::Create()
{
	//�|�C���^�p�̕ϐ�
	CField* pObject;

	//�������̊m��
	pObject = new CField;

	//������
	pObject->Init();
	pObject->SetPos(POS);
	pObject->SetSize(SIZE, CObject3D::TYPE_FLOOR);

	return pObject;
}