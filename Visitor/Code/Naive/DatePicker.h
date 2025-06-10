#pragma once
#include "Field.h"
#include <iostream>
#include <sstream>

// Concrete Field
class DatePicker : public Field 
{
public:
    std::string getName() const override
    {
        return "Date Picker";
    }

    
    void validate() const override
    {
        if (date.empty())
        {
            std::cout << "[ERROR] Date required.\n";
        }
    }
    
    void preview() const override
    {
        
        std::cout << "[" << getName() << "] " << date << ".\n";
    }
    
    std::string exportToString() const override
    {
        std::stringstream ss;
        ss << "FieldType: " << getName() << "\n";
        ss << "Label: " << date << "\n\n";
        return ss.str();
    }
    
    void setDate(const std::string& newDate)
    {
        date = newDate;
    }
    
private:
    std::string date;
};