//================================
//
//title.cppに必要な宣言[title.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _TUTORIAL_H_ //このマクロ定義がされていなかったら
#define _TUTORIAL_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "scene.h"

//タイトルクラス
class CTutorial : public CScene
{
public:

	//メンバ関数
	CTutorial();						//コンストラクタ
	~CTutorial() override;				//デストラクタ
	HRESULT Init() override;		//初期化
	void Uninit() override;			//終了
	void Update() override;			//更新
	void Draw() override;			//描画
};
#endif