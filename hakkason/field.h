//================================
//
//field.cppに必要な宣言[field.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _FIELD_H_ //このマクロ定義がされていなかったら
#define _FIELD_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "object3D.h"

//フィールドクラス
class CField : public CObject3D
{
public:

	//定数
	static const std::string FILEPATH;	//読み込むファイル
	static const D3DXVECTOR3 SIZE;		//サイズ
	static const D3DXVECTOR3 POS;		//位置

	//メンバ関数
	CField(int nPriority = 3);					//コンストラクタ
	~CField() override;							//デストラクタ
	HRESULT Init() override;					//初期化
	void Uninit() override;						//終了
	void Update() override;						//更新
	void Draw() override;						//描画
	static CField* Create();					//生成
};

#endif