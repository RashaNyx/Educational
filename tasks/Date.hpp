#ifndef DATE_HPP
#define DATE_HPP
#include <string>
class Date {
private:
    int year;
    int month;
    int day;

public:
    // Constructeurs
    Date();
    Date(int d, int m, int y);

    // Méthodes
    Date& addDays(int daysToAdd);
    void DisplayDate() const;
    std::string toString() const;

private:
    // Méthode utilitaire pour obtenir le nombre de jours dans un mois donné
    int getDaysInMonth(int year, int month);
};

#endif // DATE_HPP
