#pragma once
#include <vector>

class Instagram
{
public:
    Instagram()
    {
        users.push_back(User("Kiet", "kiet@gmail.com"));
    }

    std::vector<User> getAllUsers()
    {
        return users;
    }

private:
    std::vector<User> users;
};