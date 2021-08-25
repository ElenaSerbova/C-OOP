#pragma once

template <typename T>
class SmartPointer
{
public:	

	SmartPointer(T* ptr = nullptr) : _ptr(ptr) {
		
	}

	~SmartPointer() {
		delete _ptr;
	}

	SmartPointer(const SmartPointer& pointer) = delete;
	SmartPointer& operator=(const SmartPointer& pointer) = delete;

	T& operator*() const {
		return *_ptr;
	}

	T* operator->() const {
		return _ptr;
	}

private:

	T* _ptr = nullptr;
};

