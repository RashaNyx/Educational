#include <iostream>
#include <unordered_map>
#include <fstream>

char repeatFirstUnrepeatedChar(std::istream& myStream)
{
    char caractere;
    std::unordered_map<char, int> occurences;
    while(myStream >> caractere)
    {
        occurences[caractere]++;
    }

    myStream.clear();
    myStream.seekg(0);

    while(myStream >> caractere)
    {
        if(occurences[caractere] == 1)
        {
            return caractere;
        }
    }
    return '0';
}

int main()
{
    std::ifstream fichier("./flux.txt");
    if(!fichier.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier ! " << std::endl;
        return 1;
    }

    char resultat = repeatFirstUnrepeatedChar(fichier);

    if(resultat != '0')
    {
        std::cout<<"Le premier caractere non repete est : " << resultat << std::endl;
    }
    else
    {
        std::cout<<"aucun caractere non repete dans le fichier" << std::endl;
    }

    fichier.close();
    return 0;
}