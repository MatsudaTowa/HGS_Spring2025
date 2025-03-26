//================================
//
//object2D.cpp�ɕK�v�Ȑ錾[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "title_screen.h"

const std::string CTitleScreen::FILEPATH = "data\\TEXTURE\\title.png";

//================================
// �R���X�g���N�^
//================================
CTitleScreen::CTitleScreen(int nPriority):CObject2D(nPriority)
{
}

//================================
// �f�X�g���N�^
//================================
CTitleScreen::~CTitleScreen()
{
}

//================================
// ������
//================================
HRESULT CTitleScreen::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// �I��
//================================
void CTitleScreen::Uninit()
{
	CObject2D::Uninit();
}

//================================
// �X�V
//================================
void CTitleScreen::Update()
{
	CObject2D::Update();
}

//================================
// �`��
//================================
void CTitleScreen::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// ����
//================================
CTitleScreen* CTitleScreen::Create(D3DXVECTOR3 pos)
{
	CTitleScreen* pScreen = new CTitleScreen;
	pScreen->SetPos(pos);
	pScreen->SetSize({SCREEN_WIDTH,SCREEN_HEIGHT,0.0f});
	pScreen->Init();
	return pScreen;
}
