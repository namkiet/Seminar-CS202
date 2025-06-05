#pragma once
#include "Product.h"
#include <vector>

class ClothesCollection
{
public:
    ClothesCollection()
    {
        products.push_back(Product("T-Shirt", 300000));
        products.push_back(Product("Jeans", 400000));
        products.push_back(Product("Jacket", 200000));
    }

    const std::vector<Product>& getAllProducts() const
    {
        return products;
    }

private:
    std::vector<Product> products;
};