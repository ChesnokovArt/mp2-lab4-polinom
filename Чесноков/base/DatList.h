#pragma once
#include "DatLink.h"
class TDatList
{
protected:
	PTDatLink pFirst;    //первое звено
	PTDatLink pLast;     // последнее звено 
	PTDatLink pCurrLink; // текущее звено
	PTDatLink pPrevLink; // звено перед текущим
	PTDatLink pStop;     // значение указателя, означающего конец списка
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке

	//PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
	//void DelLink(PTDatLink pLink); // удаление звена

public:
	TDatList();
	~TDatList() { DelList(); }
	/* доступ к элементам --------------------------------------------------*/
	PTDatValue GetDatValue(); // получение значения текущего звена
	virtual int IsEmpty() const { return pFirst == pStop; }
	int GetListLength() const { return ListLen; }

	/* навигация-------(индексация с 0)-------------------------------------*/
	int SetCurrentPos(int pos);
	int GetCurrentPos(void) const;          // получить номер тек. звена
	virtual int Reset ( void );             // установить на начало списка
	// cчитается законченым если после goNext cur станет pstop
	virtual int IsListEnded ( void ) const; // список завершен ?
	int GoNext ( void );                    // сдвиг вправо текущего звена
				// (=1 после применения GoNext для последнего звена списка)
	/* вставка звеньев------------------------------------------------------*/
	virtual void InsFirst(PTDatValue pVal = nullptr);   // перед первым
	virtual void InsLast ( PTDatValue pVal= nullptr);   // вставить последним
	virtual void InsCurrent( PTDatValue pVal= nullptr); // перед текущим 
	/* удаление звеньев-----------------------------------------------------*/
	// при удалении текущего звена итератор будет сброшен
	virtual void DelFirst ( void );  // удалить первое звено
	// при удалении последнего звена итератор будет сброшен
	virtual void DelCurrent( void ); // удалить текущее звено
	virtual void DelList();
};

enum class ListException
{
	EmptyList,
	OutOfBound
};