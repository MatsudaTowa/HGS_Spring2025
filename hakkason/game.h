//================================
//
//game.cppに必要な宣言[game.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAME_H_ //このマクロ定義がされていなかったら
#define _GAME_H_ //２重インクルード防止のマクロ定義

//ヘッダーのインクルード
#include "scene.h"
#include "time.h"

//ゲームクラス
class CGame : public CScene
{
public:

	//定数
	static const D3DXVECTOR3 TIME_POS;		//時間の位置
	static const std::string FILEPATH_MODEL;//モデルのファイルパス

	//メンバ関数
	CGame();						//コンストラクタ
	~CGame() override;				//デストラクタ
	HRESULT Init() override;		//初期化
	void Uninit() override;			//終了
	void Update() override;			//更新
	void Draw() override;			//描画
	void Load() override;			//読み込み

	//クリア判定
	void SetClear(bool clear) { m_bClear = clear; }	//設定

	//ポーズ
	void SetPause();						//ポーズの切り替え
	bool GetPause() { return m_bPause; }	//ポーズの状態を取得

private:

	//判定
	bool m_bClear;				//クリア判定
	bool m_bPause;				//ポーズ中か
};

#endif