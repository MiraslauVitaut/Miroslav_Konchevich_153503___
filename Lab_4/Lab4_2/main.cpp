#include<iostream>

int main()
{
    const int N = 4 , M = 6 ;
    int  min ;

    int MyArray[N][M] = {

            {23, 45, 21, 13, 89, 8},
            {78, 89, 32, 56, 2, 1},
            {21, 4, 21, 6, 7, 43},
            {32, 5, 6, 21, 1, 9}

    };

    for (int i = 0; i < M; i++)
    {
        min = INT_MAX;
        for ( int j = 0; j < N; j++)
        {
            if(MyArray[j][i] < min)
            {
                min = MyArray[j][i];
            }

        }
        std::cout << "Min element in column number " << i << " is equal to:" << min << "." << std::endl;

    }

}
