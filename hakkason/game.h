//================================
//
//game.cpp�ɕK�v�Ȑ錾[game.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _GAME_H_ //���̃}�N����`������Ă��Ȃ�������
#define _GAME_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "scene.h"
#include "time.h"

//�Q�[���N���X
class CGame : public CScene
{
public:

	//�萔
	static const D3DXVECTOR3 TIME_POS;		//���Ԃ̈ʒu
	static const std::string FILEPATH_MODEL;//���f���̃t�@�C���p�X

	//�����o�֐�
	CGame();						//�R���X�g���N�^
	~CGame() override;				//�f�X�g���N�^
	HRESULT Init() override;		//������
	void Uninit() override;			//�I��
	void Update() override;			//�X�V
	void Draw() override;			//�`��
	void Load() override;			//�ǂݍ���

	//�N���A����
	void SetClear(bool clear) { m_bClear = clear; }	//�ݒ�

	//�|�[�Y
	void SetPause();						//�|�[�Y�̐؂�ւ�
	bool GetPause() { return m_bPause; }	//�|�[�Y�̏�Ԃ��擾

private:

	//����
	bool m_bClear;				//�N���A����
	bool m_bPause;				//�|�[�Y����
};

#endif