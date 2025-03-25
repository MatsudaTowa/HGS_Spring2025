//======================================
//
//	ゲームマネージャーの処理[manager.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "gamemanager.h"

//============================
//コンストラクタ
//============================
CGameManager::CGameManager() :
	m_pEnemyManager(nullptr)	//ゲームマネージャー
{

}

//============================
//デストラクタ
//============================
CGameManager::~CGameManager()
{

}

//============================
//初期化処理
//============================
void CGameManager::Init()
{
	//フェードの生成
	m_pEnemyManager = new CEnemyManager();		//メモリ確保
	m_pEnemyManager->Init();					//初期設定
}

//============================
//終了処理
//============================
void CGameManager::Uninit()
{
	//エネミーマネージャーの破棄
	if (m_pEnemyManager != nullptr)
	{
		//終了処理後に開放
		m_pEnemyManager->Uninit();
		delete m_pEnemyManager;
		m_pEnemyManager = nullptr;
	}
}