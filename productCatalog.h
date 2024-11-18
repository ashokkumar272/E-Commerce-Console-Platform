#ifndef PRODUCT_CATALOG_H
#define PRODUCT_CATALOG_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Product.h"

extern std::unordered_map<std::string, std::vector<Product*>> productCatalog;

#endif