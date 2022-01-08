#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

TEST(MyTest , FunctionCheck)
{
    EXPECT_EQ(Check(2) , 2);
    EXPECT_NE(Check(1) , 1);
    EXPECT_NE(Check(-7) , -7);
}

TEST(Mytest2 , FunctionCreate)
{
    EXPECT_TRUE(Create(2));
}

TEST(MyTest3 , FunctionInitialize)
{
    const int n = 5;

    EXPECT_NO_THROW(Initialize(n));

    int array[n] = {1,2,5,1,2}; //// массив который должен быть при верной инициализации


    int * arr = new int [n]; /// создаем динамический массив и выделяем память под него


    arr = Initialize(n); /// присваем ссылку на массив , который инициализировался с помощью функции Initialize()

    for(int i = 0 ; i < n ; i++)
    {
            EXPECT_EQ(array[i], arr[i]); /// проверка на равенство массивов
    }


}

TEST(MyTest4 , FunctionCheck)
{
    const int n = 4;

    int arr1[n] = {2, 5,10,17};

    int * arr2 = new int [n];

    for(int i = 0 ; i < n ; i++ )
    {
        arr2[i] = arr1[i];
    }


    EXPECT_FALSE(check_array(arr2 ,0 , n-1  ));


}