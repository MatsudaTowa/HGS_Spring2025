//================================
//
//field.cpp�ɕK�v�Ȑ錾[field.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _FIELD_H_ //���̃}�N����`������Ă��Ȃ�������
#define _FIELD_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "object3D.h"

//�t�B�[���h�N���X
class CField : public CObject3D
{
public:

	//�萔
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��
	static const D3DXVECTOR3 SIZE;		//�T�C�Y
	static const D3DXVECTOR3 POS;		//�ʒu

	//�����o�֐�
	CField(int nPriority = 3);					//�R���X�g���N�^
	~CField() override;							//�f�X�g���N�^
	HRESULT Init() override;					//������
	void Uninit() override;						//�I��
	void Update() override;						//�X�V
	void Draw() override;						//�`��
	static CField* Create();					//����
};

#endif