#pragma once
#include "Product.h"

// Concrete Product
class Clothes : public Product 
{
public:
    Clothes(const std::string& name, double price, bool isChild);
    double accept(TaxVisitor* visitor) override;
    std::string getName() const override;
    double getPrice() const override;
    bool isChildWear() const;

private:
    std::string name;
    double price;
    bool isChild;
};