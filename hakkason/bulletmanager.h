//================================
//
//bulletmanager.cpp�ɕK�v�Ȑ錾[bulletmanager.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BULLETMANAGER_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BULLETMANAGER_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "bullet.h"

//�o���b�g�}�l�[�W���[�̃N���X
class CBulletManager
{
public:

	//�����o�֐�
	CBulletManager();				//�R���X�g���N�^
	~CBulletManager();				//�f�X�g���N�^
	HRESULT Init();					//������
	void Uninit();					//�I��
	void Regist(CBullet* bullet);	//�o�^
	void Erase(CBullet* bullet);	//�폜

	//���X�g�̎擾
	std::list<CBullet*> GetList() { return m_apManager; }

private:

	//�����o�ϐ�
	std::list<CBullet*> m_apManager;	//�G���Ǘ�
};

#endif