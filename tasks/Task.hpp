#ifndef TASK_HPP
#define TASK_HPP

#include <string>    // Add this line for string type
#include "Date.hpp" // Add this line for Date class

class Task{
    private:
        std::string taskName;
        std::string taskDef;
        Date taskDateCreated;
        Date taskDateDue;

    public:
        Task();
        Task(std::string taskName, std::string taskDef, Date taskDateCreated, Date taskDateDue);
        std::string toString() const;

        bool taskInsert(std::string fileName, std::string taskName, std::string taskDef, Date taskDateCreated = Date(), Date taskDateDue = Date());
        bool taskDelete(std::string fileName, std::string taskName);
        //bool taskModify(std::string fileName, std::string taskName, std::string taskDef, Date taskDateCreated = Date(), Date taskDateDue = Date());
};

#endif // TASK_HPP