//======================================
//
//	エネミーの処理[enemy.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "enemy.h"
#include "gamemanager.h"
#include "enemy_000.h"
#include "manager.h"

//============================
//エネミーのコンストラクタ
//============================
CEnemy::CEnemy(int nPriority) :
	CGame_Character(nPriority),	//親のコンストラクタ
	m_ShotFrame(0),				//発射フレーム
	m_ShotFrame_Cnt(0)			//発射カウント
{
	//マネージャーに登録
	CGameManager::GetInstance()->GetEnemyManager()->Regist(this);
}

//============================
//エネミーのデストラクタ
//============================
CEnemy::~CEnemy()
{
	//マネージャーから削除
	if (CGameManager::GetInstance()->GetEnemyManager() != nullptr)
	{
		CGameManager::GetInstance()->GetEnemyManager()->Erase(this);
	}
}

//============================
//エネミーの初期化
//============================
HRESULT CEnemy::Init()
{
	//初期化
	CGame_Character::Init();

	return S_OK;
}

//============================
//エネミーの終了処理
//============================
void CEnemy::Uninit()
{
	//死亡フラグが立っていたら抜ける
	if (GetDeath())
	{
		return;
	}

	//初期化
	CCharacter::Uninit();
}

//============================
//エネミーの更新
//============================
void CEnemy::Update()
{
	//共通処理の更新
	CGame_Character::Update();

	//マネージャーのインスタンスを取得
	CManager* pManager = CManager::GetInstance();

	++m_ShotFrame_Cnt;

	if (m_ShotFrame_Cnt > m_ShotFrame)
	{
		m_ShotFrame_Cnt = 0;
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f);
	}

#ifdef _DEBUG
	if (pManager->GetKeyboard()->GetTrigger(DIK_TAB))
	{
		SetDamage(1);
	}

#endif // _DEBUG
}

//============================
//エネミーの描画
//============================
void CEnemy::Draw()
{
	CGame_Character::Draw();
}

//============================
//エネミーのクリエイト
//============================
CEnemy* CEnemy::Create(D3DXVECTOR3 pos, ENEMY_TYPE type)
{
	//種類に応じて動的確保
	CEnemy* pEnemy = nullptr;

	switch (type)
	{
	case CEnemy::ENEMY_000:
		pEnemy = new CEnemy_000;
		break;
	default:
		assert("範囲外のエネミータイプです");
		break;
	}

	//位置の設定
	pEnemy->SetPos(pos);

	//初期化
	pEnemy->Init();

	//設定した情報を返す
	return pEnemy;
}

//============================
//ダメージの設定
//============================
bool CEnemy::SetDamage(int damage)
{
	//ダメージの設定
	CGame_Character::SetDamage(damage);

	return true;
}