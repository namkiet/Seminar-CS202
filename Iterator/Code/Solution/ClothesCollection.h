#pragma once
#include "Collection.h"
#include <vector>

class ClothesIterator;
class ClothesCollection : public Collection {
public:
    ClothesCollection();
    std::unique_ptr<Iterator> createIterator() override;
    friend class ClothesIterator;

private:
    std::vector<Product> products;
};
