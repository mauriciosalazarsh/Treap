#include "Treap.h"
#include "TreapVisualizer.h"

int main() {
    Treap treap;
    treap.insert(5);
    treap.insert(3);
    treap.insert(8);
    treap.insert(1);
    treap.insert(4);

    TreapVisualizer visualizer(treap);
    visualizer.run();

    return 0;
}

