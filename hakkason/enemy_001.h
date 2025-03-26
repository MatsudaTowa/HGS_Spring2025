//================================
//
//enemy_001.cpp�ɕK�v�Ȑ錾[enemy_001.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_001_H_ //���̃}�N����`������Ă��Ȃ�������
#define _ENEMY_001_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"

//�G�l�~�[�N���X
class CEnemy_001 : public CEnemy
{
public:

	//�����o�֐�
	CEnemy_001(int nPriority = 3);	//�R���X�g���N�^
	~CEnemy_001() override;			//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��

	void ShotBullet()override;
private:
	static const int LIFE = 10;
	static const int SHOT_FRAME = 200;
	static const int BURST_DELAY_FRAME = 20;
	static const int NUM_SHOT = 3;
	static const std::string FILEPATH;					//�ǂݍ��ރt�@�C��

	int m_nBurstDelayCnt;
	int m_nShotBullet;
};

#endif