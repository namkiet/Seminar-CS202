#include <iostream>
#include <string.h>
#include <unordered_map>
#include <memory>
#include <vector>
using namespace std;

struct SharedState 
{
    string brand;
    string model;
    string color;

    SharedState(const string& brand, const string& model, const string& color): // tai sao lai la const &
        brand(brand), model(model), color(color) 
        {
        }
    SharedState(const SharedState& other) {

    }
    string hashKey() const {
        return brand + "_" + model + "_" + color;
    }
};

struct UniqueState
{
    string owner;
    string plates;
    UniqueState(const string& owner, const string& plates): owner(owner), plates(plates)
    {
    }
};

// class FlyWeight {
//     private:
//         SharedState* share_state;
//     public:
        
//         void Operation(const UniqueState &unique_state) const 
//         {
//             cout <<""
//         }

// };

class FlyWeightFactory {
    private:
        std::unordered_map<string, SharedState> flyweights;

        string getKey(const SharedState& ss) const 
        {
            return ss.hashKey();
        }
    public:
        FlyWeightFactory(std::initializer_list<SharedState> shared_states) 
        {
            for (const SharedState& ss: shared_states)
            {
                this->flyweights.insert(std::make_pair(this->getKey(ss), ss));
            }
        }

        SharedState getSharedState (const SharedState& ss) {
            string key = ss.hashKey();
            if (this->flyweights.find(key) == this->flyweights.end()) // may need to define operator== in SharedState
            {
                std::cout << "FlyweightFactory: Can't find corresponding sharedstate, creating new one.\n";
                this->flyweights.insert(std::make_pair(key, ss));
            }
            else 
            {
                std::cout << "FlyweightFactory: reusing existing sharedState\n";
            }
            return this->flyweights.at(key);
        }
        // void ListFlyweights() const
        // {
        //     size_t count = this->flyweights.size();
        //     std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        //     for (std::pair<std::string, SharedState> pair : this->flyweights)
        //     {
        //         std::cout << pair.first << "\n";
        //     }
        // }
};

class Car
{
    private:
        UniqueState us;
        SharedState& ss;
    public:
        Car(const string& owner, const string& plates, SharedState& ss):
        us(owner, plates), ss(ss) {}
};

class CarManagement {
    private:
        std::vector<Car*> listCar;
        FlyWeightFactory& factory;
    public:
        CarManagement(FlyWeightFactory& factory): factory(factory) {}
        void addCar(const string& plates, const string& owner, const string& brand, const string& model, const string& color) {
            auto sharedState = factory.getSharedState({brand, model, color});
            listCar.push_back(new Car(owner, plates, sharedState));
        }
};

int main() {
    FlyWeightFactory* factory = new FlyWeightFactory({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
    CarManagement* manageCar = new CarManagement(*factory);
    // factory->ListFlyweights();
    manageCar->addCar("CL234IR", "James Doe", "BMW", "M5", "red");
    manageCar->addCar("CL234IR","James Doe","BMW","X1","red");
    return 0;
}
