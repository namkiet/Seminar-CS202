#include "BookCollection.h"
#include <memory>
#include <cassert>

BookCollection::BookCollection() {
    products.push(Product("The Night Circus", 150000));
    products.push(Product("Never Let Me Go", 200000));
    products.push(Product("The Martian", 300000));
}

class BookIterator : public Iterator {
public:
    explicit BookIterator(const BookCollection& coll)
      : collection(coll) {}

    bool hasNext() override {
        return index < collection.products.size();
    }
    void next() override {
        if (hasNext()) ++index;
    }
    Product current() override {
        std::stack<Product> copy = collection.products;
        for (size_t i = 0; i < index; ++i) copy.pop();
        assert(!copy.empty());
        return copy.top();
    }

private:
    const BookCollection& collection;
    size_t index = 0;
};

std::unique_ptr<Iterator> BookCollection::createIterator() {
    return std::make_unique<BookIterator>(*this);
}
