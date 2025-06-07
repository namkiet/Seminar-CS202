#pragma once
#include "Product.h"

// Concrete Product
class Electronics : public Product 
{
public:
    Electronics(const std::string& name, double price);
    double accept(TaxVisitor* visitor) override;
    std::string getName() const override;
    double getPrice() const override;

private:
    std::string name;
    double price;
};