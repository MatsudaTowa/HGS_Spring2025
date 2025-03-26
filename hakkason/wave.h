//=============================================
//
//�E�F�[�u����[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _WAVE_H_
#include "main.h"
#include "enemy.h"

//=============================================
//  �E�F�[�u�N���X��`
//=============================================
class CWave
{
public:
	//�E�F�[�u��
	enum WAVE
	{
		NONE = 0,
		ONE,
		TWO,
		THREE,
		MAX,
	};

	// �����o�֐�
	CWave();
	virtual ~CWave();

	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();

	static CWave* Create(WAVE wave);

	inline WAVE GetCurrentWave()
	{
		return m_CurrentWave;
	}


protected:

	WAVE m_CurrentWave; //���݂̃E�F�[�u

	struct EnemyInfo
	{
		D3DXVECTOR3 pos;
		CEnemy::ENEMY_TYPE type;
	};
};

#endif