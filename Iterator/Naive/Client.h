#pragma once
#include "User.h"
#include "Facebook.h"
#include "Instagram.h"
#include "TikTok.h"
#include <iostream>

class Client
{
public:
    void sendFacebookMessage(const Facebook& fb)
    {
        std::stack<User> fbUsers = fb.getAllUsers();

        while (!fbUsers.empty())
        {
            sendMessageToUser(fbUsers.top(), "HELLO from FB");
            fbUsers.pop();
        }
    }

    void sendInstagramMessage(const Instagram& ig)
    {
        std::vector<User> igUsers = ig.getAllUsers();

        for (int i = 0; i < igUsers.size(); i++)
        {
            sendMessageToUser(igUsers[i], "HELLO from IG");
        }
    }

    void sendTikTokMessage(const TikTok& tiktok)
    {
        std::unordered_map<std::string, User> tiktokUsers = tiktok.getAllUsers();
        
        for (auto it = tiktokUsers.begin(); it != tiktokUsers.end(); ++it)
        {
            sendMessageToUser(it->second, "Hello from Tiktok");
        }
    }

private:
    static void sendMessageToUser(const User& user, const std::string& message) 
    {
        std::cout << "Sending to " << user.getEmail() << ": " << message << std::endl;
    }
};