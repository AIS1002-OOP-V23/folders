
#include <iostream>

#include "ais1002/folder.hpp"

using namespace ais1002;

int main() {

    folder c("C:");
    folder left("left");
    folder bar("bar");
    folder baz("baz");
    folder fubar("fubar");

    c.add(left);

    c.add(bar);
    bar.add(baz);
    bar.add(fubar);

    baz.traverseUpwards([](folder* f){
        std::cout << f->getAbsolutePath() << std::endl;
    });

    std::cout << std::endl;

    c.traverseDepthFirst([](folder* f){
        std::cout << f->getAbsolutePath() << std::endl;
    });

    return 0;
}
