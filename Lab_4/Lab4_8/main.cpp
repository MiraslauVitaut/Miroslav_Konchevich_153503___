#include <iostream>
int main()
{
    int k , mur = 0;
    int min = INT_MAX , max = INT_MIN , minindx = 0 , maxindx = 0 , count = 0;
    std::cout << "Введите размерность массива!" << std::endl;
    while (true) {
        std::cin >> k;
        if (std::cin.fail() || std::cin.peek() != '\n' || k < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }

    std::cout << std::endl;

    double* arr = new double[k];
    srand(time(0));


    for (int i = 0; i < k; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << arr[i] << "\t";

    }

    std::cout << std::endl;

    for(int i = 0 ; i < k; i++)
    {
        if (arr[i] < min )
        {
            min = arr[i];
            minindx = i;
        }

        if (arr[i] > max)
        {

            max = arr[i];
            maxindx = i;
        }

    }

    if (minindx > maxindx)
    {
        for (int i = maxindx + 1 ; i < minindx ; i++ )
        {
            arr[i] = 0;
            count++;

        }
    }
    else if (minindx < maxindx)
    {
        for (int i = minindx + 1; i < maxindx; i++)
        {
            arr[i] = 0;
            count++;
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < k; i++)
    {
        std::cout << arr[i] << "\t";

    }

    double* b = new double[k - count];

    std::cout << std::endl;

    if ((k - count) < count)
    {
        if (minindx > maxindx)
        {
            for (int i = 0; i <= maxindx; i++)
            {
                b[i] = arr[i];
                mur++;

            }
            for (int j = minindx; j < k; j++)
            {
                b[mur++] = arr[j];

            }
        }
        else if (minindx < maxindx)
        {
            for (int i = 0 ; i <= minindx;i++)
            {
                b[i] = arr[i];
                mur++;

            }
            for (int j = maxindx ; j < k ; j++ )
            {

                b[mur++] = arr[j];

            }
        }

        std::cout << std::endl;

        for(int i = 0; i < (k - count) ; i++)
        {

            std::cout << b[i] << "\t";

        }

    }
    else
    {
        return 0;

    }










    delete[] arr;
    delete[] b;




}
