//================================
//
//object2D.cpp�ɕK�v�Ȑ錾[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "gameover_bg.h"

const std::string CGameOver_Bg::FILEPATH = "data\\TEXTURE\\gameover.png";

//================================
// �R���X�g���N�^
//================================
CGameOver_Bg::CGameOver_Bg(int nPriority) :CObject2D(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CGameOver_Bg::~CGameOver_Bg()
{
}

//================================
// ������
//================================
HRESULT CGameOver_Bg::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// �I��
//================================
void CGameOver_Bg::Uninit()
{
	CObject2D::Uninit();
}

//================================
// �X�V
//================================
void CGameOver_Bg::Update()
{
	CObject2D::Update();
}

//================================
// �`��
//================================
void CGameOver_Bg::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// ����
//================================
CGameOver_Bg* CGameOver_Bg::Create(D3DXVECTOR3 pos)
{
	CGameOver_Bg* pScreen = new CGameOver_Bg;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
