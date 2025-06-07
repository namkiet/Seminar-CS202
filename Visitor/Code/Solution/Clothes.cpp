#include "Clothes.h"
#include "TaxVisitor.h"

Clothes::Clothes(const std::string& name, double price, bool isChild) 
    : name(name), price(price), isChild(isChild) {}

double Clothes::accept(TaxVisitor* visitor) 
{
    return visitor->visitClothes(this);
}

std::string Clothes::getName() const 
{ 
    return name; 
}

double Clothes::getPrice() const 
{ 
    return price; 
}

bool Clothes::isChildWear() const 
{ 
    return isChild; 
}