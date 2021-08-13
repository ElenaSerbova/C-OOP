#pragma once
#include <exception>
using namespace std;

class index_out_of_range : public logic_error
{
public:

	const char* what() const override {
		return "Index out of range";
	}
};

