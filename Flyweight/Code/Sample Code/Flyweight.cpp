#include "Flyweight.h"

IntrinsicState::IntrinsicState(std::string d) : data(std::move(d)) {}

ExtrinsicState::ExtrinsicState(int i) : id(i) {}

ConcreteFlyweight::ConcreteFlyweight(const IntrinsicState &s) : intrinsic(s) {}

void ConcreteFlyweight::operation(const ExtrinsicState &e) const
{
    std::cout << "Intrinsic=" << intrinsic.data << ", Extrinsic=" << e.id << "\n";
}

std::shared_ptr<Flyweight> FlyweightFactory::getFlyweight(const std::string &key,
                                                        const IntrinsicState &s)
{
    auto it = pool.find(key);
    if (it != pool.end())
    {
        return it->second;
    }
    auto fw = std::make_shared<ConcreteFlyweight>(s);
    pool[key] = fw;
    return fw;
}

Context::Context(std::shared_ptr<Flyweight> fw, ExtrinsicState e)
    : flyweight(std::move(fw)), extrinsic(e) {}

void Context::doSomething() const
{
    flyweight->operation(extrinsic);
}