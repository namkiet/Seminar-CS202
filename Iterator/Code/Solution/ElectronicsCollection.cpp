#include "ElectronicsCollection.h"
#include <memory>
#include <cassert>
#include <vector>

ElectronicsCollection::ElectronicsCollection() {
    products["smartphone"] = Product("Galaxy S21", 20000000);
    products["laptop"]     = Product("MacBook Pro", 30000000);
}

class ElectronicsIterator : public Iterator {
public:
    explicit ElectronicsIterator(const ElectronicsCollection& coll)
      : collection(coll) {
        for (auto const& kv : collection.products)
            keys.push_back(kv.first);
    }

    bool hasNext() override {
        return index < keys.size();
    }
    void next() override {
        if (hasNext()) ++index;
    }
    Product current() override {
        assert(index < keys.size());
        return collection.products.at(keys[index]);
    }

private:
    const ElectronicsCollection& collection;
    std::vector<std::string> keys;
    size_t index = 0;
};

std::unique_ptr<Iterator> ElectronicsCollection::createIterator() {
    return std::make_unique<ElectronicsIterator>(*this);
}

