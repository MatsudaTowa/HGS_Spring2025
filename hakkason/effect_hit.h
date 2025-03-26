//================================
//
//effect_hit.cppに必要な宣言[effect_death.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _EFFECT_HIT_H_ //このマクロ定義がされていなかったら
#define _EFFECT_HIT_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "effect_billboard.h"

//死亡エフェクトクラス
class CEffect_Hit : public CEffect_Billboard
{
public:

	//定数
	static const std::string TEXTURE_PATH;	//テクスチャパス
	static constexpr float RADIUS{ 70.0f };	//サイズ半径

	//テクスチャ情報
	static constexpr int HORIZONTAL{ 6 };	//横の分割数(U座標)
	static constexpr int VERTICAL{ 2 };		//縦の分割数(V座標)
	static constexpr int SPEED_UPDATE{ 1 };	//更新速度
	static constexpr bool LOOP{ false };	//ループ

	//メンバ関数
	CEffect_Hit();			//コンストラクタ
	~CEffect_Hit() override;	//デストラクタ
	HRESULT Init() override;	//初期化
	void Uninit() override;		//終了
	void Update() override;		//更新
	void Draw() override;		//描画

	//生成
	static CEffect_Hit* Create(D3DXVECTOR3 pos);
};

#endif