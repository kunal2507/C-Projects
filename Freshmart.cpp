
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Item {
    string name;
    double price;
};

void displayWelcomeMessage() {
    cout << "Welcome to FreshMart - Your Grocery Store!\n";
}

void displayLogo() {
    cout << "---------------------------\n";
    cout << "      FRESHMART STORE      \n";
    cout << "---------------------------\n";
}

void displayOptions() {
    cout << "\nOptions:\n";
    cout << "1. Add items to cart\n";
    cout << "2. View cart\n";
    cout << "3. See prices of items in the store\n";
    cout << "4. Checkout\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void displayCategories(const map<int, vector<Item>>& categories) {
    cout << "\nCategories:\n";
    for (const auto& category : categories) {
        cout << category.first << ". ";
        switch (category.first) {
            case 1:
                cout << "Clothes\n";
                break;
            case 2:
                cout << "Food\n";
                break;
            case 3:
                cout << "Essentials\n";
                break;
            case 4:
                cout << "Accessories\n";
                break;
            default:
                break;
        }
    }
}

int main() {
    map<int, vector<Item>> categories = {
        {1, {{"T-shirt", 15.99}, {"Jeans", 29.99}, {"Dress", 39.99}, {"Sweater", 25.99}}},
        {2, {{"Apples", 2.49}, {"Bread", 1.99}, {"Milk", 3.49}, {"Chicken", 5.99}}},
        {3, {{"Soap", 4.99}, {"Toothpaste", 2.99}, {"Shampoo", 6.49}, {"Tissue", 3.99}}},
        {4, {{"Watch", 49.99}, {"Sunglasses", 19.99}, {"Earrings", 9.99}, {"Hat", 12.99}}}
    };

    vector<Item> cart;
    double total = 0.0;

    displayWelcomeMessage();
    displayLogo();

    while (true) {
        displayOptions();
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            displayCategories(categories);
            cout << "Enter category number to view items (0 to go back): ";
            int catChoice;
            cin >> catChoice;

            if (catChoice == 0) {
                continue;
            }

            if (categories.find(catChoice) != categories.end()) {
                cout << "Items in category " << catChoice << ":\n";
                for (size_t i = 0; i < categories[catChoice].size(); ++i) {
                    cout << i + 1 << ". " << categories[catChoice][i].name << " - $" << categories[catChoice][i].price << endl;
                }

                cout << "Enter item number to add to cart (0 to go back): ";
                int itemChoice;
                cin >> itemChoice;

                if (itemChoice == 0) {
                    continue;
                }

                Item selected = categories[catChoice][itemChoice - 1];
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;

                selected.price *= quantity;
                selected.name += " (x" + to_string(quantity) + ")";

                cart.push_back(selected);
                total += selected.price;

                cout << selected.name << " added to cart. Current total: $" << total << endl;
            } else {
                cout << "Invalid category. Please enter a valid category number.\n";
            }
        } else if (choice == 2) {
            cout << "Items in your cart:\n";
            for (const auto& item : cart) {
                cout << item.name << " - $" << item.price << endl;
            }
            cout << "Total price: $" << total << endl;
        } else if (choice == 3) {
            cout << "Prices of items in the store:\n";
            for (const auto& category : categories) {
                cout << "Category " << category.first << ":\n";
                for (const auto& item : category.second) {
                    cout << item.name << " - $" << item.price << endl;
                }
            }
        } else if (choice == 4) {
            cout << "Items in your cart:\n";
            for (const auto& item : cart) {
                cout << item.name << " - $" << item.price << endl;
            }
            cout << "Total price: $" << total << endl;

            cout << "Thank you for shopping with us at FreshMart! Have a great day!\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
