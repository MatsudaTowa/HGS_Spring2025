//======================================
//
//	ブロックの管理をする処理[blockmanager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "blockmanager.h"
#include "manager.h"

//============================
//コンストラクタ
//============================
CBlockManager::CBlockManager() :
	m_apManager()
{
	m_apManager.clear();
}

//============================
//デストラクタ
//============================
CBlockManager::~CBlockManager()
{

}

//============================
//初期化
//============================
HRESULT CBlockManager::Init()
{
	return S_OK;
}

//============================
//終了処理
//============================
void CBlockManager::Uninit()
{
	m_apManager.clear();
}

//============================
//登録処理
//============================
void CBlockManager::Regist(CBlock* block)
{
	//敵の情報を登録
	m_apManager.push_back(block);
}

//============================
//削除処理
//============================
void CBlockManager::Erase(CBlock* block)
{
	//サイズが0なら抜ける
	if (m_apManager.size() == 0)
	{
		return;
	}
	//敵の情報を削除
	m_apManager.remove(block);
}