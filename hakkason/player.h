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
#include "gauge_playerlife.h"

//プレイヤークラス
class CPlayer : public CGame_Character
{
public:

	//定数
	static constexpr int MAX_LIFE{ 20 };				//最大体力値
	static const std::string FILEPATH;					//読み込むファイル
	static constexpr int ATTACK_COOLTIME{ 30 };			//攻撃のクールタイム
	static constexpr int ATTACK_TRRIGER{ 10 };			//攻撃発生のカウント

	//キーの種類
	typedef enum
	{
		PLAYERMOTION_NORMAL = 0,
		PLAYERMOTION_WALK,
		PLAYERMOTION_ACTION,
		PLAYERMOTION_MAX
	}PLAYERMOTION;

	//メンバ関数
	CPlayer(int nPriority = 2);							//コンストラクタ
	~CPlayer() override;								//デストラクタ
	HRESULT Init() override;							//初期化
	void Uninit() override;								//終了
	void Update() override;								//更新
	void Draw() override;								//描画
	bool SetDamage(int damage) override;				//ダメージを設定
	void SetLifeGauge(CGauge_PlayerLife* gauge) { m_pLifeGauge = gauge; }	//体力ゲージの設定
	CGauge_PlayerLife* GetLifeGauge() { return m_pLifeGauge; }				//体力ゲージの取得

	//静的関数
	static CPlayer* Create();	//Playerの生成

private:

	//関数
	void UpdateOperation();	//操作の更新
	void Move();			//移動処理
	void Attack();			//攻撃処理
	void UpdateCoolTime();	//クールタイムの更新
	void Limit();			//制限

	//変数
	CGauge_PlayerLife* m_pLifeGauge;//体力ゲージのポインタ
	int m_nAttackCoolTime;		//攻撃のクールタイム
	int m_nAttackTrrigerCount;	//攻撃発生のカウント


};

#endif