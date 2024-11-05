#include "Treap.h"
#include "TreapVisualizer.h"

int main() {
    Treap treap;
    TreapVisualizer visualizer(treap);
    treap.setVisualizer(&visualizer); // Asocia el visualizador con el Treap

    // Inserciones con el visualizador como segundo parámetro
    treap.insert(1, visualizer);
    treap.insert(2, visualizer);
    treap.insert(3, visualizer);
    treap.insert(4, visualizer);
    treap.insert(5, visualizer);

    visualizer.run();
    return 0;
}
 