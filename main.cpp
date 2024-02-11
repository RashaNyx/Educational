#include <iostream>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>
#include <algorithm> // Add this line to include the algorithm header


int main()
{
    std::ifstream inputFile("inputFile.txt");
    std::string line;
    std::unordered_map<std::string,int> userActions;
    std::pair<std::string,int> best("",0);
    if(inputFile.is_open() != true)
    {
        std::cerr << "Impossible d'ouvrir le fichier " << std::endl;
        return 1;
    }


    while(std::getline(inputFile, line))
    {
        int pos1 = line.find(',');
        int pos2 = line.find(',', pos1+1);
        std::string action = line.substr(pos1+1, pos2-pos1-1);

        userActions[action]++;
    }

    
    for(const auto &entry : userActions)
    {

        if(entry.second > best.second)
        {
            best = entry;
        }
        
    }

    std::cout << "Most frequent action: " << best.first << ", count: " << best.second << std::endl;

    return 0;   
/*
    std::map<std::string, int>::iterator best = std::max_element(userActions.begin(), userActions.end(), [] (const std::pair<std::string,int>& a, const std::pair<std::string,int>& b)->bool{ return a.second < b.second; } );
    std::cout << best->first << " , " << best->second << "\n";
*/
}

