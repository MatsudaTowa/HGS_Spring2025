//================================
//
//player.cppに必要な宣言[player.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _PLAYER_H_ //このマクロ定義がされていなかったら
#define _PLAYER_H_ //２重インクルード防止のマクロ定義

#include "game_character.h"
#include "enemy.h"

//プレイヤークラス
class CPlayer : public CGame_Character
{
public:

	//定数
	static constexpr int MAX_LIFE{ 20 };				//最大体力値
	static const std::string FILEPATH;					//読み込むファイル
	
	//キーの種類
	typedef enum
	{
		PLAYERMOTION_NORMAL = 0,
		PLAYERMOTION_WALK,
		PLAYERMOTION_ACTION,
		PLAYERMOTION_JUMP,
		PLAYERMOTION_ARIAL000,
		PLAYERMOTION_ARIAL001,
		PLAYERMOTION_ARIAL002,
		PLAYERMOTION_KNOCKBACK,
		PLAYERMOTION_DAMAGE,
		PLAYERMOTION_ACTION001,
		PLAYERMOTION_ACTION002,
		PLAYERMOTION_ATTACKCHARGE,
		PLAYERMOTION_CHARGEATTACK,
		PLAYERMOTION_DASHATTACK000,
		PLAYERMOTION_DASHATTACK001,
		PLAYERMOTION_COUNTER,
		PLAYERMOTION_GUARD,
		PLAYERMOTION_DEATH,
		PLAYERMOTION_MAX
	}PLAYERMOTION;

	//メンバ関数
	CPlayer(int nPriority = 2);							//コンストラクタ
	~CPlayer() override;								//デストラクタ
	HRESULT Init() override;							//初期化
	void Uninit() override;								//終了
	void Update() override;								//更新
	void Draw() override;								//描画
	bool SetDamage(int damage, float angle) override;	//ダメージを設定

	//静的関数
	static CPlayer* Create();	//Playerの生成
};

#endif