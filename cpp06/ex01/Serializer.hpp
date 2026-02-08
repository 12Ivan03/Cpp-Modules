
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {

	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif

// a bit random questions out side of what we have talked so far? #ifndef SERIALIZER_HPP #define SERIALIZER_HPP #include <iostream> #include <cstdint> #include "Data.hpp" class Serializer { private: Serializer(); Serializer(const Serializer &other); Serializer& operator=(const Serializer &other); ~Serializer(); public: static uintptr_t serialize(Data* ptr); static Data* deserialize(uintptr_t raw); }; #endif I understand that the private initializers of a class are private so that no one can initialize it like Serializer s; But when we call Serializer::serialize(p); is the class constructed somewhere into an object ? where what is his status ect ? can you through more light on this subject please :)