
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "ais1002/folder.hpp"

using namespace ais1002;

TEST_CASE("") {

    folder c("C:");
    folder users("Users");
    folder laht("laht");
    folder dev("dev");
    folder documents("Documents");

    c.add(users);
    users.add(laht);
    laht.add(dev);
    laht.add(documents);

    REQUIRE(c.isRoot());
    REQUIRE(!users.isLeaf());
    REQUIRE(!users.isRoot());

    REQUIRE(dev.isLeaf());

    REQUIRE(laht.numChildren() == 2);

    std::vector<folder*> collect;
    c.traverseDepthFirst([&](folder* f){
        collect.emplace_back(f);
    });

    REQUIRE(collect.size() == 5);

    documents.removeFromParent();
    REQUIRE(laht.numChildren() == 1);
    REQUIRE(documents.isRoot());

}