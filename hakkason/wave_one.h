//=============================================
//
//ウェーブ処理[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_ONE_H_ //これが定義されてないとき

#define _WAVE_ONE_H_
#include "main.h"
#include "wave.h"

//=============================================
//  ウェーブクラス定義
//=============================================
class CWave_One:public CWave
{
public:

	// メンバ関数
	CWave_One();
	~CWave_One() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
	static const int NUM_ENEMY = 2;
	static const CWave::EnemyInfo ENEMY_INFO[NUM_ENEMY];
};

#endif