#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Comment
{
private:
    string name;
    string avatarUrl;
    string profileUrl;
    string text;

public:
    Comment(const string &name, const string &avatarUrl, const string &profileUrl, const string &text);
    void display() const;
};

class CommentManager
{
    vector<Comment> comments;

public:
    void addComment(const string &name, const string &avatarUrl, const string &profileUrl, const string &text);

    void showAll() const;
};

