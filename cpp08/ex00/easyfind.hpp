
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& con, int find);

#include "easyfind.tpp"

#endif

