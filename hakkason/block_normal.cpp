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
const std::string CBlock::FILEPATH = "data\\MODEL\\akarenga.x";

//============================
//コンストラクタ
//============================
CBlock::CBlock(int nPriority) : CBlock(nPriority)
{

}

//============================
//デストラクタ
//============================
CBlock::~CBlock()
{

}

//============================
//初期化
//============================
HRESULT CBlock::Init()
{
	return S_OK;
}

//============================
//終了処理
//============================
void CBlock::Uninit()
{
	//消去
	SetDeath();
}

//============================
//更新
//============================
void CBlock::Update()
{

}

//============================
//描画
//============================
void CBlock::Draw()
{
	CObjectX::Draw(FILEPATH.c_str());
}