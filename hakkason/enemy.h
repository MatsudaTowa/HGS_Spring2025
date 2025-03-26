//================================
//
//enemy.cpp�ɕK�v�Ȑ錾[enemy.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _ENEMY_H_ //���̃}�N����`������Ă��Ȃ�������
#define _ENEMY_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "game_character.h"

//�G�l�~�[�N���X
class CEnemy : public CGame_Character
{
public:

	enum ENEMY_TYPE
	{
		ENEMY_000 = 0,
		ENEMY_001,
		ENEMY_002,
		ENMEY_MAX,
	};

	//�����o�֐�
	CEnemy(int nPriority = 3);	//�R���X�g���N�^
	virtual ~CEnemy() override;										//�f�X�g���N�^
	virtual HRESULT Init() override;								//������
	virtual void Uninit() override;									//�I��
	virtual void Update() override;									//�X�V
	virtual void Draw() override;									//�`��
	static CEnemy* Create(D3DXVECTOR3 pos, ENEMY_TYPE type);							//�G�l�~�[�̐���

	//�_���[�W�̐ݒ�
	bool SetDamage(int damage) override;				//�_���[�W�̐ݒ�

	inline void SetShotFrame(int Frame) { m_ShotFrame = Frame; }
	inline void SetShotFrameCnt(int FrameCnt) { m_ShotFrame_Cnt = FrameCnt; }

	inline int& GetShotFrame() { return m_ShotFrame; }
	inline int& GetShotFrameCnt() { return m_ShotFrame_Cnt; }
private:
	void LockAtPlayer();
	int m_ShotFrame;
	int m_ShotFrame_Cnt;
};

#endif