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
	m_pEnemyManager(nullptr),	//エネミーマネージャー
	m_pBulletmanager(nullptr),	//バレットマネージャー
	m_pBlockManager(nullptr)	//ブロックマネージャー
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
	//エネミーマネージャーの生成
	m_pEnemyManager = new CEnemyManager();		//メモリ確保
	m_pEnemyManager->Init();					//初期設定

	//バレットマネージャー生成
	m_pBulletmanager = new CBulletManager();	//メモリ確保
	m_pBulletmanager->Init();					//初期設定

	//ブロックマネージャー生成
	m_pBlockManager = new CBlockManager();		//メモリ確保
	m_pBlockManager->Init();					//初期設定
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

	//エネミーマネージャーの破棄
	if (m_pBulletmanager != nullptr)
	{
		//終了処理後に開放
		m_pBulletmanager->Uninit();
		delete m_pBulletmanager;
		m_pBulletmanager = nullptr;
	}

	//エネミーマネージャーの破棄
	if (m_pBlockManager != nullptr)
	{
		//終了処理後に開放
		m_pBlockManager->Uninit();
		delete m_pBlockManager;
		m_pBlockManager = nullptr;
	}
}