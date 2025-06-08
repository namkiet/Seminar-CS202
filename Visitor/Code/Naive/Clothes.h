#pragma once
#include "Product.h"

// Concrete Product
class Clothes : public Product 
{
public:
    Clothes(std::string name, double price, bool isChildWear) 
        : name(name), price(price), isChildWear(isChildWear) {}

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
        if (isChildWear) 
            return 0.0;             // tax-free
        if (region == "USA") 
            return price * 0.10;    // 10% VAT
        if (region == "EU") 
            return price * 0.12;    // 12% VAT
        if (region == "Canada") 
            return price * 0.08;    // 8% VAT
        return price * 0.05;        // 5% VAT
    }

private:
    std::string name;
    double price;
    bool isChildWear;
};