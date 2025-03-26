//================================
//
//enemy_000.cpp�ɕK�v�Ȑ錾[enemy_000.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_000_H_ //���̃}�N����`������Ă��Ȃ�������
#define _ENEMY_000_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"

//�G�l�~�[�N���X
class CEnemy_000 : public CEnemy
{
public:

	//�����o�֐�
	CEnemy_000(int nPriority = 3);	//�R���X�g���N�^
	~CEnemy_000() override;			//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��
private:
	static const int LIFE = 5;
	static const int SHOT_FRAME = 90;
	static const std::string FILEPATH;					//�ǂݍ��ރt�@�C��
};

#endif