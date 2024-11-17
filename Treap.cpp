#include "Treap.h"
#include "TreapVisualizer.h"
#include <iostream>

Treap::Treap() : root(nullptr), visualizer(nullptr) {}

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

void Treap::clear() {
    clearTree(root);
    root = nullptr;
}

TreapNode* Treap::rotateRight(TreapNode* node) {
    if (!node || !node->left) return node;

    TreapNode* leftChild = node->left;

    // Mostrar el estado antes de la rotación
    if (visualizer) {
        visualizer->setMessage("Preparando rotacion derecha en Nodo: " + std::to_string(node->key));
        visualizer->drawStep(root); // Dibuja el estado actual del árbol
    }

    node->left = leftChild->right;
    leftChild->right = node;

    // Mostrar el estado después de la rotación
    if (visualizer) {
        visualizer->setMessage("Rotacion derecha completada en Nodo: " + std::to_string(leftChild->key));
        visualizer->drawStep(root);
    }

    return leftChild;
}

TreapNode* Treap::rotateLeft(TreapNode* node) {
    if (!node || !node->right) return node;

    TreapNode* rightChild = node->right;

    // Mostrar el estado antes de la rotación
    if (visualizer) {
        visualizer->setMessage("Preparando rotacion izquierda en Nodo: " + std::to_string(node->key));
        visualizer->drawStep(root); // Dibuja el estado actual del árbol
    }

    node->right = rightChild->left;
    rightChild->left = node;

    // Mostrar el estado después de la rotación
    if (visualizer) {
        visualizer->setMessage("Rotacion izquierda completada en Nodo: " + std::to_string(rightChild->key));
        visualizer->drawStep(root);
    }

    return rightChild;
}

TreapNode* Treap::insert(TreapNode* node, int key, TreapVisualizer& visualizer) {
    if (!node) {
        auto* newNode = new TreapNode(key);
        visualizer.setMessage("Insertando nodo: " + std::to_string(key));
        visualizer.drawStep(root); // Dibuja el árbol después de insertar
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key, visualizer);
        if (node->left && node->left->priority > node->priority) {
            visualizer.setMessage("Preparando rotacion derecha en Nodo: " + std::to_string(node->key));
            visualizer.drawStep(root); // Mostrar antes de la rotación
            node = rotateRight(node);
        }
    } else {
        node->right = insert(node->right, key, visualizer);
        if (node->right && node->right->priority > node->priority) {
            visualizer.setMessage("Preparando rotacion izquierda en Nodo: " + std::to_string(node->key));
            visualizer.drawStep(root); // Mostrar antes de la rotación
            node = rotateLeft(node);
        }
    }

    visualizer.drawStep(root); // Dibuja el estado final después de la inserción
    return node;
}


void Treap::insert(int key, TreapVisualizer& visualizer) {
    root = insert(root, key, visualizer);
}

TreapNode* Treap::deleteNode(TreapNode* node, int key) {
    if (!node) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (!node->left) {
            node = node->right;
        } else if (!node->right) {
            node = node->left;
        } else if (node->left->priority < node->right->priority) {
            visualizer->setMessage("Preparando rotacion izquierda para eliminar Nodo: " + std::to_string(key));
            visualizer->drawStep(root); // Mostrar antes de la rotación
            node = rotateLeft(node);
            node->left = deleteNode(node->left, key);
        } else {
            visualizer->setMessage("Preparando rotacion derecha para eliminar Nodo: " + std::to_string(key));
            visualizer->drawStep(root); // Mostrar antes de la rotación
            node = rotateRight(node);
            node->right = deleteNode(node->right, key);
        }
    }

    visualizer->setMessage("Nodo eliminado: " + std::to_string(key));
    visualizer->drawStep(root); // Mostrar después de la eliminación
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
        result.push_back({node->key, node->priority});
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
