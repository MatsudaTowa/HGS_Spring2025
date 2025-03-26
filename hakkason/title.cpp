//======================================
//
//	タイトルの処理[title.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "title.h"
#include "manager.h"
#include "title_screen.h"

//============================
//タイトルのコンストラクタ
//============================
CTitle::CTitle()
{
	
}

//============================
//タイトルのデストラクタ
//============================
CTitle::~CTitle()
{
	//フォグの設定
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//タイトルの初期化
//============================
HRESULT CTitle::Init()
{
	CTitleScreen::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_TITLE);
	return S_OK;
}

//============================
//タイトルの終了処理
//============================
void CTitle::Uninit()
{
	CManager::GetInstance()->GetSound()->Stop();	//終了処理
	CScene::Uninit();
}

//============================
//タイトルの更新処理
//============================
void CTitle::Update()
{
	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	//フェードが終わっていたら更新
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//エンターで画面遷移
		if (pManager->GetMouse()->GetTrigger((CInputMouse::MOUSEBUTTON_LEFT))||pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//ゲームに画面遷移
			pManager->GetFade()->SetFade(CScene::MODE_TUORIAL);
		}
	}
}

//============================
//タイトルの描画処理
//============================
void CTitle::Draw()
{
}

