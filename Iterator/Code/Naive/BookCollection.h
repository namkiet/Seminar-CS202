#pragma once
#include "Product.h"
#include <stack>

class BookCollection
{
public:
    BookCollection()
    {
        products.push(Product("The Night Circus", 150000));
        products.push(Product("Never Let Me Go", 200000));
        products.push(Product("The Martian", 300000));
    }

    const std::stack<Product>& getAllProducts() const
    {
        return products;
    }

private:
    std::stack<Product> products;
};