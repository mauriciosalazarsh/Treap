//
// Created by mauri on 25/10/2024.
//

#include "TreapManager.h"
#include <iostream>

#include "TreapManager.h"
#include <iostream>

void TreapManager::run() {
    Treap treap;
    int choice;

    while (true) {
        std::cout << "\nTreap Operations:\n";
        std::cout << "1. Insert\n2. Delete\n3. Search\n4. Display Inorder List\n5. Clear Tree\n6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                treap.insert(key);
                break;
            }
            case 2: {
                int key;
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                treap.deleteNode(key);
                break;
            }
            case 3: {
                int key;
                std::cout << "Enter key to search: ";
                std::cin >> key;
                std::cout << (treap.search(key) ? "Found\n" : "Not Found\n");
                break;
            }
            case 4: {
                std::vector<std::pair<int, double>> inorderList = treap.getInorderList();
                std::cout << "Inorder List (Key, Priority): ";
                for (const auto& [key, priority] : inorderList) {
                    std::cout << "(" << key << ", " << priority << ") ";
                }
                std::cout << "\n";
                break;
            }
            case 5:
                treap.clear();
                std::cout << "The tree has been cleared.\n";
                break;
            case 6:
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

