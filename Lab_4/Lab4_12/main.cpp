#include <iostream>



int DeleteElements(double *arr , int *count , int k) ///функция удаления дубликатов и вывода массива в консоль
{
    if(k - (*count) == 0)
    {
        std::cout << "Дубликатов элементов в массиве нет!" << std::endl;
        return 0;
    }
    else
    {
        double *arr2 = (double *) malloc(sizeof(double) * k);
        realloc(arr2, sizeof(double) * (k - (k - (*count))));
        arr2[0] = arr[0];
        int p = 0;

        for (int j = 0; j < k; j++)
        {

            bool isUnic = true;

            for (int i = j + 1; i < k; i++)
            {
                if (arr[j] == arr[i])
                {
                    isUnic = false;
                    break;
                }
            }

            if (isUnic)
            {
                arr2[p] = arr[j];
                p++;
            }

        }

        std::cout << "Массив без дубликатов: " <<std::endl;
        for (int i = 0; i < p; i++)
        {
            std::cout << arr2[i] << "\t";
        }

        delete[] arr2;
    }

    }



void SearchItem(double *arr , int *count , int k , int indx , int UnicElements) ///функция поиска дубликатов в массиве
{
    *count = k;
    for(int j = 0 ; j < k; j++)
    {

        bool isUnic = true;

            for (int i = j+1; i < k; i++)
            {
                if (i != j && arr[j] == arr[i])
                {
                    isUnic = false;
                    break;
                }
            }

            if(!isUnic)
            {
                (*count)--;
            }

        }

    std::cout << "Дубликатов в массиве: " << (k - (*count)) << std::endl;

}

int main()
{
    int k , count = 0 , indx = 10 , UnicElements = 0;

    std::cout << "Введите длинну массива:" << std::endl;
    while (true) {
        std::cin >> k;
        if (std::cin.fail() || std::cin.peek() != '\n' || k < 2) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }


   double* arr = (double*) malloc(sizeof(double) * k);

   srand(time(0));

   for(int i = 0; i < k ; i++)
   {
       arr[i] = rand() % 10 + 1;
       std::cout << arr[i] << "\t";
   }

   std::cout << std::endl;

    SearchItem( arr , &count , k , indx , UnicElements);
    std::cout << std::endl;
    DeleteElements( arr , &count , k);


    delete[] arr;

}
