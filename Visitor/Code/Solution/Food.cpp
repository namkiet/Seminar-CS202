#include "Food.h"
#include "TaxVisitor.h"

Food::Food(const std::string& name, double price) 
    : name(name), price(price) {}

double Food::accept(TaxVisitor* visitor) 
{
    return visitor->visitFood(this);
}

std::string Food::getName() const 
{ 
    return name; 
}

double Food::getPrice() const 
{ 
    return price; 
}