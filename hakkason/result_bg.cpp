//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================
#include "result_bg.h"

const std::string CResult_Bg::FILEPATH = "data\\TEXTURE\\LifeGauge.png";

//================================
// コンストラクタ
//================================
CResult_Bg::CResult_Bg(int nPriority) :CObject2D(nPriority)
{
}

//================================
// デストラクタ
//================================
CResult_Bg::~CResult_Bg()
{
}

//================================
// 初期化
//================================
HRESULT CResult_Bg::Init()
{
	CObject2D::Init();
	return S_OK;
}

//================================
// 終了
//================================
void CResult_Bg::Uninit()
{
	CObject2D::Uninit();
}

//================================
// 更新
//================================
void CResult_Bg::Update()
{
	CObject2D::Update();
}

//================================
// 描画
//================================
void CResult_Bg::Draw()
{
	CObject2D::Draw(FILEPATH.c_str());
}

//================================
// 生成
//================================
CResult_Bg* CResult_Bg::Create(D3DXVECTOR3 pos)
{
	CResult_Bg* pScreen = new CResult_Bg;
	pScreen->SetPos(pos);
	pScreen->SetSize({ SCREEN_WIDTH,SCREEN_HEIGHT,0.0f });
	pScreen->Init();
	return pScreen;
}
