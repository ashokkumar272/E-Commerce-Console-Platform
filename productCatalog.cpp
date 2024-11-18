#include <unordered_map>
#include <vector>
#include <string>
#include "Product.h"
using namespace std;

// Define the productCatalog here
unordered_map<string, vector<Product*>> productCatalog = {
    {"Electronics", {
        new ElectronicsProduct("Laptop", 899.99, 5),
        new ElectronicsProduct("Smartphone", 499.99, 3),
        new ElectronicsProduct("Headphones", 149.99, 4),
        new ElectronicsProduct("Smartwatch", 199.99, 2),
        new ElectronicsProduct("Tablet", 299.99, 3),
        new ElectronicsProduct("Camera", 599.99, 2),
        new ElectronicsProduct("Gaming Console", 399.99, 3),
        new ElectronicsProduct("Bluetooth Speaker", 99.99, 1),
        new ElectronicsProduct("Monitor", 199.99, 2),
        new ElectronicsProduct("External Hard Drive", 89.99, 1)
    }},
    {"Clothing", {
        new ClothingProduct("T-shirt", 19.99),
        new ClothingProduct("Jeans", 49.99),
        new ClothingProduct("Jacket", 89.99),
        new ClothingProduct("Sweater", 39.99),
        new ClothingProduct("Formal Shirt", 29.99),
        new ClothingProduct("Chinos", 44.99),
        new ClothingProduct("Skirt", 34.99),
        new ClothingProduct("Dress", 59.99),
        new ClothingProduct("Shorts", 24.99),
        new ClothingProduct("Hoodie", 54.99)
    }},
    {"Books", {
        new BookProduct("C++ Guide", 29.99, "MIT Press"),
        new BookProduct("Design Patterns", 39.99, "Springer Nature"),
        new BookProduct("Data Structures", 34.99, "ORO Editions"),
        new BookProduct("Introduction to Algorithms", 49.99, "MIT Press"),
        new BookProduct("Clean Code", 44.99, "Prentice Hall"),
        new BookProduct("The Pragmatic Programmer", 29.99, "Addison-Wesley"),
        new BookProduct("Effective C++", 34.99, "Pearson"),
        new BookProduct("Java Concurrency in Practice", 39.99, "Addison-Wesley"),
        new BookProduct("Head First Design Patterns", 39.99, "O'Reilly Media"),
        new BookProduct("Python for Data Analysis", 49.99, "O'Reilly Media")
    }},
    {"Home Appliances", {
        new HomeApplianceProduct("Microwave Oven", 119.99, 2),
        new HomeApplianceProduct("Refrigerator", 899.99, 5),
        new HomeApplianceProduct("Washing Machine", 499.99, 4),
        new HomeApplianceProduct("Air Conditioner", 799.99, 5),
        new HomeApplianceProduct("Vacuum Cleaner", 149.99, 3),
        new HomeApplianceProduct("Electric Kettle", 49.99, 1),
        new HomeApplianceProduct("Blender", 79.99, 2),
        new HomeApplianceProduct("Toaster", 39.99, 1),
        new HomeApplianceProduct("Dishwasher", 699.99, 5),
        new HomeApplianceProduct("Coffee Maker", 99.99, 2)
    }},
    {"Sports Equipment", {
        new SportsProduct("Basketball", 29.99, "Wilson"),
        new SportsProduct("Football", 24.99, "Nike"),
        new SportsProduct("Tennis Racket", 149.99, "Babolat"),
        new SportsProduct("Cricket Bat", 199.99, "Kookaburra"),
        new SportsProduct("Hiking Backpack", 79.99, "Osprey"),
        new SportsProduct("Yoga Mat", 19.99, "Manduka"),
        new SportsProduct("Dumbbell Set", 49.99, "Bowflex"),
        new SportsProduct("Cycling Helmet", 59.99, "Giro"),
        new SportsProduct("Running Shoes", 89.99, "Adidas"),
        new SportsProduct("Fishing Rod", 109.99, "Shimano")
    }},
    {"Beauty and Personal Care", {
        new BeautyProduct("Shampoo", 9.99, "Pantene"),
        new BeautyProduct("Conditioner", 8.99, "L'Oreal"),
        new BeautyProduct("Face Wash", 6.99, "Neutrogena"),
        new BeautyProduct("Body Lotion", 12.99, "Nivea"),
        new BeautyProduct("Hair Dryer", 29.99, "Philips"),
        new BeautyProduct("Makeup Kit", 49.99, "Maybelline"),
        new BeautyProduct("Perfume", 59.99, "Chanel"),
        new BeautyProduct("Electric Razor", 39.99, "Philips"),
        new BeautyProduct("Nail Polish Set", 14.99, "OPI"),
        new BeautyProduct("Lip Balm", 4.99, "Burt's Bees")
    }},
    {"Toys", {
        new ToyProduct("Lego Set", 49.99, 8),
        new ToyProduct("Action Figure", 19.99, 5),
        new ToyProduct("Puzzle", 14.99, 3),
        new ToyProduct("Board Game", 29.99, 4),
        new ToyProduct("Remote Control Car", 39.99, 7),
        new ToyProduct("Dollhouse", 59.99, 5),
        new ToyProduct("Stuffed Animal", 14.99, 3),
        new ToyProduct("Building Blocks", 24.99, 2),
        new ToyProduct("Train Set", 69.99, 8),
        new ToyProduct("Science Kit", 34.99, 10)
    }}
};
