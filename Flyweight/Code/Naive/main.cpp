#include "NaiveImple.h"

int main()
{
    CommentManager manager;
    manager.addComment(
        "Alice",
        "https://fb.com/alice/avatar.jpg",
        "https://fb.com/alice",
        "This is Alice's first comment!");
    manager.addComment(
        "Bob",
        "https://fb.com/bob/avatar.jpg",
        "https://fb.com/bob",
        "Hello from Bob.");
    manager.showAll();
    return 0;
}