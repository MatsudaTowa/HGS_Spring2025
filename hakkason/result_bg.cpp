//================================
//
//object2D.cpp�ɕK�v�Ȑ錾[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "result_bg.h"

const std::string CResult_Bg::FILEPATH = "data\\TEXTURE\\LifeGauge.png";

//================================
// �R���X�g���N�^
//================================
CResult_Bg::CResult_Bg(int nPriority) :CObject2D(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CResult_Bg::~CResult_Bg()
{
}

//================================
// ������
//================================
HRESULT CResult_Bg::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// �I��
//================================
void CResult_Bg::Uninit()
{
	CObject2D::Uninit();
}

//================================
// �X�V
//================================
void CResult_Bg::Update()
{
	CObject2D::Update();
}

//================================
// �`��
//================================
void CResult_Bg::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// ����
//================================
CResult_Bg* CResult_Bg::Create(D3DXVECTOR3 pos)
{
	CResult_Bg* pScreen = new CResult_Bg;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
