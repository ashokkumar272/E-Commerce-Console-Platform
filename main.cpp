#include <iostream>
#include<algorithm>
#include<sstream>
#include<fstream>
#include <iomanip>
#include "Product.h"
#include "Cart.h"
#include "User.h"
#include "productCatalog.h"
#include<string>

using namespace std;

//Colors
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string BLUE = "\033[34m";
const std::string REDDISH_PINK = "\033[38;2;255;102;153m";
const std::string REDDISH_ORANGE = "\033[38;2;255;69;0m";
const std::string RESET = "\033[0m";


unordered_map<string, vector<string>> userPurchaseHistory;


// Function declarations
void browseProducts(Cart<Product>& cart);
void viewCart(const Cart<Product>& cart);
void placeOrder(const Cart<Product>& cart, const string& userid);
void viewOrders(const string& userid);
void loadOrderHistory(const string& filename);
void getProductRecommendations(const string& userid);

int main() {
    UserManager userManager("users.txt");
    Cart<Product> cart;

    loadOrderHistory("orders.txt");

    string currentUserId;
    int choice;

    cout << REDDISH_ORANGE << "\n*** Welcome to the E-Commerce Platform! ***\n" << RESET;

    while (true) {
        cout << "\n1. Sign Up\n2. Login\n3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string userid, password;
            cout << "Enter username: ";
            cin >> userid;
            cout << "Enter password: ";
            cin >> password;

            if (userManager.signUp(userid, password)) {
                userManager.saveUsersToFile("users.txt");
            }
        } else if (choice == 2) {
            string userid, password;
            cout << "Enter username: ";
            cin >> userid;
            cout << "Enter password: ";
            cin >> password;

            if (userManager.login(userid, password)) {
                currentUserId = userid;
                break; // Proceed to main menu
            }
        } else if (choice == 3) {
            cout << REDDISH_PINK << "\nEagerly Waiting to Welcome You In On Our Platform!\n" << RESET << endl;
            return 0;
        } else {
            cout<< RED << "\nInvalid choice. Please try again.\n"<<RESET;
        }
    }

    // Main menu after successful login
    while (true) {
        cout << "\n===== Main Menu =====\n"<<endl;
        cout << "1. Browse Products\n";
        cout << "2. View Cart\n";
        cout << "3. Place Order\n";
        cout << "4. View Orders\n";
        cout << "5. Get Product Recommendations\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                browseProducts(cart);
                break;
            case 2:
                viewCart(cart);
                break;
            case 3:
                placeOrder(cart, currentUserId);
                break;
            case 4:
                viewOrders(currentUserId);
                break;
            case 5:
                getProductRecommendations(currentUserId);
                break;
            case 6:
                cout << REDDISH_PINK << "\nWish to Welcome You Again On Our Platform!\n" << RESET << endl;
                return 0;
            default:
                cout<< RED << "\nInvalid choice. Please try again.\n"<<RESET;
        }
    }
    return 0;
}

void browseProducts(Cart<Product>& cart) {
    cout << "\nSelect a category:\n";
    for (const auto& category : productCatalog) {
        cout << "- " << category.first << endl;
        delete &category;
    }

    string category;
    cout << "Enter category name: ";
    cin.ignore();
    getline(cin, category);
    

    if (productCatalog.find(category) != productCatalog.end()) {
        cout << "\nProducts in " << category << ":\n";
        const auto& products = productCatalog[category];
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << ". ";
            products[i]->display();
            delete &products;
        }

        int choice;
        cout << BLUE << "\nEnter product number to add to cart or 0 to return: "<< RESET;
        cin >> choice;

        if (choice > 0 && choice <= products.size()) {
            cart.addItem(products[choice - 1]);
            cout << "\033[32mProduct added to cart.\033[0m\n"; // Green text
        } else if (choice != 0) {
            cout << "\033[31mInvalid choice.\033[0m\n"; // Red text
        }
    } else {
        cout << "\033[31mCategory not found.\033[0m\n"; // Red text
    }
}

void viewCart(const Cart<Product>& cart) {
    cout << BLUE << "\nYour Cart:\n"<<RESET;
    cart.viewCart();
}

void placeOrder(const Cart<Product>& cart, const string& userid) {
    if (cart.isEmpty()) {
        cout << "\033[31mYour cart is empty.\033[0m\n"; // Red text
        return;
    }

    cout << "\nOrder Summary:\n";
    cart.viewCart();

    char confirm;
    cout << "\nDo you want to place this order? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        ofstream file("orders.txt", ios::app);
        if (file.is_open()) {
            file << "User: " << userid << endl;
            for (const auto& item : cart.getItems()) {
                file << "- " << item->getName() << " $" << fixed << setprecision(2) << item->getPrice() << endl;
            }
            file << "-----\n";
            file.close();
            cout << "\033[32mOrder placed successfully!\033[0m\n"; // Green text
        } else {
            cout << "\033[31mError saving order.\033[0m\n"; // Red text
        }
    } else {
        cout << "\033[31mOrder cancelled.\033[0m\n"; // Red text
    }
}

void viewOrders(const string& userid) {
    ifstream file("orders.txt");
    if (file.is_open()) {
        string line;
        bool hasOrders = false;
        bool displayOrder = false;

        cout << BLUE << "\nYour Orders:\n"<<RESET;
        while (getline(file, line)) {
            if (line.find("User: " + userid) != string::npos) {
                hasOrders = true;
                displayOrder = true;
                continue; // Skip displaying the username
            }
            if (line == "-----") {
                displayOrder = false; // End of one user's order block
            }
            if (displayOrder) {
                cout << "  " << line << endl; // Display order details only
            }
        }

        if (!hasOrders) {
            cout << "\033[31mNo orders found.\033[0m\n"; // Red text
        }
        file.close();
    } else {
        cout << "\033[31mError reading orders file.\033[0m\n"; // Red text
    }
}

void getProductRecommendations(const string& userid) {
    cout << "\nPersonalized Recommendations:\n";

    if (userPurchaseHistory.find(userid) == userPurchaseHistory.end() || userPurchaseHistory[userid].empty()) {
        cout << "Here are some popular products:\n";
        for (const auto& category : productCatalog) {
            if (!category.second.empty()) {
                cout << "- " << category.second[0]->getName() << " from " << category.first << " category.\n";
            }
        }
        return;
    }

    // Analyze user's purchase history
    unordered_map<string, int> categoryFrequency;
    for (const string& productName : userPurchaseHistory[userid]) {
        for (const auto& category : productCatalog) {
            for (const auto& product : category.second) {
                if (product->getName() == productName) {
                    categoryFrequency[category.first]++;
                }
            }
        }
    }

    // Sort categories by frequency
    vector<pair<string, int>> sortedCategories(categoryFrequency.begin(), categoryFrequency.end());
    sort(sortedCategories.begin(), sortedCategories.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Descending order
    });

    // Recommend top products from frequently purchased categories
   for (const auto& categoryPair : sortedCategories) {
    const string& category = categoryPair.first; // Get the category name
    if (!productCatalog[category].empty()) {
        cout << "- " << productCatalog[category][0]->getName() 
             << " from " << category << " category.\n";
    }
}

}

void loadOrderHistory(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "\033[31mError opening order history file.\033[0m\n"; // Red text
        return;
    }

    string line, currentUser;
    while (getline(file, line)) {
        if (line.find("User: ") == 0) {
            // Extract the username
            currentUser = line.substr(6); // Skip "User: "
        } else if (line == "-----") {
            currentUser.clear(); // Reset user when the block ends
        } else if (!currentUser.empty() && line.find("- ") == 0) {
            // Extract product name
            size_t pos = line.find("$");
            string productName = line.substr(2, pos - 3); // Skip "- " and remove price part
            userPurchaseHistory[currentUser].push_back(productName);
        }
    }
    file.close();
}
