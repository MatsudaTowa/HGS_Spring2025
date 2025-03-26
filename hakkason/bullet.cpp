//======================================
//
//	バレットの処理[bullet.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "bullet.h"
#include "manager.h"

//定数の初期化
const std::string CBullet::FILEPATH = "data\\MODEL\\bullet.x";

//============================
//コンストラクタ
//============================
CBullet::CBullet(int nPriority) : CObjectX(nPriority),
	m_Speed({0.0f, 0.0f, 0.0f})
{
	
}

//============================
//デストラクタ
//============================
CBullet::~CBullet()
{

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
	//位置の更新
	SetPos(GetPos() + m_Speed);
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
CBullet* CBullet::Create(D3DXVECTOR3 pos, float rot, float speed)
{
	//ポインタ用の変数
	CBullet* pObjectX;

	//メモリの確保
	pObjectX = new CBullet;

	//パラメータの設定
	pObjectX->SetPos(pos);					//位置の設定
	pObjectX->SetRot({ 0.0f, rot , 0.0f });	//向き
	pObjectX->m_Speed = { sinf(rot) * speed, 0.0f, cosf(rot) * speed };	//速度

	//初期化
	pObjectX->Init();

	return pObjectX;
}