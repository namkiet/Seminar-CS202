#pragma once
#include <string>

// Forward Declaration
class FieldVisitor;

// Interface for Field
class Field 
{
public: 
    virtual ~Field() = default;
    virtual void accept(FieldVisitor* visitor) = 0;
    virtual std::string getName() const = 0;
};