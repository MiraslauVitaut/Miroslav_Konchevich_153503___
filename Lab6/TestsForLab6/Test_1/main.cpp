#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest1 , Hi1)
{
    EXPECT_STREQ(Check() , "Hello");
}
TEST(MyTest2 , Hi2)
{
    std::string str = "s s s s sd sdd sd sd sd gfgfgfgffggfgf h h h h h ds";

    str += ' ';

    int * arr2 = Search(str);


    EXPECT_EQ(arr2[0] , 10); //// номер слова в строке
    EXPECT_EQ(arr2[1] , 14); //// кол-во букв максимального слова
    EXPECT_EQ(arr2[2] , 25); /// позиция в строке слова

}
TEST(MyTest3 , Hi3)
{
    std::string str = "gfgfgfgffggfgf s s s sd sdd sd sd sd gfgfgfgffggfgf h h h h h ds";

    str += ' ';

    int * arr2 = Search(str);


    EXPECT_EQ(arr2[0] , 10); //// номер слова в строке
    EXPECT_EQ(arr2[1] , 14); //// кол-во букв максимального слова
    EXPECT_EQ(arr2[2] , 38); /// позиция в строке слова

}
TEST(MyTest4 , Hi4)
{
    std::string str = "gfgfgfgffggfgf s gfgfgfgffggfgf s gfgfgfgffggfgf sdd gfgfgfgffggfgf sd sd gfgfgfgffggfgf h h gfgfgfgffggfgf h gfgfgfgffggfgf ds";

    str += ' ';

    int * arr2 = Search(str);


    EXPECT_EQ(arr2[0] , 15); //// номер слова в строке
    EXPECT_EQ(arr2[1] , 14); //// кол-во букв максимального слова
    EXPECT_EQ(arr2[2] , 111); /// позиция в строке слова

}
TEST(MyTest5 , Hi5)
{
    std::string str = "gfgfgfgffggfgf s s s sd gfgfgfgffggfgfgf sd sd sd gfgfgfgffggfgf h h h h h ds";

    str += ' ';

    int * arr2 = Search(str);


    EXPECT_EQ(arr2[0] , 6); //// номер слова в строке
    EXPECT_EQ(arr2[1] , 16); //// кол-во букв максимального слова
    EXPECT_EQ(arr2[2] , 25); /// позиция в строке слова

}
