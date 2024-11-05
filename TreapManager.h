//
// Created by mauri on 25/10/2024.
//

#ifndef TREAPMANAGER_H
#define TREAPMANAGER_H

// TreapManager.h
#include "TreapVisualizer.h"

class TreapManager {
    Treap treap;
    TreapVisualizer visualizer; // Visualizador como miembro de TreapManager

public:
    TreapManager() : visualizer(treap) {} // Inicialización del visualizador con el Treap
    void run();
};


#endif
