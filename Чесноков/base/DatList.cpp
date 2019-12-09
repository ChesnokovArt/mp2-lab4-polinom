#include "DatList.h"

TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = nullptr;
	CurrPos = -1;
	ListLen = 0;
}

PTDatValue TDatList::GetDatValue()
{
	if (IsEmpty()) throw ListException::EmptyList;
	if (CurrPos == -1) throw ListException::OutOfBound;
	else return pCurrLink->GetDatValue();
}

int TDatList::SetCurrentPos(int pos)
{
	if (pos >= ListLen || pos < 0) throw ListException::OutOfBound;
	pCurrLink = pFirst;
	pPrevLink = pStop;
	CurrPos = pos;
	for (int i = 0; i < pos; i++)
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
	}
	return pos;
}

int TDatList::GetCurrentPos(void) const
{
	if (IsEmpty()) throw ListException::EmptyList;
	return CurrPos;
}

int TDatList::Reset(void)
{
	if (IsEmpty()) CurrPos = -1; else CurrPos = 0;
	pCurrLink = pFirst;
	pPrevLink = pStop;
	return CurrPos;
}

int TDatList::IsListEnded(void) const
{
	if (CurrPos == -1) throw ListException::OutOfBound;
	return pCurrLink->GetNextDatLink() == pStop;
}

int TDatList::GoNext(void)
{
	if (IsListEnded())
	{
		pPrevLink = pStop;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos = 0;
		return CurrPos;
	}
	pPrevLink = pCurrLink;
	CurrPos++;
	pCurrLink = pCurrLink->GetNextDatLink();
	return CurrPos;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink tmp = new TDatLink(pVal, pStop);
	if (pCurrLink == pFirst && !IsEmpty()) pPrevLink = tmp;  // если предыдущего эл-та не было то он появился
	ListLen++;
	tmp->SetNextLink(pFirst);
	pFirst = tmp;
	if (pLast == pStop)
	{
		pLast = tmp;
		Reset();
	}
	CurrPos++;  // индекс текущего элемента увеличиться на 1
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink tmp = new TDatLink(pVal, pStop);
	ListLen++;
	if (IsEmpty())
	{
		pFirst = pLast = tmp;
		Reset();
	}
	else
	{
		pLast->SetNextLink(tmp);
		pLast = tmp;
	}
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (CurrPos == -1) throw ListException::OutOfBound;
	PTDatLink tmp = new TDatLink(pVal, pCurrLink);
	ListLen++; CurrPos++;
	if (pPrevLink == pStop)
	{
		pFirst = tmp;
	}
	else
	{
		pPrevLink->SetNextLink(tmp);
	}
	pPrevLink = tmp;
}

void TDatList::DelFirst(void)
{
	if (IsEmpty()) throw ListException::EmptyList;
	ListLen--;
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = pLast = pStop;
		Reset();
		return;
	}
	if (pFirst == pCurrLink)
	{
		PTDatLink tmp = pFirst->GetNextDatLink();
		delete pFirst;
		pFirst = tmp;
		Reset();
		return;
	}
	if (pPrevLink == pFirst)
	{
		PTDatLink tmp = pFirst->GetNextDatLink();
		delete pFirst;
		pFirst = tmp;
		pPrevLink = tmp;
		CurrPos--;
		return;
	}
	PTDatLink tmp = pFirst->GetNextDatLink();
	delete pFirst;
	pFirst = tmp;
	CurrPos--;
}

void TDatList::DelCurrent(void)
{
	if (IsEmpty()) throw ListException::EmptyList;
	if (pCurrLink == pStop) throw ListException::OutOfBound;
	ListLen--;
	if (pFirst == pLast)
	{
		delete pFirst;
		pFirst = pLast = pStop;
		Reset();
		return;
	}
	if (pFirst == pCurrLink)
	{
		PTDatLink tmp = pFirst->GetNextDatLink();
		delete pFirst;
		pFirst = tmp;
		Reset();
		return;
	}
	if (pCurrLink == pLast)
	{
		pPrevLink->SetNextLink(pCurrLink->GetNextLink());
		delete pCurrLink;
		Reset();
		return;
	}
	pPrevLink->SetNextLink(pCurrLink->GetNextLink());
	delete pCurrLink;
	pCurrLink = pPrevLink->GetNextDatLink();
}

void TDatList::DelList()
{
	PTDatLink cur = pFirst;
	PTDatLink tmp = cur;
	while (tmp != pStop)
	{
		tmp = cur->GetNextDatLink();
		delete cur;
		cur = tmp;
	}
	pFirst = pLast = pStop;
	ListLen = 0;
	Reset();
}
