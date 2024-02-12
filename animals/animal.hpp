#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
class Animal
{
    public:
        Animal(std::string name);
        virtual void makeSound() = 0;
        std::string getName();
        virtual ~Animal();
    protected:
        std::string m_name;
};

#endif //ANIMAL_HPP  