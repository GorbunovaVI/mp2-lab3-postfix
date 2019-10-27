#include "postfix.h"
#include <gtest.h>


TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix ("a+b"));
}
TEST(TPostfix, postfix_test_one)
{
	string tmp="a+b";
	TPostfix k(tmp);
	EXPECT_EQ("ab+", k.ToPostfix());
}
TEST(TPostfix, postfix_test_two)
{
	string tmp = "a+b*c";
	TPostfix k(tmp);
	EXPECT_EQ("abc*+", k.ToPostfix());
}
TEST(TPostfix, postfix_test_three)
{
	string tmp = "a/d*b-c*e";
	TPostfix k(tmp);
    EXPECT_EQ("ad/b*ce*-", k.ToPostfix());
}
TEST(TPostfix, postfix_test_four)
{
	string tmp = "(a+b)-d*(c-e)";
	TPostfix k(tmp);
	EXPECT_EQ("ab+dce-*-", k.ToPostfix());
}
TEST(TPostfix, postfix_test_five)
{
	string tmp = "a+b-c*k/d-z*(e-p)";
    TPostfix k(tmp);
	EXPECT_EQ("ab+ck*-d/zep-*-", k.ToPostfix());
}
TEST(TPostfix, calculate_test_one)
{
	string a;
	a = "6+5";
	TPostfix k(a);
	k.ToPostfix();
	EXPECT_EQ(11, k.Calculate());
}
TEST(TPostfix,calculate_test_two)
{
	string a;
	a = "10-8/2";
    TPostfix k(a);
	k.ToPostfix();
	EXPECT_EQ(6, k.Calculate());
}

TEST(TPostfix, calculate_test_three)
{
	string a;
	a = "70/2+6086-178*4";
	TPostfix k(a);
	k.ToPostfix();
	EXPECT_EQ(5409, k.Calculate());
}

TEST(TPostfix,calculate_test_four)
{
	string a;
	a = "8978-635*(14+2)+2336";
	TPostfix k(a);
	k.ToPostfix();
	EXPECT_EQ(1154, k.Calculate());
}