#pragma once
#include <string>

// Interface for Field
class Field 
{
public: 
    virtual ~Field() = default;
    virtual std::string getName() const = 0;
    virtual void validate() const = 0;
    virtual void preview() const = 0;
    virtual std::string exportToString() const = 0;
};