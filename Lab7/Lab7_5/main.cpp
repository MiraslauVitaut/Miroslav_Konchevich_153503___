// Лабораторная 7, задача 5. Выполнена: Кончевич М.В.
#include <iostream>
#include <string>

    int main()
    {
        char romanian[7] = { 'I','V','X','L', 'C', 'D', 'M' }; /// массив римских символов
        int arabic[7] = { 1, 5, 10, 50, 100, 500, 1000 }; ///массив арабских символов(соотв. римским)

        std::string romnumb = ""; /// создаем пустую строку

        int arabnumb = 0;

        std::cout << "Введите число: " << std::endl;
        std::cin >> arabnumb; /// вводим число

        for (int i = 6; i >= 0; i--)
        {
            while (arabnumb >= arabic[i])
            {
                if (arabnumb >= arabic[i] * 4)
                {
                    arabnumb -= arabic[i] * 4;
                    romnumb = romnumb + romanian[i]+ romanian[i]+ romanian[i]+ romanian[i];
                }
                else
                {
                    arabnumb -= arabic[i];
                    romnumb += romanian[i];
                }
            }
        }
        std::cout << romnumb << "\n";
    }