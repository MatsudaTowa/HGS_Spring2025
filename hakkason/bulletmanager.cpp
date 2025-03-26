//======================================
//
//	弾の管理をする処理[bulletmanager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "bulletmanager.h"
#include "manager.h"

//============================
//コンストラクタ
//============================
CBulletManager::CBulletManager() :
	m_apManager()
{
	m_apManager.clear();
}

//============================
//デストラクタ
//============================
CBulletManager::~CBulletManager()
{

}

//============================
//初期化
//============================
HRESULT CBulletManager::Init()
{
	return S_OK;
}

//============================
//終了処理
//============================
void CBulletManager::Uninit()
{
	m_apManager.clear();
}

//============================
//登録処理
//============================
void CBulletManager::Regist(CBullet* bullet)
{
	//敵の情報を登録
	m_apManager.push_back(bullet);
}

//============================
//削除処理
//============================
void CBulletManager::Erase(CBullet* bullet)
{
	//サイズが0なら抜ける
	if (m_apManager.size() == 0)
	{
		return;
	}
	//敵の情報を削除
	m_apManager.remove(bullet);
}