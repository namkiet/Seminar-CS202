#pragma once
#include "Product.h"

// Concrete Product
class Food : public Product 
{
public:
    Food(const std::string& name, double price);
    double accept(TaxVisitor* visitor) override;
    std::string getName() const override;
    double getPrice() const override;

private:
    std::string name;
    double price;
};