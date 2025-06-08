#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>
using namespace std;

// Abstract Iterator
template<typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T& operator*() = 0;
    virtual Iterator<T>& operator++() = 0;
    virtual bool operator!=(const Iterator<T>& other) const = 0;
};

// Abstract IterableCollection
template<typename T>
class IterableCollection {
public:
    virtual ~IterableCollection() = default;
    virtual std::unique_ptr<Iterator<T>> begin() = 0;
    virtual std::unique_ptr<Iterator<T>> end() = 0;
    virtual std::unique_ptr<Iterator<T>> createIterator() = 0;
};

// Forward declaration
template<typename T>
class ConcreteIterator;

// ConcreteCollection
template<typename T>
class ConcreteCollection : public IterableCollection<T> {
private:
    std::vector<T> collection;

public:
    void add(const T& item) {
        collection.push_back(item);
    }

    T& get(int index) {
        return collection.at(index);
    }

    const T& get(int index) const {
        return collection.at(index);
    }

    int size() const {
        return collection.size();
    }

    std::unique_ptr<Iterator<T>> begin() override {
        return std::make_unique<ConcreteIterator<T>>(*this, 0);
    }

    std::unique_ptr<Iterator<T>> end() override {
        return std::make_unique<ConcreteIterator<T>>(*this, size());
    }

    std::unique_ptr<Iterator<T>> createIterator() override {
        return std::make_unique<ConcreteIterator<T>>(*this);
    }

    friend class ConcreteIterator<T>;
};

// ConcreteIterator
template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
    ConcreteCollection<T>& collection;
    int index;

public:
    ConcreteIterator(ConcreteCollection<T>& coll) : collection(coll), index(0) {}
    ConcreteIterator(ConcreteCollection<T>& coll, int idx) : collection(coll), index(idx) {}

    T& operator*() override {
        assert(index < collection.size());
        return collection.get(index);
    }

    Iterator<T>& operator++() override {
        ++index;
        return *this;
    }

    bool operator!=(const Iterator<T>& other) const override {
        auto* o = dynamic_cast<const ConcreteIterator<T>*>(&other);
        return !o || index != o->index;
    }
};

int main() {
    ConcreteCollection<std::string> names;
    names.add("Student1");
    names.add("Student2");
    names.add("Student3");

    auto it = names.begin();

    while (*it != *names.end()) {
        cout << **it << endl;
        ++(*it);
    }
    names.add("Student4");
        while (*it != *names.end()) {
        cout << **it << endl;
        ++(*it);
    }

    return 0;
}
