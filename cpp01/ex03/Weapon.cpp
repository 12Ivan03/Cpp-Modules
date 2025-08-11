
#include "Weapon.hpp"

Weapon::Weapon(const std::string &initName) : type(initName) {};

Weapon::~Weapon() {};

const std::string   &Weapon::getType() const { 
    return type; 
};

void    Weapon::setType(const std::string &newName) {
    type = newName;
}