#pragma once

// Forward Declaration
class Food;
class Electronics;
class Clothes;

// Interface for Tax Visitor
class TaxVisitor 
{
public:
    virtual ~TaxVisitor() = default;
    virtual double visitFood(Food* item) = 0;
    virtual double visitElectronics(Electronics* item) = 0;
    virtual double visitClothes(Clothes* item) = 0;
};