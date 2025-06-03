#include "User.h"
#include "Facebook.h"
#include "Instagram.h"
#include "TikTok.h"
#include <iostream>

void sendMessage(const User& user, const std::string& message) {
    std::cout << "Sending to " << user.getEmail() << ": " << message << std::endl;
}

int main()
{
    Facebook fb;
    std::stack<User> fbUsers = fb.getAllUsers();

    while (!fbUsers.empty())
    {
        sendMessage(fbUsers.top(), "HELLO from FB");
        fbUsers.pop();
    }
    
    Instagram ig;
    std::vector<User> igUsers = ig.getAllUsers();

    for (int i = 0; i < igUsers.size(); i++)
    {
        sendMessage(igUsers[i], "HELLO from IG");
    }

    TikTok tiktok;
    std::unordered_map<std::string, User> tiktokUsers = tiktok.getAllUsers();
    
    for (auto it = tiktokUsers.begin(); it != tiktokUsers.end(); ++it)
    {
        sendMessage(it->second, "Hello from Tiktok");
    }

    return 0;
}
