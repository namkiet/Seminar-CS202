#pragma once
#include <memory>
#include "Iterator.h"

class Collection {
public:
    virtual std::unique_ptr<Iterator> createIterator() = 0;
    virtual ~Collection() = default;
};