#pragma once
#include "VECTOR.h"
#include "EVENT.h"
class DIALOG : public VECTOR
{
public:
	// конструктор по умолчанию
	DIALOG(void);
	// деструктор
	virtual ~DIALOG(void);
	// получить событие
	virtual void getEvent(EVENT& event);
	// главный цикл обработки событий
	virtual int execute();
	// обработчик
	virtual void handleEvent(EVENT & event);
	// очистить событие
	virtual void clearEvent(EVENT & event);
	// проверка атрибута endStat
	int valid();
	void endExec();// обработка события "конец работы"

protected:
	int endState;
};

