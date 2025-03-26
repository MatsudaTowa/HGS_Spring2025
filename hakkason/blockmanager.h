//================================
//
//blockmanager.cpp�ɕK�v�Ȑ錾[blockmanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCKMANAGER_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BLOCKMANAGER_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "main.h"
#include "block.h"

//�u���b�N�}�l�[�W���[�̃N���X
class CBlockManager
{
public:

	//�����o�֐�
	CBlockManager();			//�R���X�g���N�^
	~CBlockManager();			//�f�X�g���N�^
	HRESULT Init();				//������
	void Uninit();				//�I��
	void Regist(CBlock* block);	//�o�^
	void Erase(CBlock* block);	//�폜

	//���X�g�̎擾
	std::list<CBlock*> GetList() { return m_apManager; }

private:

	//�����o�ϐ�
	std::list<CBlock*> m_apManager;	//�G���Ǘ�
};

#endif