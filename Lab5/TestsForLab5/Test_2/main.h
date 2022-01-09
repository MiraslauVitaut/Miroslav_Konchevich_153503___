
#ifndef TEST_2_MAIN_H
#define TEST_2_MAIN_H

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

bool Create(int n)
{
    int* A;/// Создаем матрицу введенной размерности
    A = new int[n]; /// через массив указателей

    return true;
}

int * Initialize(int N)
{

    int array[5] = {1,2,5,1,2}; /// массив значений эл-ов , которые вводит пользователь с консоли
    int k = 0;

    int * A = new int [N];


    //////////////////////// void Initialize()

    for(int i = 0; i < N; i++)
    {

            A[i] = array[k];
            k++;

    }

    return A;

    ///////////////////////

}

bool check_array(int * A,int first, int last)
{


    if(first == last)
    {
        return A[first]<=first*first;
    }

    int mid = first + (last - first)/2;
    return check_array(A, first, mid) || check_array(A, mid + 1, last);
}

#endif //TEST_2_MAIN_H
