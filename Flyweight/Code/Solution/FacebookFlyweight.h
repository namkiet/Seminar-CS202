#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
using namespace std;

struct CommenterInfo
{
    string authorName;
    string avatarUrl;
    string profileUrl;

    CommenterInfo(const string &name, const string &avatar, const string &profile);
    string key() const;
};

struct CommentContent
{
    string text;
    CommentContent(const string &txt);
};

class CommenterFactory
{
private:
    unordered_map<string, shared_ptr<CommenterInfo>> pool;

public:
    CommenterFactory(initializer_list<CommenterInfo> initList);
    shared_ptr<CommenterInfo> get(const CommenterInfo &info);
    void listAll() const;
};

class Comment
{
private:
    shared_ptr<CommenterInfo> commenter;
    CommentContent content;

public:
    Comment(shared_ptr<CommenterInfo> c, const string &txt);
    void display() const;
};

class CommentManager
{
private:
    CommenterFactory &factory;
    vector<unique_ptr<Comment>> comments;

public:
    explicit CommentManager(CommenterFactory &fac);
    void add(const string &authorName, const string &avatarUrl, const string &profileUrl, const string &text);
    void showAll() const;
};