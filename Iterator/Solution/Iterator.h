#pragma once
#include "Product.h"

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual Product current() = 0;
    virtual ~Iterator() = default;
};
