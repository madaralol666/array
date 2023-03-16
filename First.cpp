#include "First.h"
#include <iostream>

using namespace std;

First operator+(const First& a , const First& b)
{
    unsigned int carry = 0;
    int temp_size_drob = (a.size_drob > b.size_drob ? a.size_drob : b.size_drob);
    int temp_size_whole = (a.size_whole > b.size_whole ? a.size_whole : b.size_whole);
    First result(temp_size_drob, temp_size_whole);
    for (int i = 0; i < temp_size_drob; ++i) 
    {
        int sum = (a.drob_part[i] - '0') + (b.drob_part[i] - '0');

        carry = sum / 10;
        result.drob_part[i] = sum % 10 >= 10 ? sum + 48: sum % 10 + 48;
    }
    for (int i = 0; i < temp_size_whole; ++i)
    {
        int sum = (a.whole_part[i] - '0') + (b.whole_part[i] - '0');

        carry = sum / 10;
        result.whole_part[i] = sum % 10 >= 10 ? sum + 48 : sum % 10 + 48;
    }
    for (int i = 0; i < result.size_whole; i++)
    {
        cout << result.whole_part[i];
    }
    cout << '.';
    
    for (int i = 0; i < result.size_drob; i++)
    {
        cout << result.drob_part[i];
    }
    return result;
}
