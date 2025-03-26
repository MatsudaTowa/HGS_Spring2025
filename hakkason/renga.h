//================================
//
//renga.cppに必要な宣言[renga.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _RENGA_H_ //このマクロ定義がされていなかったら
#define _RENGA_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "objectX.h"

//レンガクラス
class CRenga : public CObjectX
{
public:

	//定数の宣言
	static const std::string FILEPATH;	//読み込むファイル

	//メンバ関数
	CRenga(int nPriority = 3);														//コンストラクタ
	~CRenga() override;																//デストラクタ
	HRESULT Init() override;														//初期化
	void Uninit() override;															//終了
	void Update() override;															//更新
	void Draw() override;															//描画
	static CRenga* Create(D3DXVECTOR3 pos);											//生成

};

#endif