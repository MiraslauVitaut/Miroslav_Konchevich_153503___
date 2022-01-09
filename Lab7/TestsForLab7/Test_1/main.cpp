#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest1 , Hi1)
{
    EXPECT_EQ(Convert("32" , false) , 1122);
}
TEST(MyTest2 , Hi2)
{
    EXPECT_EQ(Convert("13" , false) , 122);
}
TEST(MyTest3 , Hi3)
{
    EXPECT_EQ(Convert("14" , false) , 200);
}
TEST(MyTest4 , Hi4)
{
    EXPECT_EQ(Convert("1" , false) , 1);
}
TEST(MyTest5 , Hi5)
{
    EXPECT_EQ(Convert("2" , false) , 2);
}
TEST(MyTest6 , Hi6)
{
    EXPECT_EQ(Convert("-2" , false) , -2);
}
