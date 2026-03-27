
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

    try
    {
        PmergeMe pm(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return (1);
    }
    
    return (0);
}

// for i in {1..100}; do
//      shuf -i 1-100 -n 20 | tr '\n' ' ' | xargs ./PmergeMe
// done