#pragma once
#include <string>
#include <iostream>
using namespace std;

// базовый класс
class ERROR
{
public:
	virtual void what() {};

};

// ошибка в индексе вектора
class INDEXERROR : public ERROR
{
protected:
	string msg;
public:
	INDEXERROR() { msg = "Ошибка индекса!\n"; }
	virtual void what() { cout << msg; }
};

// ошибка в размере вектора
class SIZEERROR : public ERROR
{
protected:
	string msg;
public:
	SIZEERROR() { msg = "Ошибка в размере вектора\n"; }
	virtual void what() { cout << msg; }
};

// превышение максимального размера вектора
class MAXSIZEERROR : public SIZEERROR
{
protected:
	string msg_;
public:
	MAXSIZEERROR() { SIZEERROR(); msg_ = "Превышение максимального размера вектора\n"; }
	virtual void what() { cout << msg << msg_; }
};

// удаление из пустого вектора
class EMPTYSIZEERROR : public SIZEERROR
{
protected:
	string msg_;
public:
	EMPTYSIZEERROR() { SIZEERROR(); msg_ = "Вектор пуст\n"; }
	virtual void what() { cout << msg << msg_; }
};

// индекс меньше нуля
class INDEXERROR1 : public INDEXERROR
{
protected:
	string msg_;
public:
	INDEXERROR1() { INDEXERROR(); msg_ = "Индекс меньше нуля\n"; }
	virtual void what() { cout << msg << msg_; }
};

// индекс больше текущего размера вектора
class INDEXERROR2 : public INDEXERROR
{
protected:
	string msg_;
public:
	INDEXERROR2() { INDEXERROR(); msg_ = "Индекс больше текущего размера вектора\n"; }
	virtual void what() { cout << msg << msg_; }
};