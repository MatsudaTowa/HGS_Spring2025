//================================
//
//enemy_000.cppに必要な宣言[enemy_000.cpp]
//Author:yuuto shimadu
// 
//================================
#include "enemy_001.h"

//静的メンバの初期化
const std::string CEnemy_001::FILEPATH = "data\\motion_enemy001.txt";

//================================
// コンストラクタ
//================================
CEnemy_001::CEnemy_001(int nPriority) :CEnemy(nPriority)
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
