//================================
//
//objectX.cppに必要な宣言[objectX.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BULLET_H_ //このマクロ定義がされていなかったら
#define _BULLET_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "objectX.h"

//バレットクラス
class CBullet : public CObjectX
{
public:

	//定数の宣言
	static const std::string FILEPATH;	//読み込むファイル

	//メンバ関数
	CBullet(int nPriority = 3);														//コンストラクタ
	~CBullet() override;															//デストラクタ
	HRESULT Init() override;														//初期化
	void Uninit() override;															//終了
	void Update() override;															//更新
	void Draw() override;															//描画
	static CBullet* Create(D3DXVECTOR3 pos, float rot, float speed, bool player);	//生成

	void SetPlayerBullet(bool player) { m_bPlayerBullet = player; }
	bool GetPlayerBullet() { return m_bPlayerBullet; }

	void SetSpeed(D3DXVECTOR3 speed) { m_Speed = speed; }	//設定
	D3DXVECTOR3& GetSpeed() { return m_Speed; }				//取得

	int& GetHansya() { return m_nHansya; }

private:

	//定数
	static constexpr int MAX_HANSYA{ 10 };	//最大反射数

	//関数
	void Collision();

	//変数
	D3DXVECTOR3 m_Speed;
	D3DXVECTOR3 m_OldPos;
	bool m_bPlayerBullet;
	int m_nHansya;

};

#endif