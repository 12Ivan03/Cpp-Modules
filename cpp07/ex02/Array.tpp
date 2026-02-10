
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {};

template <typename T>
Array<T>::Array(unsigned int lenArr) : _array(new T[lenArr]), _size(lenArr) {};

template <typename T>
Array<T>::Array(const Array &other) {

	this->_size = other._size;
	this->_array = new T[this->_size];

	for (unsigned int i = 0; i < this->_size; i++) {
		this->_array[i] = other._array[i];
	}

};

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {


	if (this != &other) {

		T* tmp = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++) {
			tmp[i] = other._array[i];
		}

		delete[] this->_array;
		this->_array = tmp;
		this->_size = other._size;
	}
	return *this;
};

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
};

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	
	if (idx >= this->_size)
		throw std::exception();
	return this->_array[idx];
};

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {

	if (idx >= this->_size)
		throw std::exception();
	return this->_array[idx];
};