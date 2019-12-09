#pragma once
#include "DatValue.h"
class TRootLink;
typedef TRootLink* PTRootLink;

// базовый класс для элементов списка
class TRootLink
{
protected:
	PTRootLink pNext;
public:
	TRootLink(PTRootLink pN = nullptr) { pNext = pN; }
	PTRootLink GetNextLink() { return pNext; }
	void SetNextLink(PTRootLink pLink) { pNext = pLink; }
	void InsNextLink(PTRootLink pLink) 
	{ 
		PTRootLink p = pNext; pNext = pLink; if (pLink != nullptr) pLink->pNext = p;
	}
	virtual void SetDatValue(PTDatValue pVal) = 0;
	virtual PTDatValue GetDatValue() const = 0;
	friend class TDatList;
};