#include "Date.hpp"
#include "Task.hpp"



int main() 
{
    Task newTask;

    Date newDate(1, 1, 2024);
    Date dueDate(20,1,2024);
    newTask.taskInsert("taches.txt", "laver garage", "laver salle de bain et cuisine 2",newDate, dueDate);

    return 0;
}
