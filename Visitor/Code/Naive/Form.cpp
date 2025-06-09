#include "Form.h"
#include "Field.h"

void Form::addField(std::shared_ptr<Field> field)
{
    fields.push_back(field);
}

void Form::validate() const
{
    for (auto& field : fields)
    {
        field->validate();
    }
}

void Form::preview() const 
{
    for (auto& field : fields) 
    {
        field->preview();
    }
}

std::string Form::exportToString() const
{
    std::string str = "";
    for (auto& field : fields)
    {
        str += field->exportToString();
    }
    return str;
}