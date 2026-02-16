
#include "easyfind.hpp"

// Contianers define thier own iterator type (Iterators are just objects that act like pointers)
// STL algorithms work with iterators, not containers

template <typename T>
typename T::iterator easyfind(T& con, int find) {
	
	typename T::iterator it;

	it = std::find(con.begin(), con.end(), find);

	if (it == con.end())
		throw std::runtime_error("Value not found");
	
	return (it);
};
