#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Comment {
    private:
    string name;
    string avatarUrl;
    string profileUrl;
    string text;
    public:
    Comment(const string& name,
            const string& avatarUrl,
            const string& profileUrl,
            const string& text)
      : name(name),
        avatarUrl(avatarUrl),
        profileUrl(profileUrl),
        text(text)
    {}
    
    void display() const {
        cout << name
             << " [" << profileUrl << "]\n"
             << "Avatar: " << avatarUrl << "\n"
             << "Comment: " << text << "\n\n";
    }
};

class CommentManager {
    vector<Comment> comments;
public:
    void addComment(const string& name,
                    const string& avatarUrl,
                    const string& profileUrl,
                    const string& text)
    {
        comments.emplace_back(Comment(name, avatarUrl, profileUrl, text));
    }

    void showAll() const {
        for (const auto& c : comments)
            c.display();
    }
};

int main() {
    CommentManager manager;
    manager.addComment(
        "Alice",
        "https://fb.com/alice/avatar.jpg",
        "https://fb.com/alice",
        "This is Alice's first comment!"
    );
    manager.addComment(
        "Bob",
        "https://fb.com/bob/avatar.jpg",
        "https://fb.com/bob",
        "Hello from Bob."
    );
    manager.showAll();
    return 0;
}