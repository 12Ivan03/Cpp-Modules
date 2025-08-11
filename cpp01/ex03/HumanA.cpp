
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), weapon(weapon) {};

HumanA::~HumanA() {};

void    HumanA::attack() {
    std::cout << _name << " attacks with " << weapon.getType() << std::endl;
}
