//================================
//
//block_normal.cppに必要な宣言[block.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCK_NORMAL_H_ //このマクロ定義がされていなかったら
#define _BLOCK_NORMAL_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "block.h"

//Xオブジェクトクラス
class CBlock_Normal : public CBlock
{
public:

	//定数の宣言
	static const std::string FILEPATH;	//読み込むファイル

	//メンバ関数
	CBlock_Normal(int nPriority = 3);						//コンストラクタ
	~CBlock_Normal() override;								//デストラクタ
	HRESULT Init() override;								//初期化
	void Uninit() override;									//終了
	void Update() override;									//更新
	void Draw() override;									//描画
	
};

#endif