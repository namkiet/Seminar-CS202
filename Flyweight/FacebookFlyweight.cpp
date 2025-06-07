#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
using namespace std;

struct CommenterInfo {
    string authorName;
    string avatarUrl;
    string profileUrl;

    CommenterInfo(const string& name,
                  const string& avatar,
                  const string& profile)
      : authorName(name),
        avatarUrl(avatar),
        profileUrl(profile)
    {}

    string key() const {
        return authorName + "  " + avatarUrl + "  " + profileUrl;
    }
};

struct CommentContent {
    string text;
    CommentContent(const string& txt)
      : text(txt)
    {}
};

class CommenterFactory {
private:
    unordered_map<string, shared_ptr<CommenterInfo>> pool;
public:
    CommenterFactory(initializer_list<CommenterInfo> initList) {
        for (auto const& info : initList) {
            auto ptr = make_shared<CommenterInfo>(info);
            pool[info.key()] = ptr;
        }
    }

    shared_ptr<CommenterInfo> get(const CommenterInfo& info) {
        auto k = info.key();
        auto it = pool.find(k);
        if (it != pool.end()) {
            return it->second;
        }
        auto ptr = make_shared<CommenterInfo>(info);
        pool[k] = ptr;
        return ptr;
    }

    void listAll() const {
        cout << "Pool has " << pool.size() << " commenters:\n";
        for (auto const& kv : pool) {
            cout << " - " << kv.first << "\n";
        }
    }
};

class Comment {
    private:
    shared_ptr<CommenterInfo> commenter;
    CommentContent content;
    public:
    Comment(shared_ptr<CommenterInfo> c, const string& txt)
      : commenter(move(c)), content(txt)
    {}

    void display() const {
        cout << commenter->authorName
          << " [" << commenter->profileUrl << "]\n"
          << "Avatar: " << commenter->avatarUrl << "\n"
          << "Comment: " << content.text
          << "\n\n";
    }
};

class CommentManager {
private:
    CommenterFactory& factory;
    vector<unique_ptr<Comment>> comments;
public:
    explicit CommentManager(CommenterFactory& fac)
      : factory(fac)
    {}

    void add(const string& authorName,
             const string& avatarUrl,
             const string& profileUrl,
             const string& text)
    {
        auto info = factory.get({authorName, avatarUrl, profileUrl});
        comments.emplace_back(
          make_unique<Comment>(info, text)
        );
    }

    void showAll() const {
        for (auto const& c : comments)
            c->display();
    }
};

int main() {
    CommenterFactory factory({
        {"Alice","https://fb.com/alice/avatar.jpg","https://fb.com/alice"},
        {"Bob","https://fb.com/bob/avatar.jpg","https://fb.com/bob"}
    });

    CommentManager mgr(factory);

    mgr.add("Alice",
            "https://fb.com/alice/avatar.jpg",
            "https://fb.com/alice",
            "This is Alice's first comment!");

    mgr.add("Alice",
            "https://fb.com/alice/avatar.jpg",
            "https://fb.com/alice",
            "Alice commenting again—reusing her info.");

    mgr.add("Charlie",
            "https://fb.com/charlie/avatar.png",
            "https://fb.com/charlie",
            "Hey, this is Charlie joining the discussion.");

    mgr.showAll();

    factory.listAll();

    return 0;
}