#ifndef CART_TPP
#define CART_TPP

#include "Cart.h"
#include <memory>
#include <iostream>
using namespace std;

// Add an item to the cart
template <typename T>
void Cart<T>::addItem(T* item) {
    items.emplace_back(unique_ptr<T>(item)); // Wrap raw pointer in unique_ptr
}

// Display all items in the cart
template <typename T>
void Cart<T>::viewCart() const {
    if (items.empty()) {
        cout << "\033[31mYour cart is empty.\033[0m\n"; // Red text
        return;
    }

    for (const auto& item : items) { // Access each item using unique_ptr
        item->display();            // Safely call display() on each item
    }
}

// Clear the cart (automatically deletes all items)
template <typename T>
void Cart<T>::clear() {
    items.clear(); // unique_ptr automatically deletes all managed objects
}

// Check if the cart is empty
template <typename T>
bool Cart<T>::isEmpty() const {
    return items.empty();
}

// Return const reference to the items
template <typename T>
const vector<unique_ptr<T>>& Cart<T>::getItems() const {
    return items;
}

#endif
