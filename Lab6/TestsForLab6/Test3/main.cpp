#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest1 , Hi1)
{
    EXPECT_STREQ(Check() , "H");
}
TEST(MyTest2 , Hi2)
{
    char arr[4] = {'d', 's' , 'a' , 'l'};


    char * arr2 =  new char[4];
    arr2 = Search("dddddssssddddssssddddssssddddsssalalalallalalala");

    for(int i = 0 ; i < 4;i++)
    {
        EXPECT_EQ(arr2[i],arr[i]);
    }

}

TEST(MyTest3 , Hi3)
{
    char arr[1] = {'d'};


    char * arr2 =  new char[1];
    arr2 = Search("dddddddddddddddddddddddddddddddddddddddddddddddddddddd");

    for(int i = 0 ; i < 1;i++)
    {
        EXPECT_EQ(arr2[i],arr[i]);
    }

}