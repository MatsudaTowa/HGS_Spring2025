//================================
//
//effect_hit.cpp�ɕK�v�Ȑ錾[effect_death.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _EFFECT_HIT_H_ //���̃}�N����`������Ă��Ȃ�������
#define _EFFECT_HIT_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "effect_billboard.h"

//���S�G�t�F�N�g�N���X
class CEffect_Hit : public CEffect_Billboard
{
public:

	//�萔
	static const std::string TEXTURE_PATH;	//�e�N�X�`���p�X
	static constexpr float RADIUS{ 70.0f };	//�T�C�Y���a

	//�e�N�X�`�����
	static constexpr int HORIZONTAL{ 6 };	//���̕�����(U���W)
	static constexpr int VERTICAL{ 2 };		//�c�̕�����(V���W)
	static constexpr int SPEED_UPDATE{ 1 };	//�X�V���x
	static constexpr bool LOOP{ false };	//���[�v

	//�����o�֐�
	CEffect_Hit();			//�R���X�g���N�^
	~CEffect_Hit() override;	//�f�X�g���N�^
	HRESULT Init() override;	//������
	void Uninit() override;		//�I��
	void Update() override;		//�X�V
	void Draw() override;		//�`��

	//����
	static CEffect_Hit* Create(D3DXVECTOR3 pos);
};

#endif