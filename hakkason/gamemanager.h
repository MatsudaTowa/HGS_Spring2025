//================================
//
//gamemanager.cppに必要な宣言[gamemanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAMEMANAGER_H_ //このマクロ定義がされていなかったら
#define _GAMEMANAGER_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "enemymanager.h"
#include "bulletmanager.h"
#include "blockmanager.h"
#include "player.h"

//マネージャークラス
class CGameManager
{

private:

	//メンバ関数
	CGameManager();								//コンストラクタ

public:

	//メンバ関数
	~CGameManager();						//デストラクタ
	void Init();							//初期化
	void Uninit();							//終了処理

	//インスタンスの生成
	static CGameManager* GetInstance()
	{
		static CGameManager instance;	//静的インスタンス
		return &instance;
	}

	void SetPlayer(CPlayer* player) { m_pPlayer = player; }	//プレイヤーの設定


	CEnemyManager* GetEnemyManager() { return m_pEnemyManager; }	//エネミーマネージャーの取得
	CBulletManager* GetBulletManager() { return m_pBulletmanager; }	//バレットマネージャーの取得
	CBlockManager* GetBlockManager() { return m_pBlockManager; }	//ブロックマネージャーの取得
	CPlayer* GetPlayer() { return m_pPlayer; }						//プレイヤーの取得

private:

	//変数
	CEnemyManager* m_pEnemyManager;
	CBulletManager* m_pBulletmanager;
	CBlockManager* m_pBlockManager;
	CPlayer* m_pPlayer;
};

#endif