//=============================================
//
//ウェーブ処理[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_TWO_H_ //これが定義されてないとき

#define _WAVE_TWO_H_
#include "main.h"
#include "wave.h"

//=============================================
//  ウェーブクラス定義
//=============================================
class CWave_Three :public CWave
{
public:

	// メンバ関数
	CWave_Three();
	virtual ~CWave_Three();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
};

#endif