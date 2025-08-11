
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(nullptr) {};

HumanB::~HumanB() {};

void    HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
};

void    HumanB::attack() {
    if (_weapon != NULL)
        std::cout << _name << " attaks with " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " not weapon available " << std::endl;
};
