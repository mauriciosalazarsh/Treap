//
// Created by mauri on 25/10/2024.
//

#ifndef TREAPVISUALIZER_H
#define TREAPVISUALIZER_H

#include <SFML/Graphics.hpp>
#include "Treap.h"
#include "Button.h" // Asume que tienes una clase Button implementada

class TreapVisualizer {
public:
    TreapVisualizer(Treap& treap);
    void run();
    void drawStep();
    void animateMove(TreapNode* node1, int startX1, int startY1, int endX1, int endY1,
                 TreapNode* node2, int startX2, int startY2, int endX2, int endY2);

    void animateRotation(TreapNode* parent, int parentStartX, int parentStartY,
                     TreapNode* child, int childStartX, int childStartY,
                     int childEndX, int childEndY, int parentEndX, int parentEndY);



private:
    Treap& treap;
    sf::RenderWindow window;
    Button nextStepButton; // Botón de "Next Step"

    bool nextStepRequested = false; // Bandera para verificar si se solicitó el siguiente paso

    void drawTree(TreapNode* node, int x, int y, int offset);
    void drawNode(int x, int y, const std::string& text, const sf::Color& color);
    void waitForNextStep(); // Espera hasta que se haga clic en "Next Step"
};

#endif
