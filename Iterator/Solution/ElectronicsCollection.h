#pragma once
#include "Collection.h"
#include <unordered_map>
#include <string>

class ElectronicsIterator;
class ElectronicsCollection : public Collection {
public:
    ElectronicsCollection();
    std::unique_ptr<Iterator> createIterator() override;
    friend class ElectronicsIterator;

private:
    std::unordered_map<std::string, Product> products;
};