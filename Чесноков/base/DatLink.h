#pragma once
#include "RootLink.h"
class TDatLink;
typedef TDatLink* PTDatLink;

class TDatLink : public TRootLink
{
protected:
	PTDatValue pValue;   // указатель на объект-значение
public:
	TDatLink(PTDatValue pVal = nullptr, PTRootLink pN = nullptr) : TRootLink(pN) { pValue = pVal; }
	void SetDatValue(PTDatValue pVal) { pValue = pVal; }
	PTDatValue GetDatValue() const { return pValue; }
	PTDatLink GetNextDatLink() const { return (PTDatLink)pNext; }

	friend class TDatList;
};