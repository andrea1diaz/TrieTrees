#include "radix_tree.h"

int main () {
    RadixTrieTree rt;

    rt.insert("hola", "0001");
    rt.insert("holas", "0002");
    rt.insert("holasa", "0003");
    rt.insert("home", "006");

    rt.search("home");

    return 0;
}
