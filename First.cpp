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

unsigned char* First::magicArray(const First& a, const First& b)
{
    int bigger_drob_size = (a.size_drob > b.size_drob ? a.size_drob : b.size_drob);
    unsigned char* small_array = (a.size_drob > b.size_drob ? a.drob_part : b.whole_part);
    int difference = (a.size_drob > b.size_drob ? a.size_drob - b.size_drob : b.size_drob - a.size_drob);
    unsigned char* new_array = new unsigned char[bigger_drob_size];
    for (int i = 0; i <sizeof(small_array); i++)
    {
        new_array[i] = small_array[i];
    }
    for (int i = sizeof(small_array); i < bigger_drob_size; i++)
    {
        new_array[i] = '0';
    }
    return nullptr;
}
