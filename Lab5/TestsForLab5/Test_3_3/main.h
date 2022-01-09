
#ifndef TEST_3_3_MAIN_H
#define TEST_3_3_MAIN_H

int Check(int n , int m)
{
    if ( n > 1 || m > 1)
    {
        return (n + m);
    }
    else
    {
        return 0;
    }
}

bool Create(int n , int m)
{
    int** A;
    A = new int *[n];
    for (int i = 0; i < m; i++)
    {
        A[i] = new int [n];
    }
    return true;
}

int ** Initialize(int N, int M)
{

    int array[16] = {1,2,5,1,2,5,1,2,5}; /// массив значений эл-ов , которые вводит пользователь с консоли
    int k = 0;

    int ** A = new int *[N];
    for (int i = 0; i < M; i++)
    {
        A[i] = new int [N];
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

#endif //TEST_3_3_MAIN_H
