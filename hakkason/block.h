//================================
//
//block.cppに必要な宣言[block.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCK_H_ //このマクロ定義がされていなかったら
#define _BLOCK_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "objectX.h"

//Xオブジェクトクラス
class CBlock : public CObjectX
{
public:

	//定数の宣言
	static const std::string FILEPATH;	//読み込むファイル

	//列挙型
	typedef enum
	{
		BLOCKTYPE_NORMAL = 0,
		BLOCKTYPE_MAX
	}BLOCKTYPE;

	//メンバ関数
	CBlock(int nPriority = 3);								//コンストラクタ
	~CBlock() override;										//デストラクタ
	HRESULT Init() override;								//初期化
	void Uninit() override;									//終了
	void Update() override;									//更新
	void Draw() override;									//描画
	static CBlock* Create(D3DXVECTOR3 pos, BLOCKTYPE type);	//ブロックの生成

	void SetBlockType(BLOCKTYPE type) { m_BlockType = type; }
	BLOCKTYPE GetBlockType() { return m_BlockType; }

private:

	//変数
	BLOCKTYPE m_BlockType;
};

#endif