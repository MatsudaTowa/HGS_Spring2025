//================================
//
//block_normal.cpp�ɕK�v�Ȑ錾[block.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCK_NORMAL_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BLOCK_NORMAL_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "block.h"

//X�I�u�W�F�N�g�N���X
class CBlock_Normal : public CBlock
{
public:

	//�萔�̐錾
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��

	//�����o�֐�
	CBlock_Normal(int nPriority = 3);						//�R���X�g���N�^
	~CBlock_Normal() override;								//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��
	
};

#endif