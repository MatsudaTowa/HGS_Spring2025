//================================
//
//player.cpp�ɕK�v�Ȑ錾[player.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _PLAYER_H_ //���̃}�N����`������Ă��Ȃ�������
#define _PLAYER_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

#include "game_character.h"
#include "enemy.h"

//�v���C���[�N���X
class CPlayer : public CGame_Character
{
public:

	//�萔
	static constexpr int MAX_LIFE{ 20 };				//�ő�̗͒l
	static const std::string FILEPATH;					//�ǂݍ��ރt�@�C��
	static constexpr int ATTACK_COOLTIME{ 30 };			//�U���̃N�[���^�C��
	
	//�L�[�̎��
	typedef enum
	{
		PLAYERMOTION_NORMAL = 0,
		PLAYERMOTION_WALK,
		PLAYERMOTION_ACTION,
		PLAYERMOTION_MAX
	}PLAYERMOTION;

	//�����o�֐�
	CPlayer(int nPriority = 2);							//�R���X�g���N�^
	~CPlayer() override;								//�f�X�g���N�^
	HRESULT Init() override;							//������
	void Uninit() override;								//�I��
	void Update() override;								//�X�V
	void Draw() override;								//�`��
	bool SetDamage(int damage, float angle) override;	//�_���[�W��ݒ�

	//�ÓI�֐�
	static CPlayer* Create();	//Player�̐���

private:

	//�֐�
	void UpdateOperation();	//����̍X�V
	void Move();			//�ړ�����
	void Attack();			//�U������
	void UpdateCoolTime();	//�N�[���^�C���̍X�V

	//�ϐ�
	int m_nAttackCoolTime;	//�U���̃N�[���^�C��


};

#endif