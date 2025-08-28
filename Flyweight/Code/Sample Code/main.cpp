#include "Flyweight.h"

int main()
{
    FlyweightFactory factory;

    auto fwA = factory.getFlyweight("A", IntrinsicState("SharedA"));
    Context c1(fwA, ExtrinsicState(1));
    Context c2(fwA, ExtrinsicState(2));

    auto fwB = factory.getFlyweight("B", IntrinsicState("SharedB"));
    Context c3(fwB, ExtrinsicState(3));

    c1.doSomething();
    c2.doSomething();
    c3.doSomething();

    return 0;
}
