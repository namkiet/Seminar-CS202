#pragma once
#include <stack>

class Facebook
{
public:
    Facebook()
    {
        users.push(User("Kiet", "kiet@gmail.com"));
        users.push(User("Linh", "linh@gmail.com"));
        users.push(User("Huyen", "huyen@gmail.com"));
    }

    const std::stack<User>& getAllUsers() const
    {
        return users;
    }

private:
    std::stack<User> users;
};