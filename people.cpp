#include "people.h"

Person::Person() : name(""), totalSpent(0.0) {} //Default constructor for Person
 
Person::Person(const std::string& name) : name(name), totalSpent(0.0) {} //Parameterized constructor

void Person::addItem(const Item& item) { //Adds an item to the person's purchase list and updates the total amount spent
    items.push_back(item);
    totalSpent += item.getPrice();
}

std::string Person::getName() const { //Returns the name of the person
    return name;
}

double Person::getTotalSpent() const { //Returns the total amount spent by the person
    return totalSpent;
}

const std::vector<Item> Person::getItems() const {//Returns the vector of items purchased by the person
    return items;
}