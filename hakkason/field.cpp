//======================================
//
//	フィールドの処理[field.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//ヘッダーのインクルード
#include "field.h"
#include "manager.h"

//定数
const std::string CField::FILEPATH = "data\\TEXTURE\\FieldTexture000.jpeg";
const D3DXVECTOR3 CField::SIZE = {1000.0f, 0.0f, 1000.0f};	//サイズ
const D3DXVECTOR3 CField::POS = {0.0f, 0.0f, 0.0f};		//位置

//============================
//コンストラクタ
//============================
CField::CField(int nPriority) : CObject3D(nPriority)
{
	
}

//============================
//デストラクタ
//============================
CField::~CField()
{
	
}

//============================
//初期化
//============================
HRESULT CField::Init()
{
	CObject3D::Init();
	return S_OK;
}

//============================
//終了処理
//============================
void CField::Uninit()
{
	CObject3D::Uninit();
}

//============================
//更新
//============================
void CField::Update()
{

}

//============================
//描画
//============================
void CField::Draw()
{
	CObject3D::Draw(FILEPATH.c_str());
}

//============================
//クリエイト
//============================
CField* CField::Create()
{
	//ポインタ用の変数
	CField* pObject;

	//メモリの確保
	pObject = new CField;

	//初期化
	pObject->Init();
	pObject->SetPos(POS);
	pObject->SetSize(SIZE, CObject3D::TYPE_FLOOR);

	return pObject;
}