#include <iostream>

int main()
{

    int n = 0  , count = 0 , temp = 0;
    std::cout << "Введите натуральное число:" << std::endl;
    while (true) {
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n' || n < 1) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }

    temp = n;

    do
    {
        count++;
    }
    while (temp /= 10);


    int* arr = new int[count];

    for(int i = 0 ; i < count ; i++)
    {
        arr[i] = n % 10;

        n /= 10;


    }
    std::cout << std::endl;
    std::cout << "Количество цифр числа: " << count <<  std::endl;
    std::cout << std::endl;

    for(int j = 0; j < count; j++)
    {
        std::cout << "Цифра стоящая в разряде номер " << j << ": " << arr[j] << std::endl;
    }

    delete[] arr;
}
