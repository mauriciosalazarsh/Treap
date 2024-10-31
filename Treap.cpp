//
// Created by mauri on 25/10/2024.
//

#include "Treap.h"
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
    TreapNode* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    return leftChild;
}

TreapNode* Treap::rotateLeft(TreapNode* node) {
    TreapNode* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}

TreapNode* Treap::insert(TreapNode* node, int key) {
    if (!node) return new TreapNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
        if (node->left && node->left->priority > node->priority)
            node = rotateRight(node);
    } else {
        node->right = insert(node->right, key);
        if (node->right && node->right->priority > node->priority)
            node = rotateLeft(node);
    }
    return node;
}

void Treap::insert(int key) {
    root = insert(root, key);
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

