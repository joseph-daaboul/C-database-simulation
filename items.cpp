#include "items.h"

Item::Item() : name(""), price(0.0) {} //Default constructor for Item

Item::Item(const std::string& name, double price) : name(name), price(price) {} //Parameterized constructor for Item

std::string Item::getName() const { //Returns the name of the item
    return name;
}

double Item::getPrice() const { //Returns the price of the item
    return price;
}