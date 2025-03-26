//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _RESULT_BG_H_ //このマクロ定義がされていなかったら
#define _RESULT_BG_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "object2D.h"
//2Dオブジェクトクラス
class CResult_Bg : public CObject2D
{
public:
	//メンバ関数
	CResult_Bg(int nPriority = 3);			//コンストラクタ
	~CResult_Bg() override;					//デストラクタ
	HRESULT Init() override;				//初期化
	void Uninit() override;					//終了
	void Update() override;					//更新
	void Draw()override;					//引数のテクスチャで描画
	static CResult_Bg* Create(D3DXVECTOR3 pos);				//Object2Dの生成

private:
	static const std::string FILEPATH;	//テクスチャパス
};

#endif