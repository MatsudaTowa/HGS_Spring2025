//================================
//
//enemy_002.cppに必要な宣言[enemy_001.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_002_H_ //このマクロ定義がされていなかったら
#define _ENEMY_002_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "enemy.h"

//=============================================
//前方宣言
//=============================================
class CEnemy_002_State;

//エネミークラス
class CEnemy_002 : public CEnemy
{
public:

	//メンバ関数
	CEnemy_002(int nPriority = 3);	//コンストラクタ
	~CEnemy_002() override;			//デストラクタ
	HRESULT Init() override;								//初期化
	void Uninit() override;									//終了
	void Update() override;									//更新
	void Draw() override;									//描画

	void ShotBullet()override;

	void ChangeState(CEnemy_002_State* state)
	{
		//今のステートを消し引数のステートに切り替える
		if (m_pState != nullptr)
		{
			delete m_pState;
			m_pState = state;
		}
	}

	CEnemy_002_State* m_pState;
private:
	static const int LIFE = 30;
	static const int SHOT_FRAME = 220;
	static constexpr float SPEED = 1.0f;
	static const std::string FILEPATH;					//読み込むファイル
};

#endif