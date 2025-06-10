#pragma once
#include "ClothesCollection.h"
#include "BookCollection.h"
#include "ElectronicsCollection.h"
#include <iostream>
#include <iomanip>

// Client
class Store
{
public:
    void displayAllClothes()
    {
        std::vector<Product> products = clothes.getAllProducts();

        for (int i = 0; i < products.size(); i++)
        {
            display(products[i]);
        }
    }

    void displayAllBooks()
    {
        std::stack<Product> products = books.getAllProducts();

        while (!products.empty())
        {
            display(products.top());
            products.pop();
        }
    }

    void displayAllElectronics()
    {
        std::unordered_map<std::string, Product> products = electronics.getAllProducts();
        
        for (auto it = products.begin(); it != products.end(); ++it)
        {
            display(it->second);
        }
    }

private:
    static void display(const Product& product) 
    {
        std::cout << "Product \"" << product.getName() << "\" cost " << std::fixed << std::setprecision(0) << product.getPrice() << "VND.\n";
    }

private:
    BookCollection books;
    ClothesCollection clothes;
    ElectronicsCollection electronics;
};