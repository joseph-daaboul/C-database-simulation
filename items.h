#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
private:
    std::string name; //Name of the item
    double price; //Price of the item

public:
    Item();
    Item(const std::string& name, double price);
    std::string getName() const;
    double getPrice() const;
};

#endif