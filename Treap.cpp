//
// Created by mauri on 25/10/2024.
//

#include "Treap.h"
#include "TreapVisualizer.h" // Asegúrate de incluir esto para la definición completa
#include <iostream>

Treap::Treap() : root(nullptr) {}

// Destructor que llama a clear para liberar memoria al finalizar
Treap::~Treap() {
    clear();
}

void Treap::clearTree(TreapNode* node) {
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

// Función pública clear que llama a clearTree y establece la raíz en nullptr
void Treap::clear() {
    clearTree(root);
    root = nullptr;
}

TreapNode* Treap::rotateRight(TreapNode* node) {
    if (!node || !node->left) return node; // Asegúrate de que node y node->left sean válidos
    TreapNode* leftChild = node->left;

    // Coordenadas actuales y de destino para el nodo y su hijo izquierdo
    int parentX = 400, parentY = 50;         // Ajusta la posición del padre
    int leftChildX = 300, leftChildY = 100;   // Ajusta la posición del hijo izquierdo

    // Solo llama a animateMove si ambos nodos son válidos
    if (node && leftChild) {
        visualizer->animateMove(leftChild, leftChildX, leftChildY, parentX, parentY,
                                node, parentX, parentY, leftChildX, leftChildY);
    }

    // Actualiza las conexiones en el árbol
    node->left = leftChild->right;
    leftChild->right = node;

    // Dibuja la estructura actualizada final
    visualizer->drawStep();

    return leftChild;
}



TreapNode* Treap::rotateLeft(TreapNode* node) {
    if (!node || !node->right) return node;
    TreapNode* rightChild = node->right;

    // Coordenadas actuales y de destino para el nodo y su hijo derecho
    int parentX = 400, parentY = 50;         // Ajusta la posición del padre (5)
    int rightChildX = 500, rightChildY = 100; // Ajusta la posición del hijo derecho (nueva posición de 5)

    // Paso 1: Mover el hijo derecho a la posición del padre
    visualizer->animateMove(rightChild, rightChildX, rightChildY, parentX, parentY, node, parentX, parentY, rightChildX, rightChildY);

    // Actualiza las conexiones en el árbol
    node->right = rightChild->left;
    rightChild->left = node;

    // Paso 2: Mover el nodo padre (5) a la posición de nuevo hijo izquierdo
    visualizer->animateMove(node, parentX, parentY, rightChildX, rightChildY, nullptr, 0, 0, 0, 0); // Solo mueve el padre

    // Paso 3: Dibuja la estructura actualizada final
    visualizer->drawStep(); // Dibuja el árbol completo en su nueva estructura

    return rightChild;
}



TreapNode* Treap::insert(TreapNode* node, int key, TreapVisualizer& visualizer) {
    if (!node) {
        auto* newNode = new TreapNode(key);
        visualizer.drawStep(); // Mostrar el nodo recién insertado
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key, visualizer);
        if (node->left && node->left->priority > node->priority) {
            node = rotateRight(node);
            visualizer.drawStep(); // Mostrar después de la rotación
        }
    } else {
        node->right = insert(node->right, key, visualizer);
        if (node->right && node->right->priority > node->priority) {
            node = rotateLeft(node);
            visualizer.drawStep(); // Mostrar después de la rotación
        }
    }
    return node;
}


// En Treap.cpp
void Treap::insert(int key, TreapVisualizer& visualizer) {
    root = insert(root, key, visualizer);
}



TreapNode* Treap::deleteNode(TreapNode* node, int key) {
    if (!node) return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (!node->left) node = node->right;
        else if (!node->right) node = node->left;
        else if (node->left->priority < node->right->priority) {
            node = rotateLeft(node);
            node->left = deleteNode(node->left, key);
        } else {
            node = rotateRight(node);
            node->right = deleteNode(node->right, key);
        }
    }
    return node;
}

void Treap::deleteNode(int key) {
    root = deleteNode(root, key);
}

TreapNode* Treap::search(TreapNode* node, int key) {
    if (!node || node->key == key) return node;

    if (key < node->key) return search(node->left, key);
    else return search(node->right, key);
}

bool Treap::search(int key) {
    return search(root, key) != nullptr;
}


void Treap::inorder(TreapNode* node, std::vector<std::pair<int, double>>& result) {
    if (node) {
        inorder(node->left, result);
        result.push_back({node->key, node->priority}); // Agrega (key, priority) al vector
        inorder(node->right, result);
    }
}

std::vector<std::pair<int, double>> Treap::getInorderList() {
    std::vector<std::pair<int, double>> result;
    inorder(root, result);
    return result;
}

TreapNode* Treap::getRoot() const {
    return root;
}
