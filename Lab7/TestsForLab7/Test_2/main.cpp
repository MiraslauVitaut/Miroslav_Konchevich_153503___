#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest1 , Hi1)
{
    EXPECT_EQ(Change("1") , 01 );
}
TEST(MyTest2 , Hi2)
{
    EXPECT_EQ(Change("2") , 10 );
}
TEST(MyTest3 , Hi3)
{
    EXPECT_EQ(Change("100") , 1100100 );
}


TEST(MyTest4 , Hi4)
{
    char * arr = new char[8];
    arr = ConvertToDop("1100100" , false);
    EXPECT_STREQ(arr , "01100100" );
}

TEST(MyTest5 , Hi5)
{
    char * arr = new char[8];
    arr = ConvertToDop("01" , false);
    EXPECT_STREQ(arr , "00000001" );
}

TEST(MyTest6 , Hi6)
{
    char * arr = new char[8];
    arr = ConvertToDop("01" , false);
    EXPECT_STREQ(arr , "00000001" );
}

TEST(MyTest7 , Hi7)
{
    char * arr = new char[8];
    arr = ConvertFromDopToPr("00000001" , false);
    EXPECT_STREQ(arr , "00000001");
}
