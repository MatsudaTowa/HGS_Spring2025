//======================================
//
//	バレットの処理[bullet.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "bullet.h"
#include "manager.h"
#include "gamemanager.h"
#include "bulletmanager.h"
#include "effect_hit.h"

//定数の初期化
const std::string CBullet::FILEPATH = "data\\MODEL\\bullet.x";

//============================
//コンストラクタ
//============================
CBullet::CBullet(int nPriority) : CObjectX(nPriority),
m_Speed({ 0.0f, 0.0f, 0.0f }),
m_OldPos({ 0.0f, 0.0f, 0.0f }),
m_bPlayerBullet(false),
m_nHansya(0)
{
	//マネージャーに登録
	if (CGameManager::GetInstance()->GetBulletManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBulletManager()->Regist(this);
	}
}

//============================
//デストラクタ
//============================
CBullet::~CBullet()
{
	//マネージャーから削除
	if (CGameManager::GetInstance()->GetBulletManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBulletManager()->Erase(this);
	}
}

//============================
//初期化
//============================
HRESULT CBullet::Init()
{
	return S_OK;
}

//============================
//終了処理
//============================
void CBullet::Uninit()
{
	//消去
	SetDeath();
}

//============================
//更新
//============================
void CBullet::Update()
{
	//過去の位置
	m_OldPos = GetPos();

	//位置の更新
	SetPos(GetPos() + m_Speed);

	Collision();

	GetRot().y = atan2f(m_Speed.x, m_Speed.z);

	if (!CManager::GetInstance()->GetCamera()->GetViewObject(GetPos()))
	{
		Uninit();
	}

	if (m_nHansya >= MAX_HANSYA)
	{
		Uninit();
	}
	
}

//============================
//当たり判定
//============================
void CBullet::Collision()
{
	//Xファイルの読み込み
	CXfile* pCXfile = CManager::GetInstance()->GetXfile();

	//敵リスト
	std::list<CEnemy*> EnemyList = CGameManager::GetInstance()->GetEnemyManager()->GetList();

	//エネミーのサイズを取得する変数
	D3DXVECTOR3 MaxSize = pCXfile->GetAddress(pCXfile->Regist(CBullet::FILEPATH.c_str())).aSize.Max;
	D3DXVECTOR3 MinSize = pCXfile->GetAddress(pCXfile->Regist(CBullet::FILEPATH.c_str())).aSize.Min;

	for (auto& iter : EnemyList)
	{
		bool bHit = false;

		//上の判定
		if (GetPos().z + (MinSize.z) <= iter->GetPos().z + iter->GetCollision()->GetRadius()
			&& GetPos().x + (MinSize.z) < iter->GetPos().x + (iter->GetCollision()->GetRadius())
			&& GetPos().x + (MaxSize.z) > iter->GetPos().x - (iter->GetCollision()->GetRadius())
			)
		{
			if (m_OldPos.z + (MinSize.z) >= iter->GetPos().z + iter->GetCollision()->GetRadius())
			{
				//位置の補正
				GetPos().z = iter->GetPos().z + iter->GetCollision()->GetRadius() - (MinSize.z);
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//下の判定
		if (GetPos().z + (MaxSize.z) > iter->GetPos().z - iter->GetCollision()->GetRadius()
			&& m_OldPos.x + (MinSize.x) < iter->GetPos().x + iter->GetCollision()->GetRadius()
			&& m_OldPos.x + (MaxSize.x) > iter->GetPos().x - iter->GetCollision()->GetRadius())
		{
			if (m_OldPos.z + MaxSize.z <= iter->GetPos().z - (iter->GetCollision()->GetRadius()))
			{
				GetPos().z = iter->GetPos().z - iter->GetCollision()->GetRadius() - MaxSize.z;
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//右の判定
		if (GetPos().x - (MaxSize.z) < iter->GetPos().x + iter->GetCollision()->GetRadius() &&
			m_OldPos.x - (MaxSize.z) >= iter->GetPos().x + iter->GetCollision()->GetRadius())
		{
			if (GetPos().z + MaxSize.z > iter->GetPos().z - iter->GetCollision()->GetRadius()
				&& GetPos().z + MinSize.z < iter->GetPos().z + iter->GetCollision()->GetRadius())
			{
				GetPos().x = iter->GetPos().x + iter->GetCollision()->GetRadius() + MaxSize.z;
				m_Speed.x *= -1.0f;
				bHit = true;
			}
		}

		//左の判定
		if (GetPos().x + (MaxSize.z) > iter->GetPos().x - iter->GetCollision()->GetRadius() &&
			m_OldPos.x + (MaxSize.z) <= iter->GetPos().x - iter->GetCollision()->GetRadius())
		{
			if (GetPos().z + MaxSize.z > iter->GetPos().z - iter->GetCollision()->GetRadius()
				&& GetPos().z + MinSize.z < iter->GetPos().z + iter->GetCollision()->GetRadius())
			{
				GetPos().x = iter->GetPos().x - iter->GetCollision()->GetRadius() - (MaxSize.z);
				m_Speed.x *= -1.0f;
				bHit = true;
			}
		}

		if (bHit)
		{
			CEffect_Hit::Create({ GetPos().x, 5.0f,  GetPos().z});
			iter->SetDamage(1);
			m_bPlayerBullet = false;
			m_nHansya++;
		}
	}

	//敵リスト
	std::list<CBlock*> BlockList = CGameManager::GetInstance()->GetBlockManager()->GetList();

	for (auto& iter : BlockList)
	{
		bool bHit = false;

		//上の判定
		if (GetPos().z + (MinSize.z) <= iter->GetPos().z + 10.0f
			&& GetPos().x + (MinSize.z) < iter->GetPos().x + (10.0f)
			&& GetPos().x + (MaxSize.z) > iter->GetPos().x - (10.0f)
			)
		{
			if (m_OldPos.z + (MinSize.z) >= iter->GetPos().z + 10.0f)
			{
				//位置の補正
				GetPos().z = iter->GetPos().z + 10.0f - (MinSize.z);
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//下の判定
		if (GetPos().z + (MaxSize.z) > iter->GetPos().z - 10.0f
			&& m_OldPos.x + (MinSize.x) < iter->GetPos().x + 10.0f
			&& m_OldPos.x + (MaxSize.x) > iter->GetPos().x - 10.0f)
		{
			if (m_OldPos.z + MaxSize.z <= iter->GetPos().z - (10.0f))
			{
				GetPos().z = iter->GetPos().z - 10.0f - MaxSize.z;
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//右の判定
		if (GetPos().x - (MaxSize.z) < iter->GetPos().x + 10.0f &&
			m_OldPos.x - (MaxSize.z) >= iter->GetPos().x + 10.0f)
		{
			if (GetPos().z + MaxSize.z > iter->GetPos().z - 10.0f
				&& GetPos().z + MinSize.z < iter->GetPos().z + 10.0f)
			{
				GetPos().x = iter->GetPos().x + 10.0f + MaxSize.x;
				m_Speed.x *= -1.0f;
				bHit = true;
			}
		}

		//左の判定
		if (GetPos().x + (MaxSize.z) > iter->GetPos().x - 10.0f &&
			m_OldPos.x + (MaxSize.z) <= iter->GetPos().x - 10.0f)
		{
			if (GetPos().z + MaxSize.z > iter->GetPos().z - 10.0f
				&& GetPos().z + MinSize.z < iter->GetPos().z + 10.0f)
			{
				GetPos().x = iter->GetPos().x - 10.0f - (MaxSize.x);
				m_Speed.x *= -1.0f;
				bHit = true;
			}
		}

		if (bHit)
		{
			m_bPlayerBullet = false;
			m_nHansya++;
		}
	}

	if (GetPos().x + MaxSize.x > 150.0f)
	{
		GetPos().x = 150.0f - MaxSize.x;
		m_Speed.x *= -1.0f;
		m_bPlayerBullet = false;
		m_nHansya++;
	}

	if (GetPos().x + MinSize.x < -150.0f)
	{
		GetPos().x = -150.0f - MinSize.x;
		m_Speed.x *= -1.0f;
		m_bPlayerBullet = false;
		m_nHansya++;
	}

	if (GetPos().z + MaxSize.z > 172.0f)
	{
		GetPos().z = 172.0f - MaxSize.z;
		m_Speed.z *= -1.0f;
		m_bPlayerBullet = false;
		m_nHansya++;
	}
}

//============================
//描画
//============================
void CBullet::Draw()
{
	//ローカル変数宣言
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	D3DXMATRIX mtxRot, mtxTrans, mtxScale;								//計算用マトリックス
	D3DMATERIAL9 matDef;												//現在のマテリアル保存用
	D3DXMATERIAL* pMat;													//マテリアルデータへのポインタ
	D3DXVECTOR3 Pos = GetPos();											//位置の取得

	//Xファイルの読み込み
	CXfile* pCXfile = CManager::GetInstance()->GetXfile();

	//ワールドの初期化
	D3DXMatrixIdentity(&GetMtx());

	//スケールを反映
	D3DXMatrixScaling(&mtxScale, GetScale().x, GetScale().y, GetScale().z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxScale);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, Pos.x, Pos.y, Pos.z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &GetMtx());

	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pBuffmat->GetBufferPointer();

	//テクスチャの数をカウント
	int nTextureCount = 0;

	//マテリアルの数だけ周回
	for (int nCntMat = 0; nCntMat < (int)pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).dwNumMat; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//テクスチャがあったら
		if (pMat[nCntMat].pTextureFilename != NULL)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pTexture[nTextureCount]);

			//テクスチャ用のカウントを進める
			nTextureCount++;
		}
		else
		{
			//テクスチャを設定しない
			pDevice->SetTexture(0, NULL);
		}

		//オブジェクトX(パーツ)の描画
		pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pMesh->DrawSubset(nCntMat);
	}

	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	//位置の設定
	SetPos(Pos);
}

//============================
//クリエイト
//============================
CBullet* CBullet::Create(D3DXVECTOR3 pos, float rot, float speed, bool player)
{
	//ポインタ用の変数
	CBullet* pObjectX;

	//メモリの確保
	pObjectX = new CBullet;

	//パラメータの設定
	pObjectX->SetPos(pos);					//位置の設定
	pObjectX->SetRot({ 0.0f, rot , 0.0f });	//向き
	pObjectX->m_Speed = { sinf(rot) * speed, 0.0f, cosf(rot) * speed };	//速度
	pObjectX->m_bPlayerBullet = player;

	//初期化
	pObjectX->Init();

	return pObjectX;
}