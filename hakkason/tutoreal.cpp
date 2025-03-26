//======================================
//
//	タイトルの処理[title.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "tutorial.h"
#include "manager.h"
#include "tutorial_screen.h"

//============================
//タイトルのコンストラクタ
//============================
CTutorial::CTutorial()
{

}

//============================
//タイトルのデストラクタ
//============================
CTutorial::~CTutorial()
{
	//フォグの設定
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//タイトルの初期化
//============================
HRESULT CTutorial::Init()
{
	CTutorialScreen::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f,0.0f });
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_GAME);
	return S_OK;
}

//============================
//タイトルの終了処理
//============================
void CTutorial::Uninit()
{
	CScene::Uninit();
}

//============================
//タイトルの更新処理
//============================
void CTutorial::Update()
{
	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	//フェードが終わっていたら更新
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//エンターで画面遷移
		if (pManager->GetMouse()->GetTrigger((CInputMouse::MOUSEBUTTON_LEFT)) || pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//ゲームに画面遷移
			pManager->GetFade()->SetFade(CScene::MODE_GAME);
		}
	}
}

//============================
//タイトルの描画処理
//============================
void CTutorial::Draw()
{

}