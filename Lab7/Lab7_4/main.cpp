#include <iostream>
#include <cmath>

// Лабораторная 7, задача 4. Выполнена: Кончевич М.В.

int length(char*);
char* subtr(char*, char*);
double toTen(char*, int);
char* max(char*, char*);
char* min(char*, char*);
char* inputNum();
char* sum(char*, char*);

int main()
{

    std::cout << "Enter the first number: " << std::endl;
    char* num1 = inputNum();

    char* num3 = new char[15];

    std::cout << num1 << "    " << num3 << "    " << std::endl;

    for (int i = 0; i < length(num1) + 2; ++i)
    {
        num3[i] = num1[i];
    }

    if (num1[0] != 'r')
    {
        std::cout << std::endl;
        std::cout << "Enter the second number: " << std::endl;

        char* num2 = inputNum();

        char* num4 = new char[15];
        std::cout << num2 << "    " << num4 << "    " << std::endl;
        for (int i = 0; i < length(num2) + 2; ++i)
        {
            num4[i] = num2[i];
        }

        if (num2[0] != 'r')
        {
            std::cout << std::endl;
            std::cout << "Sum: " << sum(num1, num2) << std::endl;
            std::cout << "Razn: " << subtr(num3, num4) << std::endl;
        }
    }

    return 0;
}

double toTen(char* input, int lenght_input)
{
    bool minus = false;
    double answer = 0;
    int i = 0, step = lenght_input - 1;

    for (int j = 0; j < lenght_input; j++)
    {
        if (input[j] == '-')
        {
            minus = true;
            i = 1;
            --step;
        }
    }

    for (; i < lenght_input; ++i, --step)
    {

        if (input[i] >= '0' && input[i] <= '9')
        {
            answer += (input[i] - '0') * pow(14, step);
            continue;
        }
        if (input[i] == 'A' || input[i] == 'a')
        {
            answer += 10 * pow(14, step);
            continue;
        }
        if (input[i] == 'B' || input[i] == 'b')
        {
            answer += 11 * pow(14, step);
            continue;
        }
        if (input[i] == 'C' || input[i] == 'c')
        {
            answer += 12 * pow(14, step);
            continue;
        }
        if (input[i] == 'D' || input[i] == 'd')
        {
            answer += 13 * pow(14, step);
            continue;
        }
        if (input[i] == 'E' || input[i] == 'e')
        {
            answer += 13 * pow(14, step);
            continue;
        }
        if (input[i] == 'F' || input[i] == 'f')
        {
            answer += 13 * pow(14, step);
            continue;
        }
        if (input[i] == 'G' || input[i] == 'g')
        {
            answer += 13 * pow(14, step);
            continue;
        }
        if (input[i] == 'H' || input[i] == 'h')
        {
            answer += 13 * pow(14, step);
            continue;
        }
        if (input[i] == 'I' || input[i] == 'i')
        {
            answer += 13 * pow(14, step);
            continue;
        }
    }

    if (minus)
    {
        answer *= -1;
    }

    return answer;
}

char* max(char* num1, char* num2)
{
    if (toTen(num1, length(num1) + 1) > toTen(num2, length(num2) + 1))
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

char* min(char* num1, char* num2)
{
    if (toTen(num1, length(num1) + 1) > toTen(num2, length(num2) + 1))
    {
        return num2;
    }
    else
    {
        return num1;
    }
}

char* inputNum()
{
    char* num = new char[2];

    num[0] = '0';

    int len = 1;

    num[len] = std::getchar();

    if (num[len] != '-' && num[len] != '+' && (num[len] < '0' || num[len] > '9') && (num[len] < 'A' || num[len] > 'I'))
    {
        std::cout << "Error.";
        num[0] = 'r';
        return num;
    }

    if (num[len] == '+')
    {
        num[len] = std::getchar();
    }

    if (num[len] < '0' && num[len] > '9' && num[len] < 'A' && num[len] > 'I')
    {
        std::cout << "Error";
        num[0] = 'r';
        return num;
    }

    ++len;

    while (std::cin.peek() != '\n')
    {
        num[len] = std::getchar();

        if (num[len] < '0' && num[len] > '9' && num[len] < 'A' && num[len] > 'I')
        {
            std::cout << "Error";
            num[0] = 'r';
            return num;
        }

        ++len;

        num[len] = '\0';

        num = (char*)realloc(num, (len + 1) * sizeof(char));
    }

    std::cin.ignore(32324, '\n');

    return num;
}

int length(char* num)
{
    int len = 0;

    while (num[len] != '\0') ++len;

    return len - 1;
}

char* sum(char* num1, char* num2)
{
    bool p = false;
    bool k = false;
    if (num1[1] == '-' && num2[1] != '-')
    {
        for (int i = 1; i < length(num1); ++i)
        {
            num1[i] = num1[i + 1];
        }

        num1[length(num1)] = '\0';

        if (toTen(num1, length(num1) + 1) > toTen(num2, length(num2) + 1))
        {
            k = true;
        }

        num1 = subtr(max(num1, num2), min(num1, num2));

        if (k)
        {
            num1[length(num1) + 2] = '\0';

            for (int i = length(num1) + 1; i > -1; --i)
            {
                num1[i] = num1[i - 1];
            }

            num1[0] = '-';
        }
        return num1;
    }
    else if (num1[1] != '-' && num2[1] == '-')
    {
        for (int i = 1; i < length(num2); ++i)
        {
            num2[i] = num2[i + 1];
        }

        num2[length(num2)] = '\0';

        if (toTen(num1, length(num1) + 1) < toTen(num2, length(num2) + 1))
        {
            k = true;
        }

        num1 = subtr(max(num1, num2), min(num1, num2));

        if (k)
        {
            num1[length(num1) + 2] = '\0';

            for (int i = length(num1) + 1; i > -1; --i)
            {
                num1[i] = num1[i - 1];
            }

            num1[0] = '-';
        }

        return num1;
    }
    else if (num1[1] == '-' && num2[1] == '-')
    {
        for (int i = 1; i < length(num1); ++i)
        {
            num1[i] = num1[i + 1];
        }

        for (int i = 1; i < length(num2); ++i)
        {
            num2[i] = num2[i + 1];
        }

        num1[length(num1)] = '\0';
        num2[length(num2)] = '\0';

        p = true;
    }

    int val1, val2, exit = 0;
    int l1 = length(num1);
    int l2 = length(num2);

    for (int i = l1, j = l2; j > -1; --i, --j)
    {

        if (num1[i] >= '0' && num1[i] <= '9')
        {
            val1 = num1[i] - '0';
        }
        else
        {
            val1 = num1[i] - 55;
        }

        if (num2[j] >= '0' && num2[j] <= '9')
        {
            val2 = num2[j] - '0';
        }
        else
        {
            val2 = num2[j] - 55;
        }

        val1 += val2;

        if (val1 < 19 && exit == 0)
        {
            if (val1 < 10)
            {
                num1[i] = val1 + '0';
            }
            else
            {
                num1[i] = 55 + val1;
            }
        }
        else if (!exit)
        {
            exit = 1;
            if (val1 - 19 < 10)
            {
                num1[i] = val1 - 19 + '0';
            }
            else
            {
                num1[i] = val1 - 19 + 55;
            }
        }

        else if (val1 + 1 < 19)
        {
            ++val1;
            if (val1 < 10)
            {
                num1[i] = val1 + '0';
            }
            else
            {
                num1[i] = 55 + val1;
            }
            exit = 0;
        }
        else
        {
            ++val1;
            if (val1 - 19 < 10)
            {
                num1[i] = val1 - 19 + '0';
            }
            else
            {
                num1[i] = val1 - 19 + 55;
            }
        }
    }

    ++l2;
    if (exit)
    {
        while (true)
        {
            if (num1[l1 - l2] >= '0' && num1[l1 - l2] < '9')
            {
                num1[l1 - l2] += 1;
                break;
            }
            else if (num1[l1 - l2] == '9')
            {
                num1[l1 - l2] = 'A';
                break;
            }
            else if (num1[l1 - l2] < 'I')
            {
                num1[l1 - l2] += 1;
                break;
            }
            else
            {
                num1[l1 - l2] = '0';
                ++l2;
            }
        }
    }

    if (num1[0] == '0')
    {
        for (int i = 0; i < length(num1); ++i)
        {
            num1[i] = num1[i + 1];
        }

        num1[length(num1)] = '\0';
    }

    if (p)
    {
        for (int i = length(num1) + 1; i > 0; --i)
        {
            num1[i] = num1[i - 1];
        }
        num1[0] = '-';
    }

    return num1;
}

char* subtr(char* num1, char* num2)
{
    if (toTen(num1, length(num1) + 1) < toTen(num2, length(num2) + 1) && num1[1] != '-' && num2[1] != '-')
    {
        num1 = subtr(num2, num1);

        num1[length(num1) + 2] = '\0';

        for (int i = length(num1) + 1; i > -1; --i)
        {
            num1[i] = num1[i - 1];
        }

        num1[0] = '-';

        return num1;
    }
    else if (num1[1] == '-' && num2[1] != '-')
    {
        num2[length(num2) + 2] = '\0';

        for (int i = length(num2) + 1; i > 1; --i)
        {
            num2[i] = num2[i - 1];
        }

        num2[1] = '-';

        num2[0] = '0';

        return sum(num1, num2);
    }

    else if (num1[1] != '-' && num2[1] == '-')
    {
        for (int i = 1; i < length(num2); ++i)
        {
            num2[i] = num2[i + 1];
        }

        num2[length(num2)] = '\0';

        return sum(num1, num2);
    }

    else if (num1[1] == '-' && num2[1] == '-')
    {
        for (int i = 1; i < length(num2); ++i)
        {
            num2[i] = num2[i + 1];
        }

        num2[length(num2)] = '\0';

        return sum(num1, num2);
    }

    int val1, val2, exit = 0;
    int l1 = length(num1);
    int l2 = length(num2);

    for (int i = 0; i < length(num1); ++i)
    {
        num1[i] = num1[i + 1];
    }

    num1[length(num1)] = '\0';

    for (int i = 0; i < length(num2); ++i)
    {
        num2[i] = num2[i + 1];
    }

    num2[length(num2)] = '\0';

    for (int i = l1 - 1, j = l2 - 1; j > -1; --i, --j)
    {
        if (num1[i] >= '0' && num1[i] <= '9')
        {
            val1 = num1[i] - '0';
        }
        else
        {
            val1 = num1[i] - 55;
        }

        if (num2[j] >= '0' && num2[j] <= '9')
        {
            val2 = num2[j] - '0';
        }
        else
        {
            val2 = num2[j] - 55;
        }

        if (val1 - val2 >= 0)
        {
            if (val1 - val2 < 10)
            {
                num1[i] = val1 - val2 + '0';
            }
            else
            {
                num1[i] = val1 - val2 + 55;
            }
        }
        else
        {
            exit = i - 1;

            while (true)
            {
                if (num1[exit] == '0')
                {
                    --exit;
                }
                else if ((num1[exit] > '0' && num1[exit] <= '9') || (num1[exit] > 'A' && num1[exit] <= 'I'))
                {
                    --num1[exit];
                    break;
                }
                else
                {
                    num1[exit] = '9';
                    break;
                }
            }

            if (val1 - val2 + 19 < 10)
            {
                num1[i] = val1 - val2 + 19 + '0';
            }
            else
            {
                num1[i] = val1 - val2 + 19 + 55;
            }
        }
    }

    return num1;
}
