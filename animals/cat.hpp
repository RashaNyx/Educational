#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat : public Animal
{
    public : 
    Cat(std::string name);
    void makeSound() override;
    ~Cat(); // Définir le destructeur de Cat

};

#endif //CAT_HPP