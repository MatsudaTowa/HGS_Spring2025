//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "gameover_bg.h"

const std::string CGameOver_Bg::FILEPATH = "data\\TEXTURE\\gameover.png";

//================================
// コンストラクタ
//================================
CGameOver_Bg::CGameOver_Bg(int nPriority) :CObject2D(nPriority)
{
}

//================================
// デストラクタ
//================================
CGameOver_Bg::~CGameOver_Bg()
{
}

//================================
// 初期化
//================================
HRESULT CGameOver_Bg::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// 終了
//================================
void CGameOver_Bg::Uninit()
{
	CObject2D::Uninit();
}

//================================
// 更新
//================================
void CGameOver_Bg::Update()
{
	CObject2D::Update();
}

//================================
// 描画
//================================
void CGameOver_Bg::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// 生成
//================================
CGameOver_Bg* CGameOver_Bg::Create(D3DXVECTOR3 pos)
{
	CGameOver_Bg* pScreen = new CGameOver_Bg;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
