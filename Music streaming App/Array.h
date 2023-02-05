
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	template <class A>
	friend ostream& operator<<(ostream& ost, Array<A>& arr);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T&);
		T& operator[](int index);
		T& operator[](int index) const;
		int getSize() const;
		bool isFull() const;
		Array<T>& operator+=(T& t);
		Array<T>& operator-=(T& t);
		void clear();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(T& t){
	if (size >= MAX_ARRAY)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARRAY;
}

template <class T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
ostream& operator<<(ostream& ost, Array<T>& arr) {
	for (int i = 0; i < arr.size; ++i) {
		ost<<arr[i]<<endl;
	}
	return ost;
}

template <class T>
Array<T>& Array<T>::operator+=(T& t) {
	if (!isFull()) {
		this->add(t);
	}
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T& t) {
	int index = 0;
	while(index < size) {
		if ((*this)[index] == t) {
			break;
		}
		++index;
	}

	if (index == size) return *this;

	for (int i = index; i < size - 1; ++i) {
		(*this)[i] = (*this)[i + 1];
	}
	--size;
	return *this;
}

template <class T>
void Array<T>::clear() {
	for (int i = 0; i < size; ++i) {
		(*this)[i] = NULL;
	}
	size = 0;
}

#endif