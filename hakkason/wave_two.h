//=============================================
//
//ウェーブ処理[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_THREE_H_ //これが定義されてないとき

#define _WAVE_THREE_H_
#include "main.h"
#include "wave.h"

//=============================================
//  ウェーブクラス定義
//=============================================
class CWave_Two :public CWave
{
public:

	// メンバ関数
	CWave_Two();
	virtual ~CWave_Two();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
	static const int NUM_ENEMY = 3;
	static const CWave::EnemyInfo ENEMY_INFO[NUM_ENEMY];
};

#endif