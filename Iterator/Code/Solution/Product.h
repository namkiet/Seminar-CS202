#pragma once
#include <string>

class Product {
public:
    Product();
    Product(const std::string& name, double price);

    std::string getName() const;
    double getPrice() const;
    void display() const;

private:
    std::string name;
    double price;
};