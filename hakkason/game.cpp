//======================================
//
//	ゲームの処理[game.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "game.h"
#include "manager.h"
#include "camera_game.h"
#include "player.h"
#include "field.h"
#include "enemy.h"
#include "gamemanager.h"

//定数
const D3DXVECTOR3 CGame::TIME_POS = { SCREEN_WIDTH * 0.4f, 50.0f, 0.0f };
const std::string CGame::FILEPATH_MODEL = "data\\FILE\\model.bin";

//============================
//ゲームのコンストラクタ
//============================
CGame::CGame() :
	m_bClear(false),	//クリア判定
	m_bPause(false),	//ポーズ判定
	m_next_wave(),		//次のウェーブ格納変数
	m_pWave(nullptr)	//ウェーブ
{
	CGameManager::GetInstance()->Init();
}

//============================
//ゲームのデストラクタ
//============================
CGame::~CGame()
{
	//フォグの設定
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	CGameManager::GetInstance()->Uninit();
}

//============================
//ゲームの初期化
//============================
HRESULT CGame::Init()
{
	//カメラを切り替え
	CManager::GetInstance()->ChangeCamera(new CCamera_Game());

	CPlayer::Create();
	CField::Create();

	SetWave(CWave::WAVE::ONE);

	return S_OK;
}

//============================
//ゲームの終了処理
//============================
void CGame::Uninit()
{
	//終了処理
	CScene::Uninit();
}

//============================
//ゲームの更新処理
//============================
void CGame::Update()
{
	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	if (CGameManager::GetInstance()->GetEnemyManager()->GetList().size() <= 0)
	{
		switch (m_pWave->GetCurrentWave())
		{
		case CWave::WAVE::ONE:
			m_next_wave = CWave::WAVE::TWO;
			break;
		case CWave::WAVE::TWO:
			m_next_wave = CWave::WAVE::THREE;
			break;
		case CWave::WAVE::THREE:
			m_next_wave = CWave::WAVE::NONE;
			break;
		default:
			assert("範囲外のウェーブです");
			break;
		}

		if (m_next_wave != CWave::WAVE::NONE)
		{
			SetWave(m_next_wave);
		}
		else if (m_next_wave == CWave::WAVE::NONE)
		{
			//マネージャーのインスタンスを取得
			CManager* pManager = CManager::GetInstance();

			//リザルトに画面遷移
			pManager->GetFade()->SetFade(CScene::MODE_RESULT);
		}
	}

	if (m_pWave != nullptr)
	{
		m_pWave->Update();
	}
}

//============================
//ゲームの描画処理
//============================
void CGame::Draw()
{

}

//============================
//ゲームの読み込み
//============================
void CGame::Load()
{

}

//============================
//ポーズの設定
//============================
void CGame::SetPause()
{
	m_bPause = m_bPause ? false : true;
}
