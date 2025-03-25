//======================================
//
//	プレイヤーの処理[player.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "player.h"
#include "manager.h"
#include "game.h"
#include "modelparts.h"
#include "camera.h"

//静的メンバの初期化
const std::string CPlayer::FILEPATH = "data\\MODEL\\player001.x";

//============================
//プレイヤーのコンストラクタ
//============================
CPlayer::CPlayer(int nPriority) : CGame_Character(nPriority)
{
	
}

//============================
//プレイヤーのデストラクタ
//============================
CPlayer::~CPlayer()
{
	
}

//============================
//プレイヤーの初期化
//============================
HRESULT CPlayer::Init()
{
	//初期化
	CGame_Character::Init();

	//パラメータの初期化
	CCharacter::SetRot({ 0.0f, 0.0f, 0.0f });
	CCharacter::SetPos({ 0.0f, 0.0f, 0.0f });
	CCharacter::SetGoalRot({ 0.0f, D3DX_PI, 0.0f });
	
	//モーションの読み込み
	SetMotionInfo("data\\playermotion000.txt");

	//仮のライフ設定
	SetLife(MAX_LIFE);

	return S_OK;
}

//============================
//プレイヤーの終了処理
//============================
void CPlayer::Uninit()
{
	//初期化
	CGame_Character::Uninit();
}

//============================
//プレイヤーの更新
//============================
void CPlayer::Update()
{
	//共通処理の更新
	CGame_Character::Update();
}

//============================
//ダメージ時の処理
//============================
bool CPlayer::SetDamage(int damage, float angle)
{
	//ダメージを受ける
	SetLife(GetLife() - damage);

	//ダメージの設定
	return true;
}

//============================
//プレイヤーの描画
//============================
void CPlayer::Draw()
{
	//キャラクタークラスの描画
	CCharacter::Draw();
}

//============================
//プレイヤーのクリエイト
//============================
CPlayer* CPlayer::Create()
{
	//ポインタ用の変数
	CPlayer* pPlayer;

	//メモリの確保
	pPlayer = new CPlayer;

	//初期化
	pPlayer->Init();

	return pPlayer;
}