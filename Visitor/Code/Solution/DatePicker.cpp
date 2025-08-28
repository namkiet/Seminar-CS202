#include "DatePicker.h"
#include "FieldVisitor.h"

void DatePicker::accept(FieldVisitor* visitor)
{
    visitor->visitDatePicker(this);
}

std::string DatePicker::getName() const
{
    return "Date Picker";
}

void DatePicker::setDate(const std::string& newDate)
{
    date = newDate;
}

const std::string& DatePicker::getDate() const
{
    return date;
}