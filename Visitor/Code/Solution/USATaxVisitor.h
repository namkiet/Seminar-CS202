#pragma once
#include "TaxVisitor.h"

// Concrete Visitor: USA Tax
class USATaxVisitor : public TaxVisitor 
{
public:
    double visitFood(Food* item) override 
    {
        return 0.0; // tax-free
    }

    double visitElectronics(Electronics* item) override 
    {
        return item->getPrice() * 0.15; // 15% VAT
    }
    
    double visitClothes(Clothes* item) override 
    {
        if (item->isChildWear()) // tax-free for child-wear
            return 0.0;
        return item->getPrice() * 0.10; // 10% VAT
    }
};