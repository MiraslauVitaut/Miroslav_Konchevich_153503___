
#ifndef TEST_4_MAIN_H
#define TEST_4_MAIN_H

#include <iostream>

char * Check( std::string s)
{

    std::string s1="";


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

    char * s11 =  new char [s1.length()];
    for(int i = 0 ; i< s1.length();i++)
    {
        s11[i] = s1[i];
    }

    return  s11;
}

#endif //TEST_4_MAIN_H
