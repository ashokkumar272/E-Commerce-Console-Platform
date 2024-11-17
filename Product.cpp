#include "Product.h"

// ElectronicsProduct
ElectronicsProduct::ElectronicsProduct(const string &name, double price, int warranty) 
    : name(name), price(price), warranty(warranty) {}
string ElectronicsProduct::getName() const { return name; }
double ElectronicsProduct::getPrice() const { return price; }
void ElectronicsProduct::display() const { 
    cout << " " << name << ": $" << price << " || Warranty: " << warranty << " years" << endl; 
}

// ClothingProduct
ClothingProduct::ClothingProduct(const string &name, double price) 
    : name(name), price(price) {}
string ClothingProduct::getName() const { return name; }
double ClothingProduct::getPrice() const { return price; }
void ClothingProduct::display() const { 
    cout << " " << name << ": $" << price << " (Clothing)" << endl; 
}

// BookProduct
BookProduct::BookProduct(const string &name, double price, const string &publication) 
    : name(name), price(price), publication(publication) {}
string BookProduct::getName() const { return name; }
double BookProduct::getPrice() const { return price; }
void BookProduct::display() const { 
    cout << " " << name << ": $" << price << " || Publication: " << publication << endl; 
}

// HomeApplianceProduct
HomeApplianceProduct::HomeApplianceProduct(const string &name, double price, int warranty) 
    : name(name), price(price), warranty(warranty) {}
string HomeApplianceProduct::getName() const { return name; }
double HomeApplianceProduct::getPrice() const { return price; }
void HomeApplianceProduct::display() const { 
    cout << " " << name << ": $" << price << " || Warranty: " << warranty << " Years" << endl; 
}

// SportsProduct
SportsProduct::SportsProduct(const string &name, double price, const string &brand) 
    : name(name), price(price), brand(brand) {}
string SportsProduct::getName() const { return name; }
double SportsProduct::getPrice() const { return price; }
void SportsProduct::display() const { 
    cout << " " << name << ": $" << price << " || Brand: " << brand << endl; 
}

// BeautyProduct
BeautyProduct::BeautyProduct(const string &name, double price, const string &brand) 
    : name(name), price(price), brand(brand) {}
string BeautyProduct::getName() const { return name; }
double BeautyProduct::getPrice() const { return price; }
void BeautyProduct::display() const { 
    cout << " " << name << ": $" << price << " || Brand: " << brand << endl; 
}

// ToyProduct
ToyProduct::ToyProduct(const string &name, double price, int recommendedAge) 
    : name(name), price(price), recommendedAge(recommendedAge) {}
string ToyProduct::getName() const { return name; }
double ToyProduct::getPrice() const { return price; }
void ToyProduct::display() const { 
    cout << " " << name << ": $" << price << " || Recommended Age: " << recommendedAge << "+ years" << endl; 
}
