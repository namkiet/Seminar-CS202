#include "Product.h"
#include <iostream>

Product::Product() = default;
Product::Product(const std::string& name, double price)
    : name(name), price(price) {}

std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }

void Product::display() const {
    std::cout << name << " " << price << std::endl;
}
