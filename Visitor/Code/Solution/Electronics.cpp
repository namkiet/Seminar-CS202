#include "Electronics.h"
#include "TaxVisitor.h"

Electronics::Electronics(const std::string& name, double price) 
    : name(name), price(price) {}

double Electronics::accept(TaxVisitor* visitor) 
{
    return visitor->visitElectronics(this);
}

std::string Electronics::getName() const 
{ 
    return name; 
}

double Electronics::getPrice() const 
{ 
    return price; 
}