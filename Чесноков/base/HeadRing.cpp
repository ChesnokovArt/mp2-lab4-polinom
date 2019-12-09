#include "HeadRing.h"

THeadRing::THeadRing(PTDatValue Head)
{
	PTDatLink tmp = new TDatLink(Head);
	tmp->SetNextLink(tmp);
	pStop = pHead = pFirst = pLast = pCurrLink = pPrevLink = tmp;
}

THeadRing::~THeadRing()
{
	delete pHead;
	DelList();
}

void THeadRing::InsFirst(PTDatValue pVal)
{
	PTDatLink tmp = new TDatLink(pVal, pStop);
	if (pCurrLink == pFirst && !IsEmpty()) pPrevLink = tmp;  // если предыдущего эл-та не было то он появился
	ListLen++;
	tmp->SetNextLink(pFirst);
	pHead->SetNextLink(tmp);
	pFirst = tmp;
	if (pLast == pStop)
	{
		pLast = tmp;
		Reset();
	}
	CurrPos++;  // индекс текущего элемента увеличиться на 1
}

void THeadRing::InsLast(PTDatValue pVal)
{
	PTDatLink tmp = new TDatLink(pVal, pStop);
	ListLen++;
	if (IsEmpty())
	{
		pHead->SetNextLink(tmp);
		pFirst = pLast = tmp;
		Reset();
	}
	else
	{
		pLast->SetNextLink(tmp);
		pLast = tmp;
	}
}

void THeadRing::InsCurrent(PTDatValue pVal)
{
	if (CurrPos == -1) throw ListException::OutOfBound;
	PTDatLink tmp = new TDatLink(pVal, pCurrLink);
	ListLen++; CurrPos++;
	if (pPrevLink == pStop)
	{
		pHead->SetNextLink(tmp);
		pFirst = tmp;
	}
	else
	{
		pPrevLink->SetNextLink(tmp);
	}
	pPrevLink = tmp;
}

void THeadRing::DelFirst(void)
{
	pHead = pFirst->GetNextDatLink();
	TDatList::DelFirst();
}
