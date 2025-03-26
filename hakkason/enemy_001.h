//================================
//
//enemy_001.cppに必要な宣言[enemy_001.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_001_H_ //このマクロ定義がされていなかったら
#define _ENEMY_001_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "enemy.h"

//エネミークラス
class CEnemy_001 : public CEnemy
{
public:

	//メンバ関数
	CEnemy_001(int nPriority = 3);	//コンストラクタ
	~CEnemy_001() override;			//デストラクタ
	HRESULT Init() override;								//初期化
	void Uninit() override;									//終了
	void Update() override;									//更新
	void Draw() override;									//描画
private:
	static const int LIFE = 20;
	static const int SHOT_FRAME = 120;
	static const std::string FILEPATH;					//読み込むファイル
};

#endif