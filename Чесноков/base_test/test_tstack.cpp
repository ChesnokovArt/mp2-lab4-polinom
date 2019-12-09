#include "DatList.h"
#include "DatList.cpp"
#include "Monom.h"
#include <gtest.h>

TEST(TDatList, can_create_empty_list)
{
	EXPECT_NO_THROW(TDatList());
}

TEST(TDatList, constructed_list_is_empty)
{
	EXPECT_EQ(true, TDatList().IsEmpty());
	EXPECT_EQ(0, TDatList().GetListLength());
}

TEST(TDatList, can_not_get_value_from_empty_list)
{
	EXPECT_ANY_THROW(TDatList().GetDatValue());
}

TEST(TDatList, can_add_value_to_list_first)
{
	TDatList list;
	TMonom m(2, 2);
	EXPECT_NO_THROW(list.InsFirst(&m));
	EXPECT_EQ(false, list.IsEmpty());
	EXPECT_EQ(1, list.GetListLength());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
}

TEST(TDatList, can_iterate_over_the_list)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	EXPECT_EQ(false, list.IsEmpty());
	EXPECT_EQ(3, list.GetListLength());
	EXPECT_EQ(1, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(3, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_EQ(true, list.IsListEnded());
}

TEST(TDatList, can_delete_inner_link)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	list.SetCurrentPos(1);
	list.DelCurrent();
	list.Reset();
	EXPECT_EQ(2, list.GetListLength());
	EXPECT_EQ(1, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(3, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_EQ(true, list.IsListEnded());
}

TEST(TDatList, can_delete_first_link_by_delete_first)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	list.DelFirst();
	EXPECT_EQ(2, list.GetListLength());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(3, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_EQ(true, list.IsListEnded());
}

TEST(TDatList, can_delete_first_link_by_delete_current)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	list.DelCurrent();
	EXPECT_EQ(2, list.GetListLength());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(3, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_EQ(true, list.IsListEnded());
}

TEST(TDatList, can_delete_last_link_by_delete_cur)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	list.SetCurrentPos(list.GetListLength() - 1);
	list.DelCurrent();
	list.Reset();
	EXPECT_EQ(2, list.GetListLength());
	EXPECT_EQ(1, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_EQ(true, list.IsListEnded());
}

TEST(TDatList, can_delete_list)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);

	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	list.DelList();
	EXPECT_EQ(0, list.GetListLength());
	EXPECT_ANY_THROW(list.IsListEnded());
	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TDatList, throws_when_set_invalid_index)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);
	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);

	EXPECT_ANY_THROW(list.SetCurrentPos(3));
	EXPECT_ANY_THROW(list.SetCurrentPos(-1));
}

TEST(TDatList, throws_when_get_from_empty_list)
{
	TDatList list;
	EXPECT_ANY_THROW(list.GetDatValue());
}

TEST(TDatList, throws_when_go_next_in_ended_list)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);
	list.InsLast(&m1);
	list.InsLast(&m2);
	list.InsLast(&m3);
	list.GoNext();
	list.GoNext();
}

TEST(TDatList, insert_cur_works_fine)
{
	TDatList list;
	TMonom m1(1, 1);
	TMonom m2(2, 2);
	TMonom m3(3, 3);
	list.InsFirst(&m1);
	list.InsCurrent(&m2);
	list.InsCurrent(&m3);
	list.Reset();
	EXPECT_EQ(3, list.GetListLength());
	EXPECT_EQ(2, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(3, PTMonom(list.GetDatValue())->GetCoeff());
	EXPECT_NO_THROW(list.GoNext());
	EXPECT_EQ(1, PTMonom(list.GetDatValue())->GetCoeff());
}