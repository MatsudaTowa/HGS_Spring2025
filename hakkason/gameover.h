//================================
//
//gameover.cpp�ɕK�v�Ȑ錾[gameover.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAMEOVER_H_ //���̃}�N����`������Ă��Ȃ�������
#define _GAMEOVER_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "scene.h"

//�^�C�g���N���X
class CGameover : public CScene
{
public:

	//�����o�֐�
	CGameover();						//�R���X�g���N�^
	~CGameover() override;				//�f�X�g���N�^
	HRESULT Init() override;		//������
	void Uninit() override;			//�I��
	void Update() override;			//�X�V
	void Draw() override;			//�`��
};
#endif