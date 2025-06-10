#include <vector>
#include <memory>

// Forward Declaration
class Field;

class Form
{
public:
    void addField(std::shared_ptr<Field> field);
    void validate() const;
    void preview() const;
    std::string exportToString() const;

private:
    std::vector<std::shared_ptr<Field>> fields;
};