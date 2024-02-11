#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("output.txt"); // Ouverture du fichier en mode écriture
    if (outputFile.is_open()) {
        outputFile << "Hello, world!" << std::endl; // Écriture dans le fichier
        outputFile.close(); // Fermeture du fichier
    }

    std::ifstream inputFile("input.txt"); // Ouverture du fichier en mode lecture
    std::string line;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Affichage du contenu du fichier ligne par ligne
        }
        inputFile.close(); // Fermeture du fichier
    }

    return 0;
}
