
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

// n | ≤ F(n) 
// ---|----- 
// 1 | 0 
// 2 | 1 
// 3 | 3 
// 4 | 5 
// 5 | 7 
// 6 | 10 
// 7 | 13 
// 8 | 16 
// 9 | 19 
// 10 | 22 
// 11 | 26 
// 12 | 29 
// 13 | 34 
// 14 | 38 
// 15 | 42 
// 16 | 46 
// 17 | 50 
// 18 | 53 
// 19 | 57 
// 20 | 62 
// 21 | 66