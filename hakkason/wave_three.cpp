//=============================================
//
//ウェーブ処理[wave.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "wave_three.h"

const CWave_Three::EnemyInfo CWave_Three::ENEMY_INFO[NUM_ENEMY]
{
	{{100.0f,0.0f,0.0f},CEnemy::ENEMY_000},
	{{-100.0f,0.0f,0.0f},CEnemy::ENEMY_000},
	{{0.0f,0.0f,30.0f},CEnemy::ENEMY_002},
};

//=============================================
//コンストラクタ
//=============================================
CWave_Three::CWave_Three()
{
}

//=============================================
//デストラクタ
//=============================================
CWave_Three::~CWave_Three()
{
}

//=============================================
//初期化
//=============================================
HRESULT CWave_Three::Init()
{
	CWave::Init();
	for (int nCnt = 0; nCnt < NUM_ENEMY; ++nCnt)
	{
		CEnemy::Create(ENEMY_INFO[nCnt].pos, ENEMY_INFO[nCnt].type);
	}
	return S_OK;
}

//=============================================
//終了
//=============================================
void CWave_Three::Uninit()
{
	CWave::Uninit();
}

//=============================================
//更新
//=============================================
void CWave_Three::Update()
{
	CWave::Update();
}
