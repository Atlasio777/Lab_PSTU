#include "DIALOG.h"

// ����������� �� ���������
DIALOG::DIALOG()
{
	this->endState = 0;
}


// ����������
DIALOG::~DIALOG()
{
}


// �������� �������
void DIALOG::getEvent(EVENT& event)
{
	string OpInt = "+-?/qam";// ������ �������� ���� ��������
	string s;
	string param;

	char code;

	cout << "(m|+|-|?|q) > ";
	cin >> s; code = s[0];// ������ ������ �������
	// �������� �� ������ ����� ��������
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;// ������� ������
		case '+': event.command = cmAdd; break;// �������� ������ � ������
		case '-': event.command = cmDel; break;// ������� ������ �� ������
		case '?': event.command = cmShow; break;// �������� ������
		case 'q': event.command = cmQuit; break;// ����� ������
		default: break;
		}// switch
		// �������� ��������� �������, ���� ��� ����
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			// ����������� �������� � �����
			int A = atoi(param.c_str());
			event.a = A;// ���������� � ���������
		}// if
	}// OpInt find
	else event.what = evNothing;// ������ �������
}

// ������� ���� ��������� �������
int DIALOG::execute()
{
	EVENT event;
	do 
	{
		this->endState = 0;
		// ��������� �������
		this->getEvent(event);
		// ��������� �������
		this->handleEvent(event);
	} 	while (!valid());
	return this->endState;
}


// �������� �������� endStat
int DIALOG::valid()
{
	if (this->endState == 0) return 0;
	return 1;
}


// �������� �������
void DIALOG::clearEvent(EVENT& event)
{
	event.what = evNothing;// ������ �������
}


// ��������� ������� "����� ������"
void DIALOG::endExec()
{
	this->endState = 1;
}


// ���������� �������
void DIALOG::handleEvent(EVENT& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:// �������� ������
			size = event.a; // ������ ������
			// �������� ������ ��� ������ ����������
			this->beg = new Object * [size];
			this->curr = 0;// ������� �������
			this->clearEvent(event); // ������� �������
			break;

		case cmAdd:// ����������
			this->add();
			this->clearEvent(event);
			break;
		case cmDel: 
			this->del();// ��������
			this->clearEvent(event);
			break;
		case cmShow: 
			this->show();// ��������
			this->clearEvent(event);
			break;
		case cmQuit:
			this->endExec();// �����
			this->clearEvent(event);
			break;
		default: break;
		}// switch
	}
}





