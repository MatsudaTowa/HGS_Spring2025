//======================================
//
//	ブロックの処理[block.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "block.h"
#include "block_normal.h"
#include "manager.h"
#include "gamemanager.h"

//定数の初期化
const std::string CBlock::FILEPATH = "data\\MODEL\\block.x";

//============================
//コンストラクタ
//============================
CBlock::CBlock(int nPriority) : CObjectX(nPriority),
	m_BlockType(CBlock::BLOCKTYPE_NORMAL)
{
	//マネージャーに登録
	CGameManager::GetInstance()->GetBlockManager()->Regist(this);
}

//============================
//デストラクタ
//============================
CBlock::~CBlock()
{
	//マネージャーから削除
	if (CGameManager::GetInstance()->GetBlockManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBlockManager()->Erase(this);
	}
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
CBlock* CBlock::Create(D3DXVECTOR3 pos, BLOCKTYPE type)
{
	//ポインタ用の変数
	CBlock* pBlock = nullptr;

	switch (type)
	{
	case BLOCKTYPE::BLOCKTYPE_NORMAL:
		pBlock = new CBlock_Normal;
		break;

	default:
		assert("ブロック範囲外");
		break;

	}

	//メモリの確保
	pBlock = new CBlock;
	pBlock->m_BlockType = type;

	//パラメータの設定
	pBlock->SetPos(pos);	//位置の設定

	//初期化
	pBlock->Init();

	return pBlock;
}