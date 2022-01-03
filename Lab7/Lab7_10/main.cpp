#include "iostream"
#include "cmath"

// Лабораторная 7, задача 10. Выполнена: Кончевич М.В.

std::string numbto3(int number);
int numbto10(std::string number);

int main()
{
    int p;

    std ::cin >> p;
    std::string poisoned = numbto3(p);
    std::string slaves = "00000";

    std::string* barrels = new std::string[240];
    for (int i = 0; i < 240; i++)
    {
        barrels[i] = numbto3(i);
    }

    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (barrels[i][j] == '0' || barrels[i][j] == '2')
            {
                continue;
            }
            if (barrels[i] == poisoned)
            {
                slaves[j] = '1';
            }
        }
    }

    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (barrels[i][j] == '0' || barrels[i][j] == '1')
            {
                continue;
            }
            if (barrels[i] == poisoned)
            {
                slaves[j] = '2';
            }
        }
    }

    std::cout << numbto10(slaves);
}

std::string numbto3(int number)
{
    std::string ans;
    while (number != 0)
    {
        ans = char(48 + number % 3) + ans;
        number /= 3;
    }
    while (ans.length() < 5)
    {
        ans = '0' + ans;
    }
    return ans;
}

int numbto10(std::string number)
{
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans += (number[i] - '0') * pow(3, 4 - i);
    }
    return ans;
}