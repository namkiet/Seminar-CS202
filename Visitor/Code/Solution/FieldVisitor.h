#pragma once

// Forward Declaration
class DatePicker;
class TextInput;

// Interface for Field Visitor
class FieldVisitor 
{
public:
    virtual ~FieldVisitor() = default;
    virtual void visitDatePicker(DatePicker* field) = 0;
    virtual void visitTextInput(TextInput* field) = 0;
};