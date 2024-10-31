//
// Created by mauri on 25/10/2024.
//

#ifndef TREAP_TREAPNODE_H
#define TREAP_TREAPNODE_H

class TreapNode {
public:
    int key;
    double priority;
    TreapNode *left;
    TreapNode *right;
    TreapNode(int key);
};

#endif //TREAP_TREAPNODE_H
