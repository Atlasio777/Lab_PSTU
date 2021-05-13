#pragma once
#include <string>
#include <iostream>
using namespace std;

// ������� �����
class ERROR
{
public:
	virtual void what() {};

};

// ������ � ������� �������
class INDEXERROR : public ERROR
{
protected:
	string msg;
public:
	INDEXERROR() { msg = "������ �������!\n"; }
	virtual void what() { cout << msg; }
};

// ������ � ������� �������
class SIZEERROR : public ERROR
{
protected:
	string msg;
public:
	SIZEERROR() { msg = "������ � ������� �������\n"; }
	virtual void what() { cout << msg; }
};

// ���������� ������������� ������� �������
class MAXSIZEERROR : public SIZEERROR
{
protected:
	string msg_;
public:
	MAXSIZEERROR() { SIZEERROR(); msg_ = "���������� ������������� ������� �������\n"; }
	virtual void what() { cout << msg << msg_; }
};

// �������� �� ������� �������
class EMPTYSIZEERROR : public SIZEERROR
{
protected:
	string msg_;
public:
	EMPTYSIZEERROR() { SIZEERROR(); msg_ = "������ ����\n"; }
	virtual void what() { cout << msg << msg_; }
};

// ������ ������ ����
class INDEXERROR1 : public INDEXERROR
{
protected:
	string msg_;
public:
	INDEXERROR1() { INDEXERROR(); msg_ = "������ ������ ����\n"; }
	virtual void what() { cout << msg << msg_; }
};

// ������ ������ �������� ������� �������
class INDEXERROR2 : public INDEXERROR
{
protected:
	string msg_;
public:
	INDEXERROR2() { INDEXERROR(); msg_ = "������ ������ �������� ������� �������\n"; }
	virtual void what() { cout << msg << msg_; }
};