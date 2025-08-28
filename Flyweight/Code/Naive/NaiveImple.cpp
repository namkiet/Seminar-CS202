#include "NaiveImple.h"

Comment::Comment(const string &name, const string &avatarUrl, const string &profileUrl, const string &text)
    : name(name), avatarUrl(avatarUrl), profileUrl(profileUrl), text(text)
{
}

void Comment::display() const
{
    cout << name
         << " [" << profileUrl << "]\n"
         << "Avatar: " << avatarUrl << "\n"
         << "Comment: " << text << "\n\n";
}

void CommentManager::addComment(const string &name, const string &avatarUrl, const string &profileUrl, const string &text)
{
    comments.emplace_back(Comment(name, avatarUrl, profileUrl, text));
}

void CommentManager::showAll() const
{
    for (const auto &c : comments)
        c.display();
}