//================================
//
//bulletmanager.cppに必要な宣言[bulletmanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BULLETMANAGER_H_ //このマクロ定義がされていなかったら
#define _BULLETMANAGER_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "bullet.h"

//バレットマネージャーのクラス
class CBulletManager
{
public:

	//メンバ関数
	CBulletManager();				//コンストラクタ
	~CBulletManager();				//デストラクタ
	HRESULT Init();					//初期化
	void Uninit();					//終了
	void Regist(CBullet* bullet);	//登録
	void Erase(CBullet* bullet);	//削除

	//リストの取得
	std::list<CBullet*> GetList() { return m_apManager; }

private:

	//メンバ変数
	std::list<CBullet*> m_apManager;	//敵を管理
};

#endif