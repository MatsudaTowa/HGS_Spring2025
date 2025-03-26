//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "title_screen.h"

const std::string CTitleScreen::FILEPATH = "data\\TEXTURE\\title.png";

//================================
// コンストラクタ
//================================
CTitleScreen::CTitleScreen(int nPriority):CObject2D(nPriority)
{
}

//================================
// デストラクタ
//================================
CTitleScreen::~CTitleScreen()
{
}

//================================
// 初期化
//================================
HRESULT CTitleScreen::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// 終了
//================================
void CTitleScreen::Uninit()
{
	CObject2D::Uninit();
}

//================================
// 更新
//================================
void CTitleScreen::Update()
{
	CObject2D::Update();
}

//================================
// 描画
//================================
void CTitleScreen::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// 生成
//================================
CTitleScreen* CTitleScreen::Create(D3DXVECTOR3 pos)
{
	CTitleScreen* pScreen = new CTitleScreen;
	pScreen->SetPos(pos);
	pScreen->SetSize({SCREEN_WIDTH,SCREEN_HEIGHT,0.0f});
	pScreen->Init();
	return pScreen;
}
