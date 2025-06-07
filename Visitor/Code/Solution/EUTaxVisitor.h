#pragma once
#include "TaxVisitor.h"

// Concrete Visitor: EU Tax
class EUTaxVisitor : public TaxVisitor 
{
public:
    double visitFood(Food* item) override 
    {
        return item->getPrice() * 0.05; // 5% VAT
    }

    double visitElectronics(Electronics* item) override 
    {
        return item->getPrice() * 0.20; // 20% VAT
    }

    double visitClothes(Clothes* item) override 
    {
        if (item->isChildWear()) // 5% VAT for child-wear
            return item->getPrice() * 0.05;
        return item->getPrice() * 0.10; // 10% VAT
    }
};