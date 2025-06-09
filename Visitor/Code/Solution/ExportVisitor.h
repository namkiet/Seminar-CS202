#pragma once
#include "FieldVisitor.h"
#include "DatePicker.h"
#include "TextInput.h"
#include <sstream>
#include <string>

// Concrete Visitor: Export
class ExportVisitor : public FieldVisitor 
{
public:
    void visitDatePicker(DatePicker* field) override 
    {
        ss << "FieldType: " << field->getName() << "\n";
        ss << "Label: " << field->getDate() << "\n\n";
    }

    void visitTextInput(TextInput* field) override 
    {
        ss << "FieldType: " << field->getName() << "\n";
        ss << "Label: " << field->getValue() << "\n\n";
    }

    std::string getResult() const 
    {
        return ss.str();
    }

private:
    std::stringstream ss;
};
