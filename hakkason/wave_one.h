//=============================================
//
//�E�F�[�u����[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_ONE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _WAVE_ONE_H_
#include "main.h"
#include "wave.h"

//=============================================
//  �E�F�[�u�N���X��`
//=============================================
class CWave_One:public CWave
{
public:

	// �����o�֐�
	CWave_One();
	~CWave_One() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
};

#endif