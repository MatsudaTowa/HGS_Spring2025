//=============================================
//
//ウェーブ処理[wave.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "wave_two.h"

const CWave_Two::EnemyInfo CWave_Two::ENEMY_INFO[NUM_ENEMY]
{
	{{100.0f,0.0f,100.0f},CEnemy::ENEMY_000},
	{{-100.0f,0.0f,100.0f},CEnemy::ENEMY_000},
	{{0.0f,0.0f,50.0f},CEnemy::ENEMY_001},
	{{100.0f,0.0f,0.0f},CEnemy::ENEMY_000},
	{{-100.0f,0.0f,0.0f},CEnemy::ENEMY_000},
};

//=============================================
//コンストラクタ
//=============================================
CWave_Two::CWave_Two()
{
}

//=============================================
//デストラクタ
//=============================================
CWave_Two::~CWave_Two()
{
}

//=============================================
//初期化
//=============================================
HRESULT CWave_Two::Init()
{
	//初期化
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
void CWave_Two::Uninit()
{
	CWave::Uninit();
}

//=============================================
//更新
//=============================================
void CWave_Two::Update()
{
	CWave::Update();
}
