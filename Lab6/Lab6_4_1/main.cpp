#include <iostream>
#include <fstream>

// Лабораторная 6, задача 4. Выполнена: Кончевич М.В.

using namespace std;

int main()
{

    string s, s1="";
    ifstream inf("/Users/miroslavkonchevich/Downloads/L6T4.txt");

    string s2 = "", s3;
    while (getline(inf, s3))
        s2 += s3;
    inf.close();

    s = s2;
    cout << s << endl;


    for( int i = 0; i < s.length(); i++ )
    {
        if (s[i]!=' ')
        {

            if (s[i]=='C' || s[i]=='Q' || s[i]=='W' || s[i]=='X')
            {
                continue;
            }


            if (s[i]=='q' && s[i+1]=='u')
            {
                s1 += "kv";
                i++;
                continue;
            }

            if (s[i]=='q')
            {
                s1 += 'k';
                continue;
            }

            if (s[i]=='x')
            {
                s1 += "ks";
                continue;
            }

            if (s[i]=='w')
            {
                s1 += 'v';
                continue;
            }

            if (s[i]=='Q' && s[i+1]=='u')
            {
                s1 += "Qv";
                i++;
                continue;
            }

            if (s[i]=='X')
            {
                s1 += "Xs";
                continue;
            }


            if (s[i]=='p' && s[i+1]=='h')
            {
                s1 += "f";
                i++;
                continue;
            }

            if (s[i]=='o' && s[i+1]=='o')
            {
                s1 += "u";
                i++;
                continue;
            }

            if (s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            {
                s1 += "u";
                i+=2;
                continue;
            }

            if (s[i]=='e' && s[i+1]=='e')
            {
                s1 += "i";
                i++;
                continue;
            }

            if (s[i]=='t' && s[i+1]=='h')
            {
                s1 += "z";
                i++;
                continue;
            }

            if (s[i]=='P' && s[i+1]=='h')
            {
                s1 += "P";
                i++;
                continue;
            }

            if (s[i]=='O' && s[i+1]=='o')
            {
                s1 += "U";
                i++;
                continue;
            }

            if (s[i]=='Y' && s[i+1]=='o' && s[i+2]=='u')
            {
                s1 += "U";
                i+=2;
                continue;
            }

            if (s[i]=='E' && s[i+1]=='e')
            {
                s1 += "I";
                i++;
                continue;
            }

            if (s[i]=='T' && s[i+1]=='h')
            {
                s1 += "Z";
                i++;
                continue;
            }


            if (s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='y')
            {
                if (s[i]=='c')
                {
                    s1 += 's';
                    continue;
                }

            }

        }
        s1 += s[i];
    }

    for(int i = 0 ; i < 10 ; i++)
    {

        s = s1;
        s1 = "";

        for (int i = 0; i < s.length(); i++){

            if (s[i] != ' ') {
                if (s[i] == s[i + 1]) {
                    s1 += s[i];
                    i++;
                    continue;
                }
            }

            s1 += s[i];
        }
    }



    cout << s1 << endl;

    ifstream ("/Users/miroslavkonchevich/Downloads/L6T4answer.txt");
    ofstream FileOut;
    FileOut.open("/Users/miroslavkonchevich/Downloads/L6T4answer.txt");
    FileOut << s;

    return 0;
}