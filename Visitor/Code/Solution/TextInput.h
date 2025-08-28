#pragma once
#include "Field.h"
#include <string>

// Concrete Field
class TextInput : public Field 
{
public:
    void accept(FieldVisitor* visitor) override;
    std::string getName() const override;
    void setValue(const std::string& newValue);
    const std::string& getValue() const;
    
private:
    std::string value;
};