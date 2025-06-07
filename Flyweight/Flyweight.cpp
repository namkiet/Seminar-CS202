#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

struct IntrinsicState {
    std::string data;
    IntrinsicState(std::string d) : data(std::move(d)) {}
};

struct ExtrinsicState {
    int id;
    ExtrinsicState(int i): id(i) {}
};

// Flyweight interface
// each kind of flyweight perform different logic on operation
struct Flyweight {
    virtual void operation(const ExtrinsicState& e) const = 0;
    virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight {
    IntrinsicState intrinsic;
public:
    ConcreteFlyweight(const IntrinsicState& s) : intrinsic(s) {}
    void operation(const ExtrinsicState& e) const override {
        std::cout << "Intrinsic=" << intrinsic.data << ", Extrinsic=" << e.id << "\n";
    }
};

class FlyweightFactory {
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> pool;
public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string& key,
                                            const IntrinsicState& s) {
        auto it = pool.find(key);
        if (it != pool.end()) {
            return it->second;
        }
        auto fw = std::make_shared<ConcreteFlyweight>(s);
        pool[key] = fw;
        return fw;
    }
};

class Context {
    std::shared_ptr<Flyweight> flyweight;
    ExtrinsicState extrinsic;
public:
    Context(std::shared_ptr<Flyweight> fw, ExtrinsicState e)
      : flyweight(std::move(fw)), extrinsic(e) {}

    void doSomething() const {
        flyweight->operation(extrinsic);
    }
};

int main() {
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
