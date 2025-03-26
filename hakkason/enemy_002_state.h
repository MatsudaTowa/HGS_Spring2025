//=============================================
//
//ボスのステートパターン[boss_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _BOSS_STATE_H_
#define _BOSS_STATE_H_


//=============================================
//前方宣言
//=============================================
class CEnemy_002;

//=============================================
//ボスのステートクラス
//=============================================
class CEnemy_002_State
{
public:
	CEnemy_002_State() {};
	virtual ~CEnemy_002_State() {};
	virtual void Move(CEnemy_002* enemy) {};
	virtual void Shot(CEnemy_002* enemy) {};
};

class CEnemy_002_Move :public CEnemy_002_State
{
public:
	CEnemy_002_Move():m_nChangeCnt(0), m_nTurnCnt(0),m_bRight(false){};
	~CEnemy_002_Move() override {};
	void Move(CEnemy_002* enemy) override;
private:
	static const int CHANGE_FRAME = 180;
	static const int TURN = 2;	//2回折り返したら終了
	int m_nChangeCnt;
	int m_nTurnCnt;
	bool m_bRight;	//true:→
};

class CEnemy_002_Shot :public CEnemy_002_State
{
public:
	CEnemy_002_Shot() {};
	~CEnemy_002_Shot() override {};
	void Shot(CEnemy_002* enemy) override;
};
#endif