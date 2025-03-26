//======================================
//
//	バレットの処理[renga.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "renga.h"
#include "manager.h"

//定数の初期化
const std::string CRenga::FILEPATH = "data\\MODEL\\renga.x";

//============================
//コンストラクタ
//============================
CRenga::CRenga(int nPriority) : CObjectX(nPriority)
{
	
}

//============================
//デストラクタ
//============================
CRenga::~CRenga()
{
	
}

//============================
//初期化
//============================
HRESULT CRenga::Init()
{
	CObjectX::Init();

	return S_OK;
}

//============================
//終了処理
//============================
void CRenga::Uninit()
{
	CObjectX::Uninit();
}

//============================
//更新
//============================
void CRenga::Update()
{
	CObjectX::Update();
}

//============================
//描画
//============================
void CRenga::Draw()
{
	CObjectX::Draw(FILEPATH.c_str());
}

//============================
//クリエイト
//============================
CRenga* CRenga::Create(D3DXVECTOR3 pos)
{
	//ポインタ用の変数
	CRenga* pObjectX;

	//メモリの確保
	pObjectX = new CRenga;

	//パラメータの設定
	pObjectX->SetPos(pos);					//位置の設定
	
	//初期化
	pObjectX->Init();

	return pObjectX;
}