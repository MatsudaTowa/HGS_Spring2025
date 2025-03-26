//================================
//
//renga.cpp�ɕK�v�Ȑ錾[renga.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _RENGA_H_ //���̃}�N����`������Ă��Ȃ�������
#define _RENGA_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "objectX.h"

//�����K�N���X
class CRenga : public CObjectX
{
public:

	//�萔�̐錾
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��

	//�����o�֐�
	CRenga(int nPriority = 3);														//�R���X�g���N�^
	~CRenga() override;																//�f�X�g���N�^
	HRESULT Init() override;														//������
	void Uninit() override;															//�I��
	void Update() override;															//�X�V
	void Draw() override;															//�`��
	static CRenga* Create(D3DXVECTOR3 pos);											//����

};

#endif