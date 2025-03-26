//=============================================
//
//�E�F�[�u����[wave.cpp]
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
//�R���X�g���N�^
//=============================================
CWave_Three::CWave_Three()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CWave_Three::~CWave_Three()
{
}

//=============================================
//������
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
//�I��
//=============================================
void CWave_Three::Uninit()
{
	CWave::Uninit();
}

//=============================================
//�X�V
//=============================================
void CWave_Three::Update()
{
	CWave::Update();
}
