#pragma once
#include "FieldVisitor.h"
#include "DatePicker.h"
#include "TextInput.h"
#include <iostream>

// Concrete Visitor: Validation
class ValidationVisitor : public FieldVisitor 
{
public:
    void visitDatePicker(DatePicker* field) override
    {
        if (field->getDate().empty())
        {
            std::cout << "[ERROR] Date required.\n";
        }
    }

    void visitTextInput(TextInput* field) override
    {
        if (field->getValue().empty())
        {
            std::cout << "[ERROR] Text input required.\n";
        }
    }
};