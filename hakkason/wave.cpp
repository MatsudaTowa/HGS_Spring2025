//=============================================
//
//ウェーブ処理[wave.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "wave.h"
#include "wave_one.h"
#include "wave_two.h"
#include "wave_three.h"

//=============================================
//コンストラクタ
//=============================================
CWave::CWave():
	m_CurrentWave()
{
}

//=============================================
//デストラクタ
//=============================================
CWave::~CWave()
{
}

//=============================================
//初期化
//=============================================
HRESULT CWave::Init()
{
	return S_OK;
}

//=============================================
//終了
//=============================================
void CWave::Uninit()
{
}

//=============================================
//更新
//=============================================
void CWave::Update()
{
}

//=============================================
//生成
//=============================================
CWave* CWave::Create(WAVE wave)
{
	// インスタンス生成
	CWave* pWave = nullptr;

	// 条件分岐
	switch (wave)
	{
	case WAVE::ONE: // ウェーブ1
		delete pWave;
		pWave = new CWave_One;
		break;

	case WAVE::TWO: //ウェーブ2
		delete pWave;
		pWave = new CWave_Two;
		break;

	case WAVE::THREE: // ウェーブ3

		delete pWave;
		pWave = new CWave_Three;
		break;
	default:
		assert("範囲外のウェーブ");
		break;
	}

	if (pWave != nullptr)
	{
		pWave->m_CurrentWave = wave;
	}
	//今のシーンの初期化
	pWave->Init();

	return pWave;
}
