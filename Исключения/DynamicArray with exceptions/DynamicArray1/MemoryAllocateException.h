#pragma once
#include <exception>
using namespace std;

class MemoryAllocateException : public exception
{
public: 

	const char* what() const override {
		return "Can`t allocate memory";
	}
};

