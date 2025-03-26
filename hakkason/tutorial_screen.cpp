//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "tutorial_screen.h"

const std::string CTutorialScreen::FILEPATH = "data\\TEXTURE\\tutorial.png";

//================================
// コンストラクタ
//================================
CTutorialScreen::CTutorialScreen(int nPriority) :CObject2D(nPriority)
{
}

//================================
// デストラクタ
//================================
CTutorialScreen::~CTutorialScreen()
{
}

//================================
// 初期化
//================================
HRESULT CTutorialScreen::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// 終了
//================================
void CTutorialScreen::Uninit()
{
	CObject2D::Uninit();
}

//================================
// 更新
//================================
void CTutorialScreen::Update()
{
	CObject2D::Update();
}

//================================
// 描画
//================================
void CTutorialScreen::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// 生成
//================================
CTutorialScreen* CTutorialScreen::Create(D3DXVECTOR3 pos)
{
	CTutorialScreen* pScreen = new CTutorialScreen;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
