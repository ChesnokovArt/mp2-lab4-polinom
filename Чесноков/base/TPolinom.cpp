#include "TPolinom.h"
#include <iostream>

using namespace std;
TPolinom::TPolinom(int** monoms, int km) : THeadRing(new TMonom(0, -1))
{
	for (int i = 0; i < km; i++)
	{
		InsLast(new TMonom(monoms[i][0], monoms[i][1]));
	}
}

TPolinom::TPolinom(TPolinom & q) : THeadRing(new TMonom(0, -1))
{
	Reset();
	while (!q.IsListEnded())
	{
		InsLast(q.GetMonom()->GetCopy());
		q.GoNext();
	}
	InsLast(q.GetMonom()->GetCopy());
	Reset();
}

TPolinom & TPolinom::operator+(TPolinom & q)
{
	Reset();
	TPolinom* res = new TPolinom(*this);
	res->Reset();
	q.Reset();
	while (!(*res->GetMonom() == *(PTMonom)(pStop->GetDatValue())))
	{
		if (*res->GetMonom() < *q.GetMonom())
		{
			res->InsCurrent(q.GetMonom()->GetCopy());
			q.GoNext();
		}
		else if (*res->GetMonom() == *q.GetMonom())
		{
			*(res->GetMonom()) += *q.GetMonom();
			if (res->GetMonom()->Coeff == 0)
			{
				res->DelCurrent();
				q.GoNext();
				if (res->IsEmpty())
				{
					break;
				}
				continue;
			}
			q.GoNext();
			res->GoNext();
		}
		else res->GoNext();
	}
	while (!(*q.GetMonom() == *(PTMonom)(q.pStop->GetDatValue())))
	{
		res->InsLast(q.GetMonom()->GetCopy());
		q.GoNext();
	}
	return *res;
}

TPolinom & TPolinom::operator=(TPolinom & q)
{
	DelList();
	Reset(); q.Reset();
	if (q.IsEmpty()) return *this;
	while (!q.IsListEnded())
	{
		InsLast(q.GetMonom()->GetCopy());
		q.GoNext();
	}
	InsLast(q.GetMonom()->GetCopy());
	Reset(); q.Reset();
	return *this;
}


void TPolinom::printMonom(TMonom & m)
{
	if (m.GetCoeff() == 0 || m.GetIndex() < 0) return;
	cout << m.GetCoeff();
	if (m.GetIndexX())
	{
		if (m.GetIndexX() == 1) cout << "X";
		else cout << "X^" << m.GetIndexX();
	}
		
	if (m.GetIndexY())
	{
		if (m.GetIndexY() == 1) cout << "Y";
		else cout << "Y^" << m.GetIndexY();
	}
		
	if (m.GetIndexZ())
	{
		if (m.GetIndexZ() == 1) cout << "Z";
		else cout << "Z^" << m.GetIndexZ();
	}
		
	cout << " ";
}

void TPolinom::print()
{
	if (IsEmpty()) { cout << '0' << endl; return; }
	int i = GetCurrentPos();
	Reset();
	PTMonom m;
	//GoNext();
	m = GetMonom();
	printMonom(*m);

	while (!IsListEnded())
	{
		GoNext();
		m = GetMonom();
		if (m->GetCoeff() > 0) cout << '+';
		printMonom(*m);
	}
	cout << endl;
	SetCurrentPos(i);
}
