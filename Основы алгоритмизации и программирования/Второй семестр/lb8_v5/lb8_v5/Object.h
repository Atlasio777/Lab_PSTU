#pragma once
class Object
{
public:
	Object();// ����������� ������
	// ���������������� ������ ������
	virtual void display() = 0;
	virtual void insert() = 0;
	virtual ~Object();// ���������� ������
};

