//================================
//
//object2D.cpp�ɕK�v�Ȑ錾[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "tutorial_screen.h"

const std::string CTutorialScreen::FILEPATH = "data\\TEXTURE\\tutorial.png";

//================================
// �R���X�g���N�^
//================================
CTutorialScreen::CTutorialScreen(int nPriority) :CObject2D(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CTutorialScreen::~CTutorialScreen()
{
}

//================================
// ������
//================================
HRESULT CTutorialScreen::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// �I��
//================================
void CTutorialScreen::Uninit()
{
	CObject2D::Uninit();
}

//================================
// �X�V
//================================
void CTutorialScreen::Update()
{
	CObject2D::Update();
}

//================================
// �`��
//================================
void CTutorialScreen::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// ����
//================================
CTutorialScreen* CTutorialScreen::Create(D3DXVECTOR3 pos)
{
	CTutorialScreen* pScreen = new CTutorialScreen;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
