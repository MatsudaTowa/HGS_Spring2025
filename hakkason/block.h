//================================
//
//block.cpp�ɕK�v�Ȑ錾[block.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCK_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BLOCK_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "objectX.h"

//X�I�u�W�F�N�g�N���X
class CBlock : public CObjectX
{
public:

	//�萔�̐錾
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��

	//�����o�֐�
	CBlock(int nPriority = 3);								//�R���X�g���N�^
	~CBlock() override;										//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��
	static CBlock* Create(D3DXVECTOR3 pos);					//�u���b�N�̐���

private:

};

#endif