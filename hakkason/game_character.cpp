//======================================
//
//	キャラクターの処理[game_character.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "game_character.h"
#include "manager.h"
#include "game.h"

//定数の設定
const float CGame_Character::GRAVITY = 0.6f;											//重力の強さ
const D3DXVECTOR3 CGame_Character::COLLISION_OFFSET = D3DXVECTOR3(0.0f, 30.0f, 0.0f);	//コリジョンのオフセット

//============================
//キャラクターのコンストラクタ
//============================
CGame_Character::CGame_Character(int nPriority) : CCharacter(nPriority)
{
	//各パラメータの初期化
	m_nLife = LIFE;							//体力
	m_bOnStand = false;						//立ち状態
	m_fRadiusSize = SIZE_RADIUS;			//サイズの半径

	//当たり判定の生成
	if (m_pCollision == nullptr)
	{
		m_pCollision = CCollision::Create(GetSizeRadius(), COLLISION_OFFSET);
	}

	//ゲームタグを設定
	SetTag(CObject::TAG_GAME);
}

//============================
//キャラクターのデストラクタ
//============================
CGame_Character::~CGame_Character()
{
	//当たり判定の消去
	if (m_pCollision != nullptr)
	{
		m_pCollision->Uninit();
		m_pCollision = nullptr;
	}
}

//============================
//キャラクターの初期化
//============================
HRESULT CGame_Character::Init()
{
	//初期化
	CCharacter::Init();

	//当たり判定の位置の更新
	m_pCollision->Update(GetPos());

	return S_OK;
}

//============================
//キャラクターの終了処理
//============================
void CGame_Character::Uninit()
{
	//終了処理
	CCharacter::Uninit();
}

//============================
//キャラクターの更新
//============================
void CGame_Character::Update()
{
	//位置の更新
	UpdatePos();

	//向きの更新
	UpdateRot();

	//モーションの更新
	UpdateMotion();

	//当たり判定の位置の更新
	m_pCollision->Update(GetPos());
}

//============================
//位置の更新
//============================
void CGame_Character::UpdatePos()
{
	//パラメータの取得
	D3DXVECTOR3 pos = CCharacter::GetPos();			//位置
	D3DXVECTOR3 OldPos = CCharacter::GetOldPos();	//前回の位置
	D3DXVECTOR3 Move = CCharacter::GetMove();		//移動量

	//前回の位置を保存
	OldPos = pos;

	//ゲームシーンなら判定
	if (CManager::GetInstance()->GetScene()->GetMode() == CManager::GetInstance()->GetScene()->MODE_GAME)
	{
		//ゲームシーンの取得
		CGame* pGame = dynamic_cast<CGame*>(CManager::GetInstance()->GetScene());

		//位置に移動量を加算
		pos += Move;
	}

	//移動量を減衰
	Move.x += (0.0f - Move.x) * 0.5f;
	Move.z += (0.0f - Move.z) * 0.5f;

	//パラメータの設定
	CCharacter::SetPos(pos);		//位置
	CCharacter::SetOldPos(OldPos);	//前回の位置
	CCharacter::SetMove(Move);		//移動量
}

//============================
//重力の処理
//============================
D3DXVECTOR3 CGame_Character::GravityMove(D3DXVECTOR3 move)
{
	//空中にいるなら重力を加算
	if (!m_bOnStand)
	{
		//ゲームシーンなら判定
		if (CManager::GetInstance()->GetScene()->GetMode() == CManager::GetInstance()->GetScene()->MODE_GAME)
		{
			//ゲームシーンの取得
			CGame* pGame = dynamic_cast<CGame*>(CManager::GetInstance()->GetScene());

			move.y -= GRAVITY;
		}
	}
	else
	{
		//着地していて落ちていたら補正
		if (move.y < 0.0f)
		{
			move.y = 0.0f;
		}
	}

	return move;
}

//============================
//キャラクターのダメージを設定
//============================
bool CGame_Character::SetDamage(int damage)
{
	//ダメージを受ける
	m_nLife -= damage;

	//0未満なら0にする
	if (m_nLife <= 0)
	{
		m_nLife = 0;

		//死亡時の処理
		SetCharacterDeath();
	}

	return true;
}

//============================
//死亡時の処理
//============================
void CGame_Character::SetCharacterDeath()
{
	//終了処理
	Uninit();
}

//============================
//キャラクターの描画処理
//============================
void CGame_Character::Draw()
{
	CCharacter::Draw();
}