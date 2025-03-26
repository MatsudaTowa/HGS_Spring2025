//======================================
//
//	�o���b�g�̏���[bullet.cpp]
//	Author : Yuuto Shimadu
//
//======================================

//�w�b�_�[�̃C���N���[�h
#include "bullet.h"
#include "manager.h"
#include "gamemanager.h"
#include "bulletmanager.h"
#include "effect_hit.h"

//�萔�̏�����
const std::string CBullet::FILEPATH = "data\\MODEL\\bullet.x";

//============================
//�R���X�g���N�^
//============================
CBullet::CBullet(int nPriority) : CObjectX(nPriority),
m_Speed({ 0.0f, 0.0f, 0.0f }),
m_OldPos({ 0.0f, 0.0f, 0.0f }),
m_bPlayerBullet(false),
m_nHansya(0)
{
	//�}�l�[�W���[�ɓo�^
	if (CGameManager::GetInstance()->GetBulletManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBulletManager()->Regist(this);
	}
}

//============================
//�f�X�g���N�^
//============================
CBullet::~CBullet()
{
	//�}�l�[�W���[����폜
	if (CGameManager::GetInstance()->GetBulletManager() != nullptr)
	{
		CGameManager::GetInstance()->GetBulletManager()->Erase(this);
	}
}

//============================
//������
//============================
HRESULT CBullet::Init()
{
	return S_OK;
}

//============================
//�I������
//============================
void CBullet::Uninit()
{
	//����
	SetDeath();
}

//============================
//�X�V
//============================
void CBullet::Update()
{
	//�ߋ��̈ʒu
	m_OldPos = GetPos();

	//�ʒu�̍X�V
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
//�����蔻��
//============================
void CBullet::Collision()
{
	//X�t�@�C���̓ǂݍ���
	CXfile* pCXfile = CManager::GetInstance()->GetXfile();

	//�G���X�g
	std::list<CEnemy*> EnemyList = CGameManager::GetInstance()->GetEnemyManager()->GetList();

	//�G�l�~�[�̃T�C�Y���擾����ϐ�
	D3DXVECTOR3 MaxSize = pCXfile->GetAddress(pCXfile->Regist(CBullet::FILEPATH.c_str())).aSize.Max;
	D3DXVECTOR3 MinSize = pCXfile->GetAddress(pCXfile->Regist(CBullet::FILEPATH.c_str())).aSize.Min;

	for (auto& iter : EnemyList)
	{
		bool bHit = false;

		//��̔���
		if (GetPos().z + (MinSize.z) <= iter->GetPos().z + iter->GetCollision()->GetRadius()
			&& GetPos().x + (MinSize.z) < iter->GetPos().x + (iter->GetCollision()->GetRadius())
			&& GetPos().x + (MaxSize.z) > iter->GetPos().x - (iter->GetCollision()->GetRadius())
			)
		{
			if (m_OldPos.z + (MinSize.z) >= iter->GetPos().z + iter->GetCollision()->GetRadius())
			{
				//�ʒu�̕␳
				GetPos().z = iter->GetPos().z + iter->GetCollision()->GetRadius() - (MinSize.z);
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//���̔���
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

		//�E�̔���
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

		//���̔���
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

	//�G���X�g
	std::list<CBlock*> BlockList = CGameManager::GetInstance()->GetBlockManager()->GetList();

	for (auto& iter : BlockList)
	{
		bool bHit = false;

		//��̔���
		if (GetPos().z + (MinSize.z) <= iter->GetPos().z + 10.0f
			&& GetPos().x + (MinSize.z) < iter->GetPos().x + (10.0f)
			&& GetPos().x + (MaxSize.z) > iter->GetPos().x - (10.0f)
			)
		{
			if (m_OldPos.z + (MinSize.z) >= iter->GetPos().z + 10.0f)
			{
				//�ʒu�̕␳
				GetPos().z = iter->GetPos().z + 10.0f - (MinSize.z);
				m_Speed.z *= -1.0f;
				bHit = true;
			}
		}

		//���̔���
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

		//�E�̔���
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

		//���̔���
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
//�`��
//============================
void CBullet::Draw()
{
	//���[�J���ϐ��錾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	D3DXMATRIX mtxRot, mtxTrans, mtxScale;								//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;												//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;													//�}�e���A���f�[�^�ւ̃|�C���^
	D3DXVECTOR3 Pos = GetPos();											//�ʒu�̎擾

	//X�t�@�C���̓ǂݍ���
	CXfile* pCXfile = CManager::GetInstance()->GetXfile();

	//���[���h�̏�����
	D3DXMatrixIdentity(&GetMtx());

	//�X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScale, GetScale().x, GetScale().y, GetScale().z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxScale);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, Pos.x, Pos.y, Pos.z);

	D3DXMatrixMultiply(&GetMtx(), &GetMtx(), &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &GetMtx());

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pBuffmat->GetBufferPointer();

	//�e�N�X�`���̐����J�E���g
	int nTextureCount = 0;

	//�}�e���A���̐���������
	for (int nCntMat = 0; nCntMat < (int)pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).dwNumMat; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`������������
		if (pMat[nCntMat].pTextureFilename != NULL)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pTexture[nTextureCount]);

			//�e�N�X�`���p�̃J�E���g��i�߂�
			nTextureCount++;
		}
		else
		{
			//�e�N�X�`����ݒ肵�Ȃ�
			pDevice->SetTexture(0, NULL);
		}

		//�I�u�W�F�N�gX(�p�[�c)�̕`��
		pCXfile->GetAddress(pCXfile->Regist(FILEPATH.c_str())).pMesh->DrawSubset(nCntMat);
	}

	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	//�ʒu�̐ݒ�
	SetPos(Pos);
}

//============================
//�N���G�C�g
//============================
CBullet* CBullet::Create(D3DXVECTOR3 pos, float rot, float speed, bool player)
{
	//�|�C���^�p�̕ϐ�
	CBullet* pObjectX;

	//�������̊m��
	pObjectX = new CBullet;

	//�p�����[�^�̐ݒ�
	pObjectX->SetPos(pos);					//�ʒu�̐ݒ�
	pObjectX->SetRot({ 0.0f, rot , 0.0f });	//����
	pObjectX->m_Speed = { sinf(rot) * speed, 0.0f, cosf(rot) * speed };	//���x
	pObjectX->m_bPlayerBullet = player;

	//������
	pObjectX->Init();

	return pObjectX;
}