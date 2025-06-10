#pragma once
#include "Field.h"
#include <iostream>
#include <sstream>

// Concrete Field
class TextInput : public Field 
{
public:
    std::string getName() const override
    {
        return "Text Input";
    }

    
    void validate() const override
    {
        if (value.empty())
        {
            std::cout << "[ERROR] Text input required.\n";
        }
    }
    
    void preview() const override
    {
        
        std::cout << "[" << getName() << "] " << value << ".\n";
    }
    
    std::string exportToString() const override
    {
        std::stringstream ss;
        ss << "FieldType: " << getName() << "\n";
        ss << "Label: " << value << "\n\n";
        return ss.str();
    }
    
    void setValue(const std::string& newValue)
    {
        value = newValue;
    }
    
private:
    std::string value;
};