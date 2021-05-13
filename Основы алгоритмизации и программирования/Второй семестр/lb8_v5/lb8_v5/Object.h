#pragma once
class Object
{
public:
	Object();// конструктор класса
	// чистовиртуальные методы класса
	virtual void display() = 0;
	virtual void insert() = 0;
	virtual ~Object();// деструктор класса
};

