#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class First
{
private:
	unsigned char *whole_part{ 0 };
	unsigned char *drob_part{ 0 };
	unsigned const int size_whole;
	unsigned const int size_drob;

public:
	First(unsigned int size_w = 0, unsigned int size_d = 0) : size_whole(size_w), size_drob(size_d)
	{
		srand(time(0));
		whole_part = new unsigned char[size_whole];
		drob_part = new unsigned char[size_drob];

		for (int i = 0; i < size_whole; i++)
		{
			whole_part[i] = '0' + rand() % 10;
			cout << whole_part[i];
		}
		cout << ',';
		for (int i = 0; i < size_drob; i++)
		{
			drob_part[i] = '0' + rand() % 10;
			cout << drob_part[i];
		}
		cout << endl;
	}
	friend First operator+(const First&, const First&);
	friend First operator-(const First&, const First&);
	friend First operator*(const First&, const First&);
	friend First operator==(const First&, const First&);
	unsigned char* magicArray(const First&, const First&);


	~First() 
	{
		delete[] whole_part;
		delete[] drob_part;
	}
};

