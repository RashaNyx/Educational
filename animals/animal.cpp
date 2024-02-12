#include "animal.hpp"

Animal::Animal(std::string name) : m_name(name) 
{
    std::cout<<"Animal constructor" << std::endl;
}

Animal::~Animal() 
{
    std::cout<<"Animal destructor" << std::endl;

}

std::string Animal::getName()
{
    return this->m_name;
} 

