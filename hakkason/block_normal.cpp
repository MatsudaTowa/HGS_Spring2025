//======================================
//
//	ブロックの処理[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "block_normal.h"
#include "manager.h"

//定数の初期化
const std::string CBlock_Normal::FILEPATH = "data\\MODEL\\akarenga.x";

//============================
//コンストラクタ
//============================
CBlock_Normal::CBlock_Normal(int nPriority) : CBlock(nPriority)
{

}

//============================
//デストラクタ
//============================
CBlock_Normal::~CBlock_Normal()
{

}

//============================
//初期化
//============================
HRESULT CBlock_Normal::Init()
{
	return S_OK;
}

//============================
//終了処理
//============================
void CBlock_Normal::Uninit()
{
	//消去
	SetDeath();
}

//============================
//更新
//============================
void CBlock_Normal::Update()
{

}

//============================
//描画
//============================
void CBlock_Normal::Draw()
{
	CObjectX::Draw(FILEPATH.c_str());
}