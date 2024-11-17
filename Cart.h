#ifndef CART_H
#define CART_H

#include <vector>
#include <memory> // For smart pointers
#include <iostream>
using namespace std;

template <typename T>
class Cart {
    vector<unique_ptr<T>> items; // Use unique_ptr to manage ownership automatically

public:
    void addItem(T* item);              // Add raw pointer, ownership is transferred
    void viewCart() const;              // View cart contents
    void clear();                       // Clear all items
    bool isEmpty() const;               // Check if cart is empty
    const vector<unique_ptr<T>>& getItems() const; // Return const reference to items
};

#include "Cart.tpp" // Include template implementation
#endif
