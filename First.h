#pragma once
class First
{
private:
	unsigned const int max_size;
	unsigned char *whole_part{ 0 };
	unsigned char *drob_part{ 0 };
	unsigned const int size_whole;
	unsigned const int size_drob;

public:
	First(unsigned int size, unsigned int size_w, unsigned int size_d) : max_size(size), size_whole(size_w), size_drob(size_d)
	{
		whole_part = new unsigned char[max_size];
		drob_part = new unsigned char[max_size];
	}
	First() 
	{
	
	}

	~First() 
	{
		delete[] whole_part;
		delete[] drob_part;
	}
	void random_array();
};

