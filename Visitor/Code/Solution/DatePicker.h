#pragma once
#include "Field.h"
#include <string>

// Concrete Field
class DatePicker : public Field 
{
public:
    void accept(FieldVisitor* visitor) override;
    std::string getName() const override;
    void setDate(const std::string& newDate);
    const std::string& getDate() const;

private:
    std::string date;
};