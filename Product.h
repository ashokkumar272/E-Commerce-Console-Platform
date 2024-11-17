#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

// Base class for all products
class Product {
public:
    virtual ~Product() = default;
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual void display() const = 0;
};

// Electronics Product
class ElectronicsProduct : public Product {
    string name;
    double price;
    int warranty;

public:
    ElectronicsProduct(const string &name, double price, int warranty);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Clothing Product
class ClothingProduct : public Product {
    string name;
    double price;

public:
    ClothingProduct(const string &name, double price);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Book Product
class BookProduct : public Product {
    string name, publication;
    double price;

public:
    BookProduct(const string &name, double price, const string &publication);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Home Appliance Product
class HomeApplianceProduct : public Product {
    string name;
    double price;
    int warranty;

public:
    HomeApplianceProduct(const string &name, double price, int warranty);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Sports Product
class SportsProduct : public Product {
    string name, brand;
    double price;

public:
    SportsProduct(const string &name, double price, const string &brand);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Beauty Product
class BeautyProduct : public Product {
    string name, brand;
    double price;

public:
    BeautyProduct(const string &name, double price, const string &brand);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

// Toy Product
class ToyProduct : public Product {
    string name;
    double price;
    int recommendedAge;

public:
    ToyProduct(const string &name, double price, int recommendedAge);
    string getName() const override;
    double getPrice() const override;
    void display() const override;
};

#endif

