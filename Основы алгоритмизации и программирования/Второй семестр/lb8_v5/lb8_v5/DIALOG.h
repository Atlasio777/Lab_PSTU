#pragma once
#include "VECTOR.h"
#include "EVENT.h"
class DIALOG : public VECTOR
{
public:
	// ����������� �� ���������
	DIALOG(void);
	// ����������
	virtual ~DIALOG(void);
	// �������� �������
	virtual void getEvent(EVENT& event);
	// ������� ���� ��������� �������
	virtual int execute();
	// ����������
	virtual void handleEvent(EVENT & event);
	// �������� �������
	virtual void clearEvent(EVENT & event);
	// �������� �������� endStat
	int valid();
	void endExec();// ��������� ������� "����� ������"

protected:
	int endState;
};

