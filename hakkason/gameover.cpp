//======================================
//
//	タイトルの処理[gameover.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "gameover.h"
#include "manager.h"
#include "gameover_bg.h"

//============================
//タイトルのコンストラクタ
//============================
CGameover::CGameover()
{

}

//============================
//タイトルのデストラクタ
//============================
CGameover::~CGameover()
{
	//フォグの設定
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//タイトルの初期化
//============================
HRESULT CGameover::Init()
{
	CGameOver_Bg::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });

	return S_OK;
}

//============================
//タイトルの終了処理
//============================
void CGameover::Uninit()
{
	//終了処理
	CScene::Uninit();
}

//============================
//タイトルの更新処理
//============================
void CGameover::Update()
{
	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	//フェードが終わっていたら更新
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//エンターで画面遷移
		if (pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//ゲームに画面遷移
			pManager->GetFade()->SetFade(CScene::MODE_TITLE);
		}
	}
}

//============================
//タイトルの描画処理
//============================
void CGameover::Draw()
{

}