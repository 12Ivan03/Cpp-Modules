
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main() {

    Zombie* heapZombie = newZombie("Harper");
    heapZombie->announce();
    
    delete heapZombie;
    heapZombie = nullptr;

    randomChump("Siven");

    return 0;
}
