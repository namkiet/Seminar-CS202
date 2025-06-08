#include "Clothes.h"
#include "Electronics.h"
#include "Food.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// -------------------- Main --------------------
int main() 
{
    std::vector<std::shared_ptr<Product>> cart = {
        std::make_shared<Food>("Bread", 2.5),
        std::make_shared<Electronics>("Laptop", 1000.0),
        std::make_shared<Clothes>("Jacket", 120.0, false),
        std::make_shared<Clothes>("Kids Jacket", 60.0, true)
    };

    std::string region = "Canada"; // Choose region

    double totalTax = 0.0;
    for (const auto& product : cart) {
        double tax = product->getTax(region);
        std::cout << product->getName() << " - $" << product->getPrice()
                  << " | Tax: $" << tax << std::endl;
        totalTax += tax;
    }

    std::cout << "Total Tax: $" << totalTax << std::endl;
    return 0;
}
