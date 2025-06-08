#pragma once
#include "Product.h"

// Concrete Product
class Food : public Product 
{
public:
    Food(std::string name, double price) 
        : name(name), price(price) {}

    std::string getName() const override 
    { 
        return name; 
    }

    double getPrice() const override 
    { 
        return price; 
    }

    double getTax(const std::string& region) const override 
    {
        if (region == "USA" || region == "Canada") 
            return price * 0.10;    // 10% VAT
        if (region == "EU")
            return price * 0.05;    // 5% VAT
        return 0.0;
    }

private:
    std::string name;
    double price;
};