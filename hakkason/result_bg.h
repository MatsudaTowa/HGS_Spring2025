//================================
//
//object2D.cpp�ɕK�v�Ȑ錾[object2D.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _RESULT_BG_H_ //���̃}�N����`������Ă��Ȃ�������
#define _RESULT_BG_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "object2D.h"
//2D�I�u�W�F�N�g�N���X
class CResult_Bg : public CObject2D
{
public:
	//�����o�֐�
	CResult_Bg(int nPriority = 3);			//�R���X�g���N�^
	~CResult_Bg() override;					//�f�X�g���N�^
	HRESULT Init() override;				//������
	void Uninit() override;					//�I��
	void Update() override;					//�X�V
	void Draw()override;					//�����̃e�N�X�`���ŕ`��
	static CResult_Bg* Create(D3DXVECTOR3 pos);				//Object2D�̐���

private:
	static const std::string FILEPATH;	//�e�N�X�`���p�X
};

#endif