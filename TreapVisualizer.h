//
// Created by mauri on 25/10/2024.
//

#ifndef TREAPVISUALIZER_H
#define TREAPVISUALIZER_H

#include <SFML/Graphics.hpp>
#include "Treap.h"
#include "Button.h"

#include "Button.h"
// Otros includes...

class TreapVisualizer {
public:
    TreapVisualizer(Treap& treap);
    void run();

private:
    Treap& treap;
    sf::RenderWindow window;

    // Botones
    Button insertButton;
    Button deleteButton;
    Button searchButton;
    Button displayButton;
    Button clearTreeButton;

    void handleMouseClick(const sf::Vector2f& mousePos);
};













/*class TreapVisualizer {
public:
    TreapVisualizer(Treap& treap);
    void run();

private:
    Treap& treap;
    sf::RenderWindow window;

    void drawTree(TreapNode* node, int x, int y, int offset);
    void drawNode(int x, int y, const std::string& text);
};*/

#endif

