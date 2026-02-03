
#include "Serializer.hpp"

// OCF
Serializer::Serializer() {};

Serializer::Serializer(const Serializer &other) {};

Serializer& Serializer::operator=(const Serializer &other) {
	return (*this);
};

Serializer::~Serializer() {};

// Functions
uintptr_t Serializer::serialize(Data* ptr) {

	std::uintptr_t res;

	res = reinterpret_cast<std::uintptr_t>(ptr);
	return (res);
};

Data* Serializer::deserialize(uintptr_t raw) {

	Data *res;

	res = reinterpret_cast<Data*>(raw);
	return (res);
};

// uintptr_t is a number type that can hold every
// bit of a pointer so you can get the exact same pointer back later.