// Treap.h
#ifndef TREAP_TREAP_H
#define TREAP_TREAP_H

#include "TreapNode.h"
#include <vector>
#include <utility> // Para std::pair

class TreapVisualizer; // Declaración adelantada

class Treap {
private:
    TreapNode* root;
    TreapVisualizer* visualizer;

    TreapNode* insert(TreapNode* node, int key, TreapVisualizer& visualizer); // Asegúrate de que este tenga 3 parámetros
    TreapNode* deleteNode(TreapNode* node, int key);
    TreapNode* search(TreapNode* node, int key);

    // Modifica inorder para almacenar pares (key, priority)
    void inorder(TreapNode* node, std::vector<std::pair<int, double>>& result);

    void clearTree(TreapNode* node);

public:
    Treap();
    ~Treap();

    void setVisualizer(TreapVisualizer* vis) { visualizer = vis; }
    TreapNode* getRoot() const;

    void insert(int key, TreapVisualizer& visualizer); // Asegúrate de que tenga 2 parámetros
    void deleteNode(int key);
    bool search(int key);
    std::vector<std::pair<int, double>> getInorderList();
    void clear();
    TreapNode* rotateRight(TreapNode* node);
    TreapNode* rotateLeft(TreapNode* node);

};

#endif // TREAP_TREAP_H