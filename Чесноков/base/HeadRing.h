#pragma once
#include "DatList.h"
class THeadRing : public TDatList
{
protected:
	PTDatLink pHead;
public:
	THeadRing(PTDatValue Head);
	~THeadRing();

	virtual void InsFirst(PTDatValue pVal = nullptr);
	virtual void InsLast(PTDatValue pVal = nullptr);
	virtual void InsCurrent(PTDatValue pVal = nullptr);
	virtual void DelFirst(void);
};