#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual void visitA(ConcreteElementA* a) = 0;
    virtual void visitB(ConcreteElementB* b) = 0;
};

class Element
{
public:
    virtual ~Element() = default;
    virtual void accept(Visitor* visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visitA(this);
    }
};

class ConcreteElementB : public Element
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visitB(this);
    }
};

class ConcreteVistor1 : public Visitor
{
public:
    void visitA(ConcreteElementA* a) override
    {
        std::cout << "Visitor 1 visits A.\n";
    }

    void visitB(ConcreteElementB* b) override
    {
        std::cout << "Visitor 1 visits B.\n";
    }
};

class ConcreteVistor2 : public Visitor
{
public:
    void visitA(ConcreteElementA* a) override
    {
        std::cout << "Visitor 2 visits A.\n";
    }

    void visitB(ConcreteElementB* b) override
    {
        std::cout << "Visitor 2 visits B.\n";
    }
};

int main()
{
    ConcreteVistor1* visitor1 = new ConcreteVistor1();
    ConcreteVistor2* visitor2 = new ConcreteVistor2();

    std::vector<Element*> elements;
    elements.push_back(new ConcreteElementA());
    elements.push_back(new ConcreteElementB());

    for (Element* e : elements)
    {
        e->accept(visitor2);
    }

    return 0;
}