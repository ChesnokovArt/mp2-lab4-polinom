#pragma once
#include "DatValue.h"

enum class MonomException
{
	InvalidOp
};
class TMonom : public TDatVal
{
protected:
	int Coeff;    // коэффициент монома
	int Index;    // свёртка степеней по десятичным цифрам (макс степень = 9)
public:
	TMonom(int cval = 1, int ival = 0) : Coeff(cval), Index(ival) {}
	TMonom(const TMonom& m) : Coeff(m.GetCoeff()), Index(m.GetIndex()) {}
	virtual TDatVal* GetDatVal() { return (TDatVal*)this; }
	void SetCoeff(int cval) { Coeff = cval; }
	int GetCoeff(void) const { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int GetIndex(void) const { return Index; }
	int GetIndexX(void) const { return Index / 100; }
	int GetIndexY(void) const { return (Index % 100) / 10; }
	int GetIndexZ(void) const { return Index % 10; }
	TMonom& operator= (const TMonom& tm)
	{
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	TMonom& operator+= (const TMonom& tm)
	{
		if (Index != tm.Index) throw MonomException::InvalidOp;
		Coeff += tm.Coeff;
		return *this;
	}
	// подобность
	int operator==(const TMonom& tm)
	{
		return (Index == tm.Index);
	}
	int operator<(const TMonom& tm)
	{
		return (Index < tm.Index);
	}

	virtual TDatVal* GetCopy()
	{
		return new TMonom(*this);
	}
	friend class TPolinom;
};

typedef TMonom* PTMonom;