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
	
	//�L�[�̎��
	typedef enum
	{
		PLAYERMOTION_NORMAL = 0,
		PLAYERMOTION_WALK,
		PLAYERMOTION_ACTION,
		PLAYERMOTION_JUMP,
		PLAYERMOTION_ARIAL000,
		PLAYERMOTION_ARIAL001,
		PLAYERMOTION_ARIAL002,
		PLAYERMOTION_KNOCKBACK,
		PLAYERMOTION_DAMAGE,
		PLAYERMOTION_ACTION001,
		PLAYERMOTION_ACTION002,
		PLAYERMOTION_ATTACKCHARGE,
		PLAYERMOTION_CHARGEATTACK,
		PLAYERMOTION_DASHATTACK000,
		PLAYERMOTION_DASHATTACK001,
		PLAYERMOTION_COUNTER,
		PLAYERMOTION_GUARD,
		PLAYERMOTION_DEATH,
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
};

#endif