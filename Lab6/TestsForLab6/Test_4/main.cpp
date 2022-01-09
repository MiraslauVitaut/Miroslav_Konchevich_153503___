#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest1 , Hi1)
{
    EXPECT_STREQ(Check("kkkkkkkkkkkkkkkkk") , "k");
}
TEST(MyTest2 , Hi2)
{
    EXPECT_STREQ(Check("aaaaabbbbbccccc") , "abc");
}
TEST(MyTest3 , Hi3)
{
    EXPECT_STREQ(Check("Too swift for Theex, too quick for Gallow") , "Tu svift for Ziks, tu kvick for Galov");
}
TEST(MyTest4 , Hi4)
{
    EXPECT_STREQ(Check("Too strong for young Prince Joseph to follow") , "Tu strong for ung Prinse Josef to folov");
}