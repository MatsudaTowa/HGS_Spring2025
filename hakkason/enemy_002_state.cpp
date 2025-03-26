#include "enemy_002_state.h"
#include "enemy_002.h"

//=============================================
//発射ステート
//=============================================
void CEnemy_002_Shot::Shot(CEnemy_002* enemy)
{
	enemy->ShotBullet();
}


