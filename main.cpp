#include "Treap.h"
#include "TreapVisualizer.h"

int main() {
    Treap treap;
    TreapVisualizer visualizer(1000, 700, "Treap Visualizer");
    treap.setVisualizer(&visualizer);

    visualizer.setMessage("Insertando nodos...");
    treap.insert(50, visualizer);
    treap.insert(30, visualizer);
    treap.insert(70, visualizer);
    treap.insert(20, visualizer);
    treap.insert(40, visualizer);

    visualizer.setMessage("Eliminando nodos...");
    treap.deleteNode(30);

    visualizer.visualizeTreap(&treap);

    return 0;
}
