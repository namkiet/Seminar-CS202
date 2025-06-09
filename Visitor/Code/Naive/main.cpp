#include "Form.h"
#include "TextInput.h"
#include "DatePicker.h"

#include <iostream>

int main() 
{
    auto textInput = std::make_shared<TextInput>();
    auto datePicker = std::make_shared<DatePicker>();

    Form form;
    form.addField(textInput);
    form.addField(datePicker);

    textInput->setValue("ABC");
    datePicker->setDate("09/06/2025");
    form.preview();
    std::cout << form.exportToString();

    return 0;
}
