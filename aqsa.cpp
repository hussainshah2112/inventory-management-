#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    vector<Item> items;
    int nextId = 1;

public:
    void addItem() {
        Item item;
        item.id = nextId++;
        cout << "Enter item name: ";
        cin >> item.name;
        cout << "Enter quantity: ";
        cin >> item.quantity;
        cout << "Enter price: ";
        cin >> item.price;
        items.push_back(item);
        cout << "Item added successfully!\n";
    }

    void viewItems() {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\nInventory Items:\n";
        for (const auto& item : items) {
            cout << "ID: " << item.id
                 << ", Name: " << item.name
                 << ", Quantity: " << item.quantity
                 << ", Price: $" << item.price << '\n';
        }
    }

    void updateItem() {
        int id;
        cout << "Enter item ID to update: ";
        cin >> id;

        for (auto& item : items) {
            if (item.id == id) {
                cout << "Enter new name: ";
                cin >> item.name;
                cout << "Enter new quantity: ";
                cin >> item.quantity;
                cout << "Enter new price: ";
                cin >> item.price;
                cout << "Item updated successfully!\n";
                return;
            }
        }

        cout << "Item not found.\n";
    }

    void deleteItem() {
        int id;
        cout << "Enter item ID to delete: ";
        cin >> id;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->id == id) {
                items.erase(it);
                cout << "Item deleted successfully!\n";
                return;
            }
        }

        cout << "Item not found.\n";
    }
};

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Update Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.viewItems();
                break;
            case 3:
                inventory.updateItem();
                break;
            case 4:
                inventory.deleteItem();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
