//================================
//
//blockmanager.cppに必要な宣言[blockmanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCKMANAGER_H_ //このマクロ定義がされていなかったら
#define _BLOCKMANAGER_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "main.h"
#include "block.h"

//ブロックマネージャーのクラス
class CBlockManager
{
public:

	//メンバ関数
	CBlockManager();			//コンストラクタ
	~CBlockManager();			//デストラクタ
	HRESULT Init();				//初期化
	void Uninit();				//終了
	void Regist(CBlock* block);	//登録
	void Erase(CBlock* block);	//削除

	//リストの取得
	std::list<CBlock*> GetList() { return m_apManager; }

private:

	//メンバ変数
	std::list<CBlock*> m_apManager;	//敵を管理
};

#endif