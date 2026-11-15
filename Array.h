#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <iostream>
using namespace std;

class Array
{
	int* data;
	int capacity;
public:
	bool isValidIndex(int index);
	Array(int = 0);
	~Array();
	Array(const Array&);
	void display();
	int getsize();
	int& getSet(int index);
	void resize(int newCapacity);
};

#endif
#pragma once
