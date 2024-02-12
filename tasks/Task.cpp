//#include <string>
#include <fstream> // Pour la manipulation des fichiers
#include <iostream>
#include <sstream> // Pour la manipulation des chaînes de caractères

#include "Task.hpp"

Task::Task() : taskName("0"), taskDef("0"), taskDateCreated(Date()), taskDateDue(Date()) {}

Task::Task(std::string taskName, std::string taskDef, Date taskDateCreated, Date taskDateDue) : taskName(taskName), taskDef(taskDef), taskDateCreated(taskDateCreated), taskDateDue(taskDateDue)
{

}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Task.hpp"

bool Task::taskInsert(std::string fileName, std::string taskName, std::string taskDef, Date taskDateCreated, Date taskDateDue)
{
    std::ifstream inFile(fileName);
    std::ofstream outFile("temp.txt");
    std::string line;

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return false;
    }

    bool taskFound = false;

    while (std::getline(inFile, line)) {
        //istringstream est une classe de flux qui permet de lire les données a partir d'une chaine de caracètres.
        std::istringstream iss(line);
        std::string currentTaskName;
        //extrait une partie de la chaine de caractère à partir du flux iss, elle extrait les caractères du flux iss jusqu'à ce qu'elle rencontre le délimiteur ',' et stocke le resultat dans currentTaskName
        std::getline(iss, currentTaskName, ',');

        if (currentTaskName == taskName) {
            outFile << taskName << "," << taskDef << "," << taskDateCreated.toString() << "," << taskDateDue.toString() << std::endl;
            taskFound = true;
        } else {
            outFile << line << std::endl;
        }
    }

    if (!taskFound) {
        outFile << taskName << "," << taskDef << "," << taskDateCreated.toString() << "," << taskDateDue.toString() << std::endl;
    }

    inFile.close();
    outFile.close();

    std::remove(fileName.c_str());
    std::rename("temp.txt", fileName.c_str());

    return true;
}

std::string Task::toString() const {
    std::ostringstream oss;
    oss << taskName << "," << taskDef << "," << taskDateCreated.toString() << "," << taskDateDue.toString();
    return oss.str();
}
