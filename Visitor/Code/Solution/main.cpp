#include "Clothes.h"
#include "Electronics.h"
#include "Food.h"
#include "USATaxVisitor.h"
#include "EUTaxVisitor.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

int main() 
{
    std::vector<std::unique_ptr<Product>> cart;
    cart.emplace_back(std::make_unique<Food>("Bread", 2.50));
    cart.emplace_back(std::make_unique<Electronics>("Phone", 500.00));
    cart.emplace_back(std::make_unique<Clothes>("Jacket", 80.00, false));
    cart.emplace_back(std::make_unique<Clothes>("Kids Shirt", 30.00, true));

    USATaxVisitor usaTax;
    EUTaxVisitor euTax;

    std::cout << "=== Tax Calculation (USA) ===\n";
    for (const auto& item : cart) 
    {
        double tax = item->accept(&usaTax);
        std::cout << item->getName() << " - Tax: $" << tax << '\n';
    }

    std::cout << "\n=== Tax Calculation (EU) ===\n";
    for (const auto& item : cart) 
    {
        double tax = item->accept(&euTax);
        std::cout << item->getName() << " - Tax: $" << tax << '\n';
    }

    return 0;
}
