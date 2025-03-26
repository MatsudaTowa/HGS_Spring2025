//================================
//
//objectX.cpp�ɕK�v�Ȑ錾[objectX.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BULLET_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BULLET_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "objectX.h"

//�o���b�g�N���X
class CBullet : public CObjectX
{
public:

	//�萔�̐錾
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��

	//�����o�֐�
	CBullet(int nPriority = 3);														//�R���X�g���N�^
	~CBullet() override;															//�f�X�g���N�^
	HRESULT Init() override;														//������
	void Uninit() override;															//�I��
	void Update() override;															//�X�V
	void Draw() override;															//�`��
	static CBullet* Create(D3DXVECTOR3 pos, float rot, float speed, bool player);	//����

	void SetPlayerBullet(bool player) { m_bPlayerBullet = player; }
	bool GetPlayerBullet() { return m_bPlayerBullet; }

	void SetSpeed(D3DXVECTOR3 speed) { m_Speed = speed; }	//�ݒ�
	D3DXVECTOR3& GetSpeed() { return m_Speed; }				//�擾

	int& GetHansya() { return m_nHansya; }

private:

	//�萔
	static constexpr int MAX_HANSYA{ 10 };	//�ő唽�ː�

	//�֐�
	void Collision();

	//�ϐ�
	D3DXVECTOR3 m_Speed;
	D3DXVECTOR3 m_OldPos;
	bool m_bPlayerBullet;
	int m_nHansya;

};

#endif