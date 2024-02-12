#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

//une fonction pour mettre le fichier dans un stream
//une fonction pour récupérer la string comprise entre ',' et ','
//dans le main : on crée une AT<string,number>, on lit chaque ligne du fichier, on récupère la string et on incrémente la valeur dans l'AT 

std::ifstream openFile(std::string fileName)
{
    std::ifstream file(fileName);
    if(file.is_open() == false)
    {
        std::cerr << "impossible d'ouvrir le fichier" << std::endl;
        throw std::runtime_error("impossible d'ouvrir le fichier");
    }
    return file;
}


void closeFile(std::ifstream &file)
{
    file.close();
}

std::string getStringBetweenCharacters(const std::string &text, char c)
{
    int commaPos = text.find(c);
    if(commaPos == std::string::npos)
    {
        std::cerr << "Pas de délimiteur '" << c << "' dans le texte" << std::endl;
        std::exit(EXIT_FAILURE); // Arrêter le programme en indiquant une erreur
        return "";
    }

    int left = commaPos;
    int right = text.find(c, left+1);
    if(right == std::string::npos)
    {
        std::cerr << "Seul un délimiteur '" << c << "' a été trouvé dans le texte" << std::endl;
        std::exit(EXIT_FAILURE); // Arrêter le programme en indiquant une erreur
        return ""; // Retourner une chaîne vide si le deuxième délimiteur n'est pas trouvé
    }

    return text.substr(left+1, right-left-1);
}

int main()
{
    std::ifstream file = openFile("logs.txt");
    std::string line;
    std::string action;
    std::unordered_map<std::string, int> occurences;
    std::pair<std::string, int> best("", 0);
    while(std::getline(file, line))
    {
        //std::cout << "lecture de la ligne : \n" << line << std::endl;
        action = getStringBetweenCharacters(line, ',');
        occurences[action]++;
    }
    
    closeFile(file);

    for(auto &entry : occurences)
    {
        if(best.second < entry.second)
        {
            best = entry;
        }
    }

    std::cout << best.first << " : " << best.second << std::endl;
    return 0;
}