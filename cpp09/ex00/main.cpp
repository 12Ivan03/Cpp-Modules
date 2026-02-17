
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

    try
    {
        if (argc != 2)
            throw std::runtime_error("could not open file.");
        // the rest of the main program
        BitcoinExchange bce;
        bce.populateDatabase();
        bce.processInputFile(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    
    return (0);
}