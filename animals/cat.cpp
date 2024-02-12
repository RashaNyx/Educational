#include "cat.hpp"

void Cat::makeSound()
{
    std::cout << "meow ! " << std::endl;
}

Cat::Cat(std::string name) : Animal(name){}

Cat::~Cat() {
    std::cout<< "bye bye, " << this->m_name << std::endl;
} // Définition du destructeur de Cat
