//======================================
//
//	リザルトの処理[result.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "result.h"
#include "manager.h"
#include "camera_result.h"
#include "cleartime.h"

//定数
const D3DXVECTOR3 CResult::TIME_POS = { SCREEN_WIDTH * 0.4f, 355.0f, 0.0f };

//============================
//リザルトのコンストラクタ
//============================
CResult::CResult()
{
	
}

//============================
//リザルトのデストラクタ
//============================
CResult::~CResult()
{
	//フォグの設定
	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
}

//============================
//リザルトの初期化
//============================
HRESULT CResult::Init()
{
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_RESULT);

	//カメラを切り替え
	CManager::GetInstance()->ChangeCamera(new CCamera_Result());

	//クリアタイムの初期化
	CClearTime::GetInstance()->SetPos(TIME_POS);
	CClearTime::GetInstance()->Init();
	
	return S_OK;
}

//============================
//リザルトの終了処理
//============================
void CResult::Uninit()
{
	CManager::GetInstance()->GetSound()->Stop();	//終了処理

	//終了処理
	CScene::Uninit();
}

//============================
//リザルトの更新処理
//============================
void CResult::Update()
{
	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	//フェードが終わっていたら更新
	if (CManager::GetInstance()->GetFade()->GetEnd())
	{
		//エンターで画面遷移
		if (pManager->GetKeyboard()->GetTrigger(DIK_RETURN) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_A) || pManager->GetJoypad()->GetPress(CInputJoypad::JOYKEY_START))
		{
			//タイトルに画面遷移
			pManager->GetFade()->SetFade(CScene::MODE_TITLE);
		}
	}
}

//============================
//リザルトの描画処理
//============================
void CResult::Draw()
{

}