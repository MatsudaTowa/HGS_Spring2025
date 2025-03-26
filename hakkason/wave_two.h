//=============================================
//
//�E�F�[�u����[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_THREE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _WAVE_THREE_H_
#include "main.h"
#include "wave.h"

//=============================================
//  �E�F�[�u�N���X��`
//=============================================
class CWave_Two :public CWave
{
public:

	// �����o�֐�
	CWave_Two();
	virtual ~CWave_Two();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
	static const int NUM_ENEMY = 3;
	static const CWave::EnemyInfo ENEMY_INFO[NUM_ENEMY];
};

#endif