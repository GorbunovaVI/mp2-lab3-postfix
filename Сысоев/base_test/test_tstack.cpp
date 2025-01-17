#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, cannot_create_stack_with_large_length)
{
	ASSERT_ANY_THROW(TStack<int> s(MaxStackSize + 1));
}

TEST(TStack, can_set_and_get_element)
{
	TStack<int> s(4);
	s.Push(2);
	EXPECT_EQ(s.Pop(), 2);
}

TEST(TStack, check_on_empty_stack)
{
	TStack<int> s(4);
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, check_on_full_stack)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.Push(i + 1);
	EXPECT_EQ(true, s.IsFull());
}

TEST(TStack, throw_to_the_excess_size)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; i++)
		s.Push(i + 1);

	ASSERT_ANY_THROW(s.Push(5));
}

TEST(TStack, can_get_size)
{
	TStack<int> s(5);
	EXPECT_EQ(5, s.Getsize());
}

TEST(TStack, show_elem_of_stack)
{
	TStack<int> s(4);
	s.Push(4);
	EXPECT_EQ(4, s.Top());
}

TEST(TStack, throw_on_an_opportunity_to_get_elem)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, throw_on_an_opportunity_to_show_elem)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, check_IsEmpty)
{
	TStack<int> s(4);
	s.Push(2);
	EXPECT_NE(true, s.IsEmpty());
}

TEST(TStack, check_IsFull)
{
	TStack<int> s(5);
	EXPECT_NE(true, s.IsFull());
}

TEST(TStack, can_push_and_pop)
{
	TStack<int> s(5);
	s.Push(3);
	s.Pop();
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, can_push)
{
	TStack<int> s(5);
	s.Push(3);
	EXPECT_EQ(false, s.IsEmpty());
}

