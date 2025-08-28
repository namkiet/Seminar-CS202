#pragma once
#include "FieldVisitor.h"
#include "DatePicker.h"
#include "TextInput.h"
#include <iostream>

// Concrete Visitor: Preview
class PreviewVisitor : public FieldVisitor 
{
public:
    void visitDatePicker(DatePicker* field) override 
    {
        std::cout << "[" << field->getName() << "] " << field->getDate() << ".\n";
    }

    void visitTextInput(TextInput* field) override 
    {
        std::cout << "[" << field->getName() << "] " << field->getValue() << ".\n";
    }
};