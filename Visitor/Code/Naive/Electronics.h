#pragma once
#include "Product.h"

// Concrete Product
class Electronics : public Product 
{
public:
    Electronics(std::string name, double price) 
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
        if (region == "USA") 
            return price * 0.15;    // 15% VAT
        if (region == "EU") 
            return price * 0.20;    // 20% VAT
        if (region == "Canada")
            return price * 0.13;    // 13% VAT
        return 0.0;                 // tax-free
    }

private:
    std::string name;
    double price;
};