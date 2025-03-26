//================================
//
//enemy_000.cppに必要な宣言[enemy_000.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_000_H_ //このマクロ定義がされていなかったら
#define _ENEMY_000_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "enemy.h"

//エネミークラス
class CEnemy_000 : public CEnemy
{
public:

	//メンバ関数
	CEnemy_000(int nPriority = 3);	//コンストラクタ
	~CEnemy_000() override;			//デストラクタ
	HRESULT Init() override;								//初期化
	void Uninit() override;									//終了
	void Update() override;									//更新
	void Draw() override;									//描画
private:
	static const int LIFE = 5;
	static const int SHOT_FRAME = 90;
	static const std::string FILEPATH;					//読み込むファイル
};

#endif