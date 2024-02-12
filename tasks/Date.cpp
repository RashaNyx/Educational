#include <iostream>
#include <sstream>
#include "Date.hpp"

Date::Date() : year(0), month(0), day(0) {}
Date::Date(int d, int m, int y) : year(y), month(m), day(d) {
    // Vérifier si l'année est valide (non négative)
    if (year < 0) {
        std::cerr << "Erreur : Année invalide" << std::endl;
        year = 0; // Remettre l'année à une valeur par défaut
    }

    // Vérifier si le mois est valide (entre 1 et 12)
    if (month < 1 || month > 12) {
        std::cerr << "Erreur : Mois invalide" << std::endl;
        month = 1; // Remettre le mois à une valeur par défaut
    }

    // Vérifier si le jour est valide en fonction du mois et de l'année
    int maxDaysInMonth = getDaysInMonth(year, month);
    if (day < 1 || day > maxDaysInMonth) {
        std::cerr << "Erreur : Jour invalide" << std::endl;
        day = 1; // Remettre le jour à une valeur par défaut
    }
}
void Date::DisplayDate() const
{
    std::cout << year << "Y" << std::endl;
    std::cout << month << "M" << std::endl;
    std::cout << day << "D" << std::endl;

}

// Méthode utilitaire pour obtenir le nombre de jours dans un mois donné
int Date::getDaysInMonth(int year, int month)
{
    switch (month)
    {
    case 2:                                                        // Février
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // Année bissextile
            return 29;
        else
            return 28;
    case 4:
    case 6:
    case 9:
    case 11: // Avril, Juin, Septembre, Novembre
        return 30;
    default: // Janvier, Mars, Mai, Juillet, Août, Octobre, Décembre
        return 31;
    }
}

Date& Date::addDays(int daysToAdd) {
    int totalDays = day + daysToAdd;

    // Ajouter les jours supplémentaires au jour actuel
    while (totalDays > getDaysInMonth(year, month))
    {
        totalDays -= getDaysInMonth(year, month);
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    // Mettre à jour la date résultante
    day = totalDays;
    
    return *this; // Return the modified date object
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << day << "-" << month << "-" << year ;
    return oss.str();
}
