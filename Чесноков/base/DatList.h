#pragma once
#include "DatLink.h"
class TDatList
{
protected:
	PTDatLink pFirst;    //������ �����
	PTDatLink pLast;     // ��������� ����� 
	PTDatLink pCurrLink; // ������� �����
	PTDatLink pPrevLink; // ����� ����� �������
	PTDatLink pStop;     // �������� ���������, ����������� ����� ������
	int CurrPos;         // ����� �������� ����� (��������� �� 0)
	int ListLen;         // ���������� ������� � ������

	//PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
	//void DelLink(PTDatLink pLink); // �������� �����

public:
	TDatList();
	~TDatList() { DelList(); }
	/* ������ � ��������� --------------------------------------------------*/
	PTDatValue GetDatValue(); // ��������� �������� �������� �����
	virtual int IsEmpty() const { return pFirst == pStop; }
	int GetListLength() const { return ListLen; }

	/* ���������-------(���������� � 0)-------------------------------------*/
	int SetCurrentPos(int pos);
	int GetCurrentPos(void) const;          // �������� ����� ���. �����
	virtual int Reset ( void );             // ���������� �� ������ ������
	// c�������� ���������� ���� ����� goNext cur ������ pstop
	virtual int IsListEnded ( void ) const; // ������ �������� ?
	int GoNext ( void );                    // ����� ������ �������� �����
				// (=1 ����� ���������� GoNext ��� ���������� ����� ������)
	/* ������� �������------------------------------------------------------*/
	virtual void InsFirst(PTDatValue pVal = nullptr);   // ����� ������
	virtual void InsLast ( PTDatValue pVal= nullptr);   // �������� ���������
	virtual void InsCurrent( PTDatValue pVal= nullptr); // ����� ������� 
	/* �������� �������-----------------------------------------------------*/
	// ��� �������� �������� ����� �������� ����� �������
	virtual void DelFirst ( void );  // ������� ������ �����
	// ��� �������� ���������� ����� �������� ����� �������
	virtual void DelCurrent( void ); // ������� ������� �����
	virtual void DelList();
};

enum class ListException
{
	EmptyList,
	OutOfBound
};