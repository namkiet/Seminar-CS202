#include "TextInput.h"
#include "FieldVisitor.h"

void TextInput::accept(FieldVisitor* visitor)
{
    visitor->visitTextInput(this);
}

std::string TextInput::getName() const
{
    return "Text Input";
}

void TextInput::setValue(const std::string& newValue)
{
    value = newValue;
}

const std::string& TextInput::getValue() const
{
    return value;
}