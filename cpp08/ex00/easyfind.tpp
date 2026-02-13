
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& con, int find) {
	
	typename T::iterator it;

	it = std::find(con.begin(), con.end(), find);

	if (it == con.end())
		throw std::runtime_error("Value not found");
	
	return (it);
};
