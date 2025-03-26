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
const std::string CField::FILEPATH = "data\\TEXTURE\\FieldTexture000.jpeg";
const D3DXVECTOR3 CField::SIZE = {1000.0f, 0.0f, 1000.0f};	//�T�C�Y
const D3DXVECTOR3 CField::POS = {0.0f, 0.0f, 0.0f};		//�ʒu

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
	CObject3D::Init();
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
	CObject3D::Draw(FILEPATH.c_str());
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