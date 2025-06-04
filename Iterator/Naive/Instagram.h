#pragma once
#include <vector>

class Instagram
{
public:
    Instagram()
    {
        users.push_back(User("Kiet", "kiet@gmail.com"));
    }

    const std::vector<User>& getAllUsers() const
    {
        return users;
    }

private:
    std::vector<User> users;
};