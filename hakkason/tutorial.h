//================================
//
//title.cpp�ɕK�v�Ȑ錾[title.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _TUTORIAL_H_ //���̃}�N����`������Ă��Ȃ�������
#define _TUTORIAL_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "scene.h"

//�^�C�g���N���X
class CTutorial : public CScene
{
public:

	//�����o�֐�
	CTutorial();						//�R���X�g���N�^
	~CTutorial() override;				//�f�X�g���N�^
	HRESULT Init() override;		//������
	void Uninit() override;			//�I��
	void Update() override;			//�X�V
	void Draw() override;			//�`��
};
#endif