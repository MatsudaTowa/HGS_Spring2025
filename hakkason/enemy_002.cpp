//================================
//
//enemy_000.cppに必要な宣言[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_002.h"
#include "bullet.h"
#include "enemy_002_state.h"

//静的メンバの初期化
const std::string CEnemy_002::FILEPATH = "data\\motion_enemy002.txt";

//================================
// コンストラクタ
//================================
CEnemy_002::CEnemy_002(int nPriority) :CEnemy(nPriority),
m_pState(nullptr)
{
}

//================================
// デストラクタ
//================================
CEnemy_002::~CEnemy_002()
{
	if (m_pState != nullptr)
	{
		delete m_pState;
	}
}

//================================
// 初期化
//================================
HRESULT CEnemy_002::Init()
{
	//初期化
	CGame_Character::Init();

	//ボスのステート生成
	if (m_pState == nullptr)
	{
		//最初は徘徊状態
		m_pState = new CEnemy_002_Shot;
	}

	SetShotFrame(SHOT_FRAME);

	//モーションの読み込み
	SetMotionInfo(FILEPATH.c_str());

	//仮のライフ設定
	SetLife(LIFE);

	return S_OK;
}

//================================
// 終了
//================================
void CEnemy_002::Uninit()
{
	//終了
	CGame_Character::Uninit();
}

//================================
// 更新
//================================
void CEnemy_002::Update()
{
	//更新
	CEnemy::Update();

	if (m_pState != nullptr)
	{
		m_pState->Move(this);
		m_pState->Shot(this);
	}
}

//================================
// 描画
//================================
void CEnemy_002::Draw()
{
	//キャラクタークラスの描画
	CCharacter::Draw();
}

//============================
//弾発射
//============================
void CEnemy_002::ShotBullet()
{
	LockAtPlayer();

	int nCnt = GetShotFrameCnt();
	++nCnt;

	if (nCnt > GetShotFrame())
	{
		nCnt = 0;

		CBullet::Create(GetPos(), GetRot().y + QRTR_PI + D3DX_PI, 1.0f, false);
		CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, false);
		CBullet::Create(GetPos(), GetRot().y - QRTR_PI + D3DX_PI, 1.0f, false);
	}
	SetShotFrameCnt(nCnt);

}
