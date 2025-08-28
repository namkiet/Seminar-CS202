#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <memory>

template<typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual T current() = 0;
    virtual ~Iterator() = default;
};

template<typename T>
class IterableCollection {
public:
    virtual std::unique_ptr<Iterator<T>> createIterator() = 0;
    virtual ~IterableCollection() = default;
};

template<typename T>
class ConcreteIterator;

template<typename T>
class ConcreteCollection : public IterableCollection<T> {
private:
    std::vector<T> collection;
public:
    ConcreteCollection() = default;

    void add(const T& item) {
        collection.push_back(item);
    }
    T get(int index) const {
        return collection.at(index);
    }
    int size() const {
        return collection.size();
    }
    std::unique_ptr<Iterator<T>> createIterator() override {
        return std::make_unique<ConcreteIterator<T>>(*this);
    }
    virtual ~ConcreteCollection() {}
};

template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
    const ConcreteCollection<T>& collection;
    int index = 0;
public:
    ConcreteIterator(const ConcreteCollection<T>& collection)
        : collection(collection) {}

    bool hasNext() override {
        return index < collection.size();
    }
    void next() override {
        if (!hasNext()) {
            std::cout << "Reach the end" << endl;
        } else {
            index += 1;
        }
    }
    T current() override {
        return collection.get(index);
    }
};

int main() {
    ConcreteCollection<string> names;
    names.add("Student1");
    names.add("Student2");
    names.add("Student3");

    auto it = names.createIterator();
    while (it->hasNext()) {
        cout << it->current() << endl;
        it->next();
    }
    return 0;
}