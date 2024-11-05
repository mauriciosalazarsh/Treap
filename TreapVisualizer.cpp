//
// Created by mauri on 25/10/2024.
//

#include "TreapVisualizer.h"
#include <string>

#include <chrono>
#include <thread>
#include <cmath> // Para la interpolación
#include <iostream>

TreapVisualizer::TreapVisualizer(Treap& treap)
    : treap(treap), window(sf::VideoMode(800, 600), "Treap Visualizer"),
      nextStepButton(700, 550, 80, 30, "Next Step") { // Cambia aquí el inicializador del botón
}



void TreapVisualizer::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawTree(treap.getRoot(), 400, 50, 200); // Usa el getter getRoot()
        window.display();
    }
}


void TreapVisualizer::drawTree(TreapNode* node, int x, int y, int offset) {
    if (!node) return;

    // Texto que se mostrará en el nodo (clave y prioridad)
    std::string text = std::to_string(node->key) + "\n(" + std::to_string(node->priority) + ")";
    drawNode(x, y, text, sf::Color::Green);


    // Dibujar la línea y el hijo izquierdo
    if (node->left) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x - offset, y + 100), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->left, x - offset, y + 100, offset / 2);
    }

    // Dibujar la línea y el hijo derecho
    if (node->right) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x + offset, y + 100), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->right, x + offset, y + 100, offset / 2);
    }
}


void TreapVisualizer::drawNode(int x, int y, const std::string& text, const sf::Color& color) {
    sf::CircleShape circle(30);
    circle.setFillColor(color); // Aplica el color de entrada
    circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
    window.draw(circle);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Manejo de error: fuente no encontrada
        return;
    }

    sf::Text nodeText(text, font, 14);
    nodeText.setFillColor(sf::Color::Black);
    nodeText.setPosition(x - 20, y - 20);
    window.draw(nodeText);
}


void TreapVisualizer::animateMove(TreapNode* node1, int startX1, int startY1, int endX1, int endY1,
                                  TreapNode* node2, int startX2, int startY2, int endX2, int endY2) {

    if (!node1 || !node2) {
        std::cerr << "Error: Puntero nulo en animateMove" << std::endl;
        return;
    }



    const int frames = 60; // Número de fotogramas para una animación suave
    for (int i = 0; i <= frames; ++i) {
        float t = static_cast<float>(i) / frames;

        // Interpolación lineal para ambos nodos
        int x1 = startX1 + static_cast<int>((endX1 - startX1) * t);
        int y1 = startY1 + static_cast<int>((endY1 - startY1) * t);
        int x2 = startX2 + static_cast<int>((endX2 - startX2) * t);
        int y2 = startY2 + static_cast<int>((endY2 - startY2) * t);

        window.clear(sf::Color::White);
        drawTree(treap.getRoot(), 400, 50, 200); // Dibuja el árbol completo

        // Dibuja los nodos en movimiento
        drawNode(x1, y1, std::to_string(node1->key) + "\n(" + std::to_string(node1->priority) + ")", sf::Color::Red);
        drawNode(x2, y2, std::to_string(node2->key) + "\n(" + std::to_string(node2->priority) + ")", sf::Color::Blue);

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Pausa entre frames
    }
}




void TreapVisualizer::drawStep() {
    window.clear(sf::Color::White);
    drawTree(treap.getRoot(), 400, 50, 200);
    nextStepButton.draw(window); // Dibuja el botón de "Next Step"
    window.display();
    waitForNextStep(); // Espera a que el usuario presione "Next Step"
}


void TreapVisualizer::waitForNextStep() {
    nextStepRequested = false;
    while (!nextStepRequested && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // Detecta si el botón de "Next Step" fue presionado
                if (nextStepButton.isClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    nextStepRequested = true;
                }
            }
        }

        // Dibuja el árbol y el botón "Next Step"
        window.clear(sf::Color::White);
        drawTree(treap.getRoot(), 400, 50, 200);
        nextStepButton.draw(window); // Dibuja el botón en la ventana
        window.display();
    }
}
