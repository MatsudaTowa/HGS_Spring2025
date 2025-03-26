//=============================================
//
//ウェーブ処理[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_H_ //これが定義されてないとき

#define _WAVE_H_
#include "main.h"
#include "enemy.h"

//=============================================
//  ウェーブクラス定義
//=============================================
class CWave
{
public:
	//ウェーブ列挙
	enum WAVE
	{
		NONE = 0,
		ONE,
		TWO,
		THREE,
		MAX,
	};

	// メンバ関数
	CWave();
	virtual ~CWave();

	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();

	static CWave* Create(WAVE wave);

	inline WAVE GetCurrentWave()
	{
		return m_CurrentWave;
	}


protected:

	WAVE m_CurrentWave; //現在のウェーブ

	struct EnemyInfo
	{
		D3DXVECTOR3 pos;
		CEnemy::ENEMY_TYPE type;
	};
};

#endif