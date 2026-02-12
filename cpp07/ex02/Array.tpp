
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {};

template <typename T>
Array<T>::Array(unsigned int lenArr) : _array(nullptr), _size(lenArr) {
	
	if (this->_size > 0) 
		this->_array = new T[lenArr];
};

template <typename T>
Array<T>::Array(const Array &other) : _array(nullptr), _size(other._size) {

	if (other._size > 0) {
		this->_array = new T[this->_size];
		
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_array[i] = other._array[i];
		}
	}
};

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {

	if (this != &other) {

		T* tmp = nullptr;
		if (other._size > 0) {
			tmp = new T[other._size];
			
			for (unsigned int i = 0; i < other._size; i++) {
				tmp[i] = other._array[i];
			}
		}	
		delete[] this->_array;
		this->_array = tmp;
		this->_size = other._size;
	}
	return (*this);
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

template <typename T>
unsigned int	Array<T>::size() const {

	return (this->_size);
};
