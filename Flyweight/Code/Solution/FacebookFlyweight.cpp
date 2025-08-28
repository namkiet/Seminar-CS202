#include "FacebookFlyweight.h"

CommenterInfo::CommenterInfo(const string &name, const string &avatar, const string &profile)
    : authorName(name), avatarUrl(avatar), profileUrl(profile)
{
}

string CommenterInfo::key() const
{
    return authorName + "  " + avatarUrl + "  " + profileUrl;
}

CommentContent::CommentContent(const string &txt)
    : text(txt)
{
}

CommenterFactory::CommenterFactory(initializer_list<CommenterInfo> initList)
{
    for (auto const &info : initList)
    {
        auto ptr = make_shared<CommenterInfo>(info);
        pool[info.key()] = ptr;
    }
}

shared_ptr<CommenterInfo> CommenterFactory::get(const CommenterInfo &info)
{
    auto k = info.key();
    auto it = pool.find(k);
    if (it != pool.end())
    {
        return it->second;
    }
    auto ptr = make_shared<CommenterInfo>(info);
    pool[k] = ptr;
    return ptr;
}

void CommenterFactory::listAll() const
{
    cout << "Pool has " << pool.size() << " commenters:\n";
    for (auto const &kv : pool)
    {
        cout << " - " << kv.first << "\n";
    }
}

Comment::Comment(shared_ptr<CommenterInfo> c, const string &txt)
    : commenter(move(c)), content(txt)
{
}

void Comment::display() const
{
    cout << commenter->authorName
         << " [" << commenter->profileUrl << "]\n"
         << "Avatar: " << commenter->avatarUrl << "\n"
         << "Comment: " << content.text
         << "\n\n";
}

CommentManager::CommentManager(CommenterFactory &fac)
    : factory(fac)
{
}

void CommentManager::add(const string &authorName,
         const string &avatarUrl,
         const string &profileUrl,
         const string &text)
{
    auto info = factory.get({authorName, avatarUrl, profileUrl});
    comments.emplace_back(
        make_unique<Comment>(info, text));
}

void CommentManager::showAll() const
{
    for (auto const &c : comments)
        c->display();
}