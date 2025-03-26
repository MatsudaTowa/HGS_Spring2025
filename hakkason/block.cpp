//======================================
//
//	ブロックの処理[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "block.h"
#include "manager.h"

//定数の初期化
const std::string CBlock::FILEPATH = "data\\MODEL\\block.x";

//============================
//コンストラクタ
//============================
CBlock::CBlock(int nPriority) : CObjectX(nPriority)
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
	
}

//============================
//クリエイト
//============================
CBlock* CBlock::Create(D3DXVECTOR3 pos)
{
	//ポインタ用の変数
	CBlock* pBlock;

	//メモリの確保
	pBlock = new CBlock;

	//パラメータの設定
	pBlock->SetPos(pos);	//位置の設定

	//初期化
	pBlock->Init();

	return pBlock;
}