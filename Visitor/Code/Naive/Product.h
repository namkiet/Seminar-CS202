#pragma once
#include <string>

// Interface for Product
class Product 
{
public:
    virtual ~Product() = default;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual double getTax(const std::string& region) const = 0;
};