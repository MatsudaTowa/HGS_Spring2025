//================================
//
//block.cpp�ɕK�v�Ȑ錾[block.h]
//Author:yuuto shimadu
// 
//================================

#ifndef _BLOCK_H_ //���̃}�N����`������Ă��Ȃ�������
#define _BLOCK_H_ //�Q�d�C���N���[�h�h�~�̃}�N����`

//�w�b�_�[�̃C���N���[�h
#include "objectX.h"

//X�I�u�W�F�N�g�N���X
class CBlock : public CObjectX
{
public:

	//�萔�̐錾
	static const std::string FILEPATH;	//�ǂݍ��ރt�@�C��

	//�񋓌^
	typedef enum
	{
		BLOCKTYPE_NORMAL = 0,
		BLOCKTYPE_MAX
	}BLOCKTYPE;

	//�����o�֐�
	CBlock(int nPriority = 3);								//�R���X�g���N�^
	~CBlock() override;										//�f�X�g���N�^
	HRESULT Init() override;								//������
	void Uninit() override;									//�I��
	void Update() override;									//�X�V
	void Draw() override;									//�`��
	static CBlock* Create(D3DXVECTOR3 pos, BLOCKTYPE type);	//�u���b�N�̐���

	void SetBlockType(BLOCKTYPE type) { m_BlockType = type; }
	BLOCKTYPE GetBlockType() { return m_BlockType; }

private:

	//�ϐ�
	BLOCKTYPE m_BlockType;
};

#endif