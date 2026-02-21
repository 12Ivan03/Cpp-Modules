
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

    try
    {

        PmergeMe pm(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    return (0);
}