//
// Created by mauri on 25/10/2024.
//

#ifndef TREAP_TREAP_H
#define TREAP_TREAP_H

#include "TreapNode.h"
#include <vector>
#include <utility> // Para std::pair

class Treap {
private:
    TreapNode* root;

    TreapNode* rotateRight(TreapNode* node);
    TreapNode* rotateLeft(TreapNode* node);
    TreapNode* insert(TreapNode* node, int key);
    TreapNode* deleteNode(TreapNode* node, int key);
    TreapNode* search(TreapNode* node, int key);

    // Modifica inorder para almacenar pares (key, priority)
    void inorder(TreapNode* node, std::vector<std::pair<int, double>>& result);

    void clearTree(TreapNode* node);

public:
public:
    Treap();
    ~Treap();

    // Nuevo método para obtener el nodo raíz
    TreapNode* getRoot() const;

    void insert(int key);
    void deleteNode(int key);
    bool search(int key);
    std::vector<std::pair<int, double>> getInorderList();
    void clear();

};

#endif //TREAP_TREAP_H
