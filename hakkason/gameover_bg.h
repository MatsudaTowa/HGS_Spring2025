//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAMEOVER_BG_H_ //このマクロ定義がされていなかったら
#define _GAMEOVER_BG_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "object2D.h"
//2Dオブジェクトクラス
class CGameOver_Bg : public CObject2D
{
public:
	//メンバ関数
	CGameOver_Bg(int nPriority = 3);			//コンストラクタ
	~CGameOver_Bg() override;					//デストラクタ
	HRESULT Init() override;				//初期化
	void Uninit() override;					//終了
	void Update() override;					//更新
	void Draw()override;		//引数のテクスチャで描画
	static CGameOver_Bg* Create(D3DXVECTOR3 pos);				//Object2Dの生成

private:
	static const std::string FILEPATH;	//テクスチャパス
};

#endif