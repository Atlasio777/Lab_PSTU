#include "DIALOG.h"

// конструктор по умолчанию
DIALOG::DIALOG()
{
	this->endState = 0;
}


// деструктор
DIALOG::~DIALOG()
{
}


// получить событие
void DIALOG::getEvent(EVENT& event)
{
	string OpInt = "+-?/qam";// строка содержит коды операций
	string s;
	string param;

	char code;

	cout << "(m|+|-|?|q) > ";
	cin >> s; code = s[0];// первый символ команды
	// является ли символ кодом операции
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;// создать группу
		case '+': event.command = cmAdd; break;// добавить объект в группу
		case '-': event.command = cmDel; break;// удалить объект из группы
		case '?': event.command = cmShow; break;// просмотр группы
		case 'q': event.command = cmQuit; break;// конец работы
		default: break;
		}// switch
		// выделяем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			// преобразуем параметр в число
			int A = atoi(param.c_str());
			event.a = A;// записываем в сообщение
		}// if
	}// OpInt find
	else event.what = evNothing;// пустое событие
}

// главный цикл обработки событий
int DIALOG::execute()
{
	EVENT event;
	do 
	{
		this->endState = 0;
		// получение события
		this->getEvent(event);
		// обработка события
		this->handleEvent(event);
	} 	while (!valid());
	return this->endState;
}


// проверка атрибута endStat
int DIALOG::valid()
{
	if (this->endState == 0) return 0;
	return 1;
}


// очистить событие
void DIALOG::clearEvent(EVENT& event)
{
	event.what = evNothing;// пустое событие
}


// обработка события "конец работы"
void DIALOG::endExec()
{
	this->endState = 1;
}


// обработчик событий
void DIALOG::handleEvent(EVENT& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:// создание группы
			size = event.a; // размер группы
			// выделяем память под массив указателей
			this->beg = new Object * [size];
			this->curr = 0;// текущая позиция
			this->clearEvent(event); // очищаем событие
			break;

		case cmAdd:// добавление
			this->add();
			this->clearEvent(event);
			break;
		case cmDel: 
			this->del();// удаление
			this->clearEvent(event);
			break;
		case cmShow: 
			this->show();// просмотр
			this->clearEvent(event);
			break;
		case cmQuit:
			this->endExec();// выход
			this->clearEvent(event);
			break;
		default: break;
		}// switch
	}
}





