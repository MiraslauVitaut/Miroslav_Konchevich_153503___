
#include <iostream>
#include <cmath>

// Лабораторная 6, задача 9. Выполнена: Кончевич М.В.

double exponenta(char* arr, int& i)
{
    int sum1 = 0;
    if (i != 0 && arr[i - 1] - 48 <= 9 && arr[i - 1] - 48 >= 0 && arr[i] == 'e' && arr[i + 1] - 48 <= 9 && arr[i + 1] - 48 >= 0)
    {
        int k = 0;
        for (int j = i + 1; arr[j] - 48 <= 9 && arr[j] - 48 >= 0; j++, k++) {}
        int j = i + 1;
        for (; k >= 1; j++, k--)
        {
            int t = k - 1;
            double number = arr[j] - 48;
            while (t--)
            {
                number *= 10;
            }
            sum1 += number;
        }
        i = j;
    }
    else if (i != 0 && arr[i - 1] - 48 <= 9 && arr[i - 1] - 48 >= 0 && arr[i] == 'e' && arr[i + 1] == '-' && arr[i + 2] - 48 <= 9 && arr[i + 2] - 48 >= 0)
    {
        int k = 0;

        for (int j = i + 2; arr[j] - 48 <= 9 && arr[j] - 48 >= 0; j++, k++) {}

        int j = i + 2;
        for (; k >= 1; j++, k--)
        {
            int t = k - 1;

            double number = arr[j] - 48;
            while (t--)
            {
                number *= 10;
            }
            sum1 += number;
        }

        i = j;

        sum1 *= -1;
    }
    return sum1;
}

void DeleteArray(char * arr)
{
    free(arr);
}

int main()
{
    int numb = 1;
    double sum = 0;

    char* arr = (char*)malloc(numb * sizeof(char*));


    for (int i = 0; std::cin.peek() != '\n'; i++)
    {
        arr[i] = std::cin.get();
        numb++;
        arr = (char *) realloc(arr, numb * sizeof(char *));
    }

    numb--;

    for (int i = 0; i < numb; i++)
    {
        if (arr[i] == '-' && arr[i + 1] - '0' <= 9 && arr[i + 1] - '0' >= 0)
        {
            double sum1 = 0;
            int k = 0;

            for (int j = i + 1; arr[j] - '0' <= 9 && arr[j] - '0' >= 0; j++, k++) {}

            int j = i + 1;

            for (; k >= 1; j++, k--)
            {
                int t = k - 1;

                double number = arr[j] - '0';

                while (t--)
                {
                    number *= 10;
                }
                sum1 -= number;
            }

            if (arr[j] == '.' && arr[j + 1] - '0' <= 9 && arr[j + 1] - '0' >= 0)
            {
                for (j++, k = 1; arr[j] - '0' <= 9 && arr[j] - '0' >= 0; j++, k++)
                {

                    double number = arr[j] - '0';

                    while (k--)
                    {
                        number /= 10;
                    }

                    sum1 -= number;
                }
            }
            i = j;
            double current_sum = exponenta(arr, i);
            --i;
            sum += sum1 * pow(10, current_sum);
        }
        else if (arr[i] - '0' <= 9 && arr[i] - '0' >= 0)
        {

            double sum1 = 0;
            int k = 0;
            for (int j = i; arr[j] - '0' <= 9 && arr[j] - '0' >= 0; j++, k++) {}
            int j = i;

            for (; k >= 1; j++, k--)
            {

                int t = k - 1;
                double number = arr[j] - '0';
                while (t--)
                {
                    number *= 10;
                }
                sum1 += number;
            }

            if (arr[j] == '.' && arr[j + 1] - '0' <= 9 && arr[j + 1] - '0' >= 0)
            {
                for (++j, k = 1; arr[j] - '0' <= 9 && arr[j] - '0' >= 0; j++, k++)
                {

                    double number = arr[j] - '0';
                    while (k--)
                    {
                        number /= 10;
                    }

                    sum1 += number;
                }
            }
            i = j;
            double rezsum = exponenta(arr, i);
            --i;;
            sum += sum1 * pow(10, rezsum);
        }
    }
    std::cout << sum << "\n";

    DeleteArray(arr);
}



