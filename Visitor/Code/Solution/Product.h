#pragma once
#include <string>

// Forward Declaration
class TaxVisitor;

// Interface for Product
class Product 
{
public:
    virtual ~Product() = default;
    virtual double accept(TaxVisitor* visitor) = 0;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
};