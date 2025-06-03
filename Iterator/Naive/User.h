#pragma once
#include <string>

class User {
public:
    User() = default;
    User(std::string name, std::string email)
        : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

private:
    std::string name;
    std::string email;
};