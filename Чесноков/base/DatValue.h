#pragma once
class TDatVal
{
public:
	virtual TDatVal* GetCopy() = 0;  // cоздание копии
	~TDatVal() {}
};

typedef TDatVal* PTDatValue;