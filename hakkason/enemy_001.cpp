//================================
//
//enemy_000.cppに必要な宣言[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_001.h"
#include "bullet.h"
#include "manager.h"

//静的メンバの初期化
const std::string CEnemy_001::FILEPATH = "data\\motion_enemy001.txt";

//================================
// コンストラクタ
//================================
CEnemy_001::CEnemy_001(int nPriority) :CEnemy(nPriority),
m_nBurstDelayCnt(0),
m_nShotBullet(0)
{
}

//================================
// デストラクタ
//================================
CEnemy_001::~CEnemy_001()
{
}

//================================
// 初期化
//================================
HRESULT CEnemy_001::Init()
{
	//初期化
	CGame_Character::Init();

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
void CEnemy_001::Uninit()
{
	//終了
	CGame_Character::Uninit();
}

//================================
// 更新
//================================
void CEnemy_001::Update()
{
	//更新
	CEnemy::Update();
	ShotBullet();

}

//================================
// 描画
//================================
void CEnemy_001::Draw()
{
	//キャラクタークラスの描画
	CCharacter::Draw();
}

//================================
// 発射処理
//================================
void CEnemy_001::ShotBullet()
{
	LockAtPlayer();

	int nCnt = GetShotFrameCnt();
	++nCnt;

	if (nCnt > GetShotFrame())
	{
		++m_nBurstDelayCnt;
		if (m_nBurstDelayCnt > BURST_DELAY_FRAME)
		{
			CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SHOT);

			m_nBurstDelayCnt = 0;
			CBullet::Create(GetPos(), GetRot().y + D3DX_PI, 1.0f, false);
			++m_nShotBullet;
			if (m_nShotBullet >= NUM_SHOT)
			{
				m_nShotBullet = 0;
				nCnt = 0;
			}
		}

	}
	SetShotFrameCnt(nCnt);
}
