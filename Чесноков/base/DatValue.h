#pragma once
class TDatVal
{
public:
	virtual TDatVal* GetCopy() = 0;  // c������� �����
	~TDatVal() {}
};

typedef TDatVal* PTDatValue;