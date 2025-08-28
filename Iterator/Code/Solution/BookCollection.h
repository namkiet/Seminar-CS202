#pragma once
#include "Collection.h"
#include <stack>

class BookIterator;
class BookCollection : public Collection {
public:
    BookCollection();
    std::unique_ptr<Iterator> createIterator() override;
    friend class BookIterator;

private:
    std::stack<Product> products;
};