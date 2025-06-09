#include "Form.h"
#include "Field.h"
#include "ValidationVisitor.h"
#include "PreviewVisitor.h"
#include "ExportVisitor.h"

void Form::addField(std::shared_ptr<Field> field)
{
    fields.push_back(field);
}

void Form::validate() const
{
    ValidationVisitor validator;
    for (auto& field : fields)
    {
        field->accept(&validator);
    }
}

void Form::preview() const 
{
    PreviewVisitor previewer;
    for (auto& field : fields) 
    {
        field->accept(&previewer);
    }
}

std::string Form::exportToString() const
{
    ExportVisitor exporter;
    for (auto& field : fields)
    {
        field->accept(&exporter);
    }
    return exporter.getResult();
}