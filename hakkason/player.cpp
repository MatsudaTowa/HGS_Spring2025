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
#include "bullet.h"
#include "gamemanager.h"
#include "effect_hit.h"

//静的メンバの初期化
const std::string CPlayer::FILEPATH = "data\\MODEL\\player001.x";

//============================
//プレイヤーのコンストラクタ
//============================
CPlayer::CPlayer(int nPriority) : CGame_Character(nPriority),
	m_nAttackCoolTime(0),		//攻撃のクールタイム
	m_nAttackTrrigerCount(0),	//攻撃発動のカウント
	m_pLifeGauge(nullptr)		//体力ゲージのポインタ
{
	CGame_Character::GetCollision()->SetRadius(13.0f);
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
	CCharacter::SetPos({ 0.0f, 0.0f, -100.0f });
	CCharacter::SetGoalRot({ 0.0f, D3DX_PI, 0.0f });

	//モーションの読み込み
	SetMotionInfo("data\\playermotion000.txt");

	//ゲージの生成
	if (m_pLifeGauge == nullptr)
	{
		m_pLifeGauge = CGauge_PlayerLife::Create(MAX_LIFE);
	}

	//仮のライフ設定
	SetLife(MAX_LIFE);

	CGameManager::GetInstance()->SetPlayer(this);

	return S_OK;
}

//============================
//プレイヤーの終了処理
//============================
void CPlayer::Uninit()
{
	//初期化
	CGame_Character::Uninit();

	//ゲージの消去
	if (m_pLifeGauge != nullptr)
	{
		m_pLifeGauge->Uninit();
		m_pLifeGauge = nullptr;
	}
}

//============================
//プレイヤーの更新
//============================
void CPlayer::Update()
{
	//クールタイムの更新
	UpdateCoolTime();

	//操作の処理
	UpdateOperation();

	//共通処理の更新
	CGame_Character::Update();
}

//============================
//操作の更新
//============================
void CPlayer::UpdateOperation()
{
	Collision();

	//確認
	if (m_nAttackCoolTime > 0) return;

	Move();

	Attack();

	Limit();
}

//============================
//移動処理
//============================
void CPlayer::Move()
{
	//判定用
	bool bPressKey = false;
	CCamera* pCamera = CManager::GetInstance()->GetCamera();
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 Rotgoal = GetGoalRot();

	if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_A))
	{//Aキーが押された場合
		if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
		{
			move.x += sinf(D3DX_PI * -0.75f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * -0.75f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * 0.75f/* + pCamera->GetRot().y*/;
		}
		else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
		{
			move.x += sinf(D3DX_PI * -0.25f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * -0.25f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * 0.25f/* + pCamera->GetRot().y*/;
		}
		else
		{
			move.x += sinf(D3DX_PI * -0.5f + pCamera->GetRot().y) * 1.0f;
			move.z += cosf(D3DX_PI * -0.5f + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = -(D3DX_PI * -0.5f/* - pCamera->GetRot().y*/);
		}

		bPressKey = true;	//キーボードを触っている
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_D))
	{//Dキーが押された場合

		if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
		{
			move.x += sinf(D3DX_PI * 0.75f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * 0.75f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * -0.75f/* + pCamera->GetRot().y*/;
		}
		else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
		{
			move.x += sinf(D3DX_PI * 0.25f - pCamera->GetRot().y) * 1.0f;
			move.z -= cosf(D3DX_PI * 0.25f - pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI * -0.25f/* + pCamera->GetRot().y*/;
		}
		else
		{
			move.x += sinf(D3DX_PI * 0.5f + pCamera->GetRot().y) * 1.0f;
			move.z += cosf(D3DX_PI * 0.5f + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = -(D3DX_PI * 0.5f/* - pCamera->GetRot().y*/);
		}

		bPressKey = true;	//キーボードを触っている
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_W))
	{//Wキーが押された場合
		{
			move.z -= cosf(D3DX_PI + pCamera->GetRot().y) * 1.0f;
			move.x -= sinf(D3DX_PI + pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = D3DX_PI/* + pCamera->GetRot().y*/;
		}

		bPressKey = true;	//キーボードを触っている
	}
	else if (CManager::GetInstance()->GetKeyboard()->GetPress(DIK_S))
	{//Sキーが押された場合
		{
			move.z -= cosf(pCamera->GetRot().y) * 1.0f;
			move.x -= sinf(pCamera->GetRot().y) * 1.0f;
			Rotgoal.y = pCamera->GetRot().y;
		}

		bPressKey = true;	//キーボードを触っている
	}

	SetMove(move);
	SetGoalRot(Rotgoal);

	//モーションを設定
	if (bPressKey)
	{
		if (GetMotionState() != CPlayer::PLAYERMOTION_WALK)
		{
			SetMotion(CPlayer::PLAYERMOTION_WALK);
		}
	}
	else
	{
		if (GetMotionState() != CPlayer::PLAYERMOTION_NORMAL)
		{
			SetMotion(CPlayer::PLAYERMOTION_NORMAL);
		}
	}
}

//============================
//攻撃処理
//============================
void CPlayer::Attack()
{
	//攻撃を押したら
	if (CManager::GetInstance()->GetMouse()->GetTrigger(CInputMouse::MOUSEBUTTON_LEFT))
	{
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SWING);

		SetMotion(CPlayer::PLAYERMOTION_ACTION);	//モーション設定
		m_nAttackCoolTime = ATTACK_COOLTIME;		//クールタイムを設定
		//CBullet::Create(GetPos(), GetGoalRot().y + D3DX_PI, 1.0f, true);
	}
}

//============================
//クールタイムの更新
//============================
void CPlayer::UpdateCoolTime()
{
	//クールタイムを減らす
	if (m_nAttackCoolTime <= 0) return;

	m_nAttackTrrigerCount++;

	if (m_nAttackTrrigerCount == ATTACK_TRRIGER)
	{
		//バレットリスト
		std::list<CBullet*> BulletList = CGameManager::GetInstance()->GetBulletManager()->GetList();

		//攻撃判定の生成
		D3DXVECTOR3 AttackPos = GetPos();
		AttackPos += {sinf(GetRot().y + D3DX_PI)* 5.0f, 0.0f, cosf(GetRot().y + D3DX_PI)* 5.0f};

		for (auto& iter : BulletList)
		{
			float fXZ = sqrtf((iter->GetPos().x - AttackPos.x) * (iter->GetPos().x - AttackPos.x) + (iter->GetPos().z - AttackPos.z) * (iter->GetPos().z - AttackPos.z)); //距離を算出する


			if (fXZ <= 45.0f && !iter->GetPlayerBullet())
			{
				CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_REFRECT);

				iter->GetSpeed() *= -1.3f;
				iter->GetHansya()++;
			}
		}
	}

	m_nAttackCoolTime--;

	if (m_nAttackCoolTime <= 0) m_nAttackTrrigerCount = 0;
}

//============================
//制限
//============================
void CPlayer::Limit()
{
	if (GetPos().z > -100.0f)
	{
		GetPos().z = -100.0f;
	}

	if (GetPos().z < -150.0f)
	{
		GetPos().z = -150.0f;
	}

	if (GetPos().x + GetCollision()->GetRadius() > 150.0f)
	{
		GetPos().x = 150.0f - GetCollision()->GetRadius();
	}

	if (GetPos().x - GetCollision()->GetRadius() < -150.0f)
	{
		GetPos().x = -150.0f + GetCollision()->GetRadius();
	}
}

//============================
//当たり判定
//============================
void CPlayer::Collision()
{
	//バレットリスト
	std::list<CBullet*> BulletList = CGameManager::GetInstance()->GetBulletManager()->GetList();

	for (auto& iter : BulletList)
	{
		float fXZ = sqrtf((iter->GetPos().x - GetPos().x) * (iter->GetPos().x - GetPos().x) + (iter->GetPos().z - GetPos().z) * (iter->GetPos().z - GetPos().z)); //距離を算出する

		if (fXZ <= 15.0f && !iter->GetPlayerBullet())
		{
			CEffect_Hit::Create({ GetPos().x, 5.0f,  GetPos().z });
			iter->Uninit();
			SetDamage(1);
		}
	}
}

//============================
//ダメージ時の処理
//============================
bool CPlayer::SetDamage(int damage)
{
	//体力がないなら更新しない
	if (GetLife() <= 0)
	{
		return false;
	}

	//死亡フラグが立っていたら抜ける
	if (GetDeath())
	{
		return true;
	}

	//ダメージを受ける
	SetLife(GetLife() - damage);

	//インスタンスの取得
	CGauge_PlayerLife* pGauge = GetLifeGauge();

	//体力ゲージに反映
	if (pGauge != nullptr)
	{
		//ゲージに反映
		pGauge->GetGauge()->AddGauge(-(float)damage);
	}

	//体力ゲージを設定
	SetLifeGauge(pGauge);

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