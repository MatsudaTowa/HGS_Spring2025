//================================
//
//enemy.cppに必要な宣言[enemy.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_H_ //このマクロ定義がされていなかったら
#define _ENEMY_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "game_character.h"

//エネミークラス
class CEnemy : public CGame_Character
{
public:

	enum ENEMY_TYPE
	{
		ENEMY_000 = 0,
		ENMEY_MAX,
	};

	//メンバ関数
	CEnemy(int nPriority = 3);	//コンストラクタ
	virtual ~CEnemy() override;										//デストラクタ
	virtual HRESULT Init() override;								//初期化
	virtual void Uninit() override;									//終了
	virtual void Update() override;									//更新
	virtual void Draw() override;									//描画
	static CEnemy* Create(D3DXVECTOR3 pos, ENEMY_TYPE type);							//エネミーの生成

	//ダメージの設定
	bool SetDamage(int damage) override;				//ダメージの設定
};

#endif