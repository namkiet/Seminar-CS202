#pragma once
#include "Product.h"
#include <string>
#include <unordered_map>

class ElectronicsCollection
{
public:
    ElectronicsCollection()
    {
        products["smartphone"]  = Product("Galaxy S21", 20000000);
        products["laptop"]      = Product("MacBook Pro", 30000000);
    }

    const std::unordered_map<std::string, Product>& getAllProducts() const
    {
        return products;
    }

private:
    std::unordered_map<std::string, Product> products;
};