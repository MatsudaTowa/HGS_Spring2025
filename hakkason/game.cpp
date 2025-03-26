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
	m_bPause(false)		//ポーズ判定
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

	CEnemy::Create({VEC3_RESET_ZERO}, CEnemy::ENEMY_000);
	CPlayer::Create();
	CField::Create();
	
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