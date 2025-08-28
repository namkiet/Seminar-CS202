#include "FacebookFlyweight.h"

int main()
{
    CommenterFactory factory({{"Alice", "https://fb.com/alice/avatar.jpg", "https://fb.com/alice"},
                              {"Bob", "https://fb.com/bob/avatar.jpg", "https://fb.com/bob"}});

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