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

TEST(MyTest2 , FunctionCreate)
{
    EXPECT_TRUE(Create(2.3 ,2.3));
    EXPECT_ANY_THROW(Create(-1 , -1));
}

TEST(MyTest3 , FunctionInitialize)
{


    const int n = 3;

    EXPECT_NO_THROW(Initialize(n , n));

    double array[n][n] = //// массив который должен быть при верной инициализации
            {
                    {1.2,2.5,5  },
                    {1.2,2.5,5.6  },
                    {1.2,2.5,5.6  }

            };

    double ** arr = new double * [n]; /// создаем двумерный динамический массив и выделяем память под него
    for(int i = 0 ; i < n;i++)
    {
        arr[i] = new double [n];
    }

    arr = Initialize(n, n); /// присваем ссылку на массив , который инициализировался с помощью функции Initialize()

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            EXPECT_EQ(array[i][j], arr[i][j]); ///проверка на равенство массивов
        }
    }



}

