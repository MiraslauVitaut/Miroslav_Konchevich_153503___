//
// Created by Miroslav Konchevich on 8.01.22.
//

#ifndef TEST_3_2_MAIN_H
#define TEST_3_2_MAIN_H

int Check(int n)
{
    if ( n > 1)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

bool Create(int n , int m)
{
    double ** A;
    A = new double *[n];
    for (int i = 0; i < m; i++)
    {
        A[i] = new double [n];
    }
    return true;
}

double ** Initialize(int N, int M)
{

    double array[16] = {1.2,2.5,5,1.2,2.5,5.6,1.2,2.5,5.6}; /// массив значений эл-ов , которые вводит пользователь с консоли
    int k = 0;

    double ** A = new double *[N];
    for (int i = 0; i < M; i++)
    {
        A[i] = new double [N];
    }

    //////////////////////// void Initialize()

    for(int i = 0; i < N; i++)
    {
        for(int j = 0;  j < M;  j++ )
        {
            A[i][j] = array[k];
            k++;
        }
    }

    return A;

    ///////////////////////

}

#endif //TEST_3_2_MAIN_H
