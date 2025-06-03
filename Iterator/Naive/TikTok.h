#pragma once
#include <string>
#include <unordered_map>

class TikTok
{
public:
    TikTok()
    {
        users["kiet"] = User("Kiet", "kiet@gmail.com");
        users["linh"] = User("Linh", "linh@gmail.com");
    }

    std::unordered_map<std::string, User> getAllUsers() const
    {
        return users;
    }

private:
    std::unordered_map<std::string, User> users;
};