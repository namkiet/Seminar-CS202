#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

struct IntrinsicState
{
    std::string data;
    IntrinsicState(std::string d);
};

struct ExtrinsicState
{
    int id;
    ExtrinsicState(int i);
};

// Flyweight interface
// each kind of flyweight perform different logic on operation
struct Flyweight
{
    virtual void operation(const ExtrinsicState &e) const = 0;
    virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight
{
    IntrinsicState intrinsic;

public:
    ConcreteFlyweight(const IntrinsicState &s);
    void operation(const ExtrinsicState &e) const override;
};

class FlyweightFactory
{
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> pool;

public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string &key, const IntrinsicState &s);
};

class Context
{
    std::shared_ptr<Flyweight> flyweight;
    ExtrinsicState extrinsic;

public:
    Context(std::shared_ptr<Flyweight> fw, ExtrinsicState e);

    void doSomething() const;
};

