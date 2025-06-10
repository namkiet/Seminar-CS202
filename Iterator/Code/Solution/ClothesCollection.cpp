#include "ClothesCollection.h"
#include <memory>
#include <cassert>

ClothesCollection::ClothesCollection() {
    products.emplace_back("T-Shirt", 300000);
    products.emplace_back("Jeans",   400000);
    products.emplace_back("Jacket",  200000);
}

class ClothesIterator : public Iterator {
public:
    explicit ClothesIterator(const ClothesCollection& coll)
      : collection(coll) {}

    bool hasNext() override {
        return index < collection.products.size();
    }
    void next() override {
        if (hasNext()) ++index;
    }
    Product current() override {
        assert(index < collection.products.size());
        return collection.products[index];
    }

private:
    const ClothesCollection& collection;
    size_t index = 0;
};

std::unique_ptr<Iterator> ClothesCollection::createIterator() {
    return std::make_unique<ClothesIterator>(*this);
}
