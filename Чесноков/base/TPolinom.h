#pragma once
#include "HeadRing.h"
#include "Monom.h"
class TPolinom : public THeadRing
{
public:
	// �������������� ��� ������ �������� � ������� ������������������� ��������
	TPolinom(int** monoms = nullptr, int km = 0);  // monoms - ���� "����-������"
	TPolinom(TPolinom& q);
	PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom& operator+(TPolinom& q);
	TPolinom& operator=(TPolinom& q);

	// DEBUG
	
	void print();
private:
	void printMonom(TMonom& m);
	
};

