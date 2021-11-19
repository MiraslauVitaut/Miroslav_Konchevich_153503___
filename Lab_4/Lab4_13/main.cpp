#include <iostream>



int main() {
    srand(time(0));
    int N , count = 0;
    std::cout << "Введите кол-во удлинителей , купленных Мишей!" << std::endl;
    while (true) {
        std::cin >> N;
        if (std::cin.fail() || std::cin.peek() != '\n' || N < 1 ) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "incorrect data, try again" << std::endl;
        }
        else break;
    }

    int *arr = new int [N];

    for(int i = 0 ; i < N; i++)
    {
        arr[i] = rand() % 10 + 1;
        std::cout << "Кол-во входов в " << i + 1 << " удлинителе равно: " << arr[i] << std::endl;
    }

    for(int j = 0; j < N ; j++)
    {
        if((j + 1) < N)
        {
            count += arr[j] - 1;
        }
        else if(j + 1 == N)
        {
            count += arr[j];
        }
    }

    delete[] arr;

    std::cout << std::endl;
    std::cout << "Кол-во розеток , которые получит Миша в итоге равно: " << count << std::endl;


    return 0;
}
