//=============================================
//
//�E�F�[�u����[wave.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WAVE_TWO_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _WAVE_TWO_H_
#include "main.h"
#include "wave.h"

//=============================================
//  �E�F�[�u�N���X��`
//=============================================
class CWave_Three :public CWave
{
public:

	// �����o�֐�
	CWave_Three();
	virtual ~CWave_Three();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

private:
};

#endif