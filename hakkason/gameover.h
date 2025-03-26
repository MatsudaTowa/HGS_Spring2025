//================================
//
//gameover.cppに必要な宣言[gameover.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAMEOVER_H_ //このマクロ定義がされていなかったら
#define _GAMEOVER_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "scene.h"

//タイトルクラス
class CGameover : public CScene
{
public:

	//メンバ関数
	CGameover();						//コンストラクタ
	~CGameover() override;				//デストラクタ
	HRESULT Init() override;		//初期化
	void Uninit() override;			//終了
	void Update() override;			//更新
	void Draw() override;			//描画
};
#endif