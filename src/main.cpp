

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "bptree.h"

int main() {
    // Open the database file
    BPTree db("database.bpt");
    
    // Read number of commands
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline
    
    // Process each command
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        
        if (command == "insert") {
            std::string key;
            int value;
            iss >> key >> value;
            db.insert(key, value);
        } else if (command == "delete") {
            std::string key;
            int value;
            iss >> key >> value;
            db.remove(key, value);
        } else if (command == "find") {
            std::string key;
            iss >> key;
            std::vector<int> values = db.search(key);
            
            if (values.empty()) {
                std::cout << "null" << std::endl;
            } else {
                for (size_t j = 0; j < values.size(); j++) {
                    if (j > 0) std::cout << " ";
                    std::cout << values[j];
                }
                std::cout << std::endl;
            }
        }
    }
    
    // Close the database
    db.close();
    
    return 0;
}


