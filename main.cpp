#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include "items.h"
#include "people.h"

using namespace std;

// Function to trim leading and trailing whitespace from a string in case of accidents
string trim(const string& str) {
    auto start = str.begin();
    while (start != str.end() && isspace(*start)) {
        ++start;
    }

    auto end = str.end();
    do {
        --end;
    } while (distance(start, end) > 0 && isspace(*end));

    return string(start, end + 1);
}

int main() {
    // Input file names
    const string paymentsFileName = "payments.txt";
    const string peopleFileName = "people.txt";

    ifstream paymentsFile(paymentsFileName);
    ifstream peopleFile(peopleFileName);

    // Check if files opened successfully
    if (!paymentsFile.is_open()) {
        cerr << "Error: Unable to open payments.txt." << endl;
        return 1;
    }

    if (!peopleFile.is_open()) {
        cerr << "Error: Unable to open people.txt." << endl;
        return 1;
    }

    // Check if payments.txt is empty
    if (paymentsFile.peek() == EOF) {
        cerr << "Error: The payments.txt file is empty." << endl;
        return 1;
    }

    unordered_map<string, Person> peopleMap;
    string line;

    // Load people from people.txt
    while (getline(peopleFile, line)) {
        line = trim(line); // Trim whitespace from the line
        if (line.empty()) {
            cerr << "Error: people.txt contains an empty line." << endl;
            return 1;
        }
        peopleMap[line] = Person(line);  // Initialize Person
    }

    // Check if people.txt is empty
    if (peopleMap.empty()) {
        cerr << "Error: The people.txt file is empty." << endl;
        return 1;
    }

    // Process payments.txt to add items to the corresponding Person objects
    while (getline(paymentsFile, line)) {
        istringstream iss(line);
        string personName, itemName;
        double price;

        // Validate payment format
        if (!(iss >> personName >> itemName >> price)) {
            cerr << "Error: Invalid format in payments.txt - " << line << endl;
            return 1;
        }

        // Add the item to the corresponding Person if they exist in peopleMap
        if (peopleMap.find(personName) != peopleMap.end()) {
            peopleMap[personName].addItem(Item(itemName, price));
        }
    }

    paymentsFile.close();
    peopleFile.close();

    // Print the output statements
    for (const auto& entry : peopleMap) {
        const string& name = entry.first;
        const Person& person = entry.second;

        cout << person.getName() << endl;
        for (const auto& item : person.getItems()) {
            cout << item.getName() << " " << item.getPrice() << endl;
        }
        cout << "Total: " << person.getTotalSpent() << endl;
    }

    return 0;
}
