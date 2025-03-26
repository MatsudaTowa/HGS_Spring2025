//=============================================
//
//�E�F�[�u����[wave.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "wave.h"
#include "wave_one.h"
#include "wave_two.h"
#include "wave_three.h"

//=============================================
//�R���X�g���N�^
//=============================================
CWave::CWave():
	m_CurrentWave()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CWave::~CWave()
{
}

//=============================================
//������
//=============================================
HRESULT CWave::Init()
{
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CWave::Uninit()
{
}

//=============================================
//�X�V
//=============================================
void CWave::Update()
{
}

//=============================================
//����
//=============================================
CWave* CWave::Create(WAVE wave)
{
	// �C���X�^���X����
	CWave* pWave = nullptr;

	// ��������
	switch (wave)
	{
	case WAVE::ONE: // �E�F�[�u1
		delete pWave;
		pWave = new CWave_One;
		break;

	case WAVE::TWO: //�E�F�[�u2
		delete pWave;
		pWave = new CWave_Two;
		break;

	case WAVE::THREE: // �E�F�[�u3

		delete pWave;
		pWave = new CWave_Three;
		break;
	default:
		assert("�͈͊O�̃E�F�[�u");
		break;
	}

	if (pWave != nullptr)
	{
		pWave->m_CurrentWave = wave;
	}
	//���̃V�[���̏�����
	pWave->Init();

	return pWave;
}
