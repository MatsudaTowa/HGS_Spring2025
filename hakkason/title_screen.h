//================================
//
//object2D.cppに必要な宣言[object2D.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _TITLE_SCREEN_H_ //このマクロ定義がされていなかったら
#define _TITLE_SCREEN_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "object2D.h"
//2Dオブジェクトクラス
class CTitleScreen : public CObject2D
{
public:
	//メンバ関数
	CTitleScreen(int nPriority = 3);			//コンストラクタ
	~CTitleScreen() override;					//デストラクタ
	HRESULT Init() override;				//初期化
	void Uninit() override;					//終了
	void Update() override;					//更新
	void Draw()override;		//引数のテクスチャで描画
	static CTitleScreen* Create(D3DXVECTOR3 pos);				//Object2Dの生成

private:
	static const std::string FILEPATH;	//テクスチャパス
};

#endif