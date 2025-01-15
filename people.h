#ifndef PERSON_H
#define PERSON_H

#include "items.h"
#include <string>
#include <vector>

class Person {
private:
    std::string name; //Name of the person
    std::vector<Item> items; //List of items purchased
    double totalSpent; //Total amount spent by the person

public:
    Person();
    Person(const std::string& name);

    void addItem(const Item& item);
    std::string getName() const;
    double getTotalSpent() const;
     const std::vector<Item> getItems() const;
};

#endif