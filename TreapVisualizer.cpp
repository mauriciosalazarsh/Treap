//
// Created by mauri on 25/10/2024.
//

#include "TreapVisualizer.h"
#include <string>

// Constructor de TreapVisualizer
TreapVisualizer::TreapVisualizer(Treap& treap)
        : treap(treap), window(sf::VideoMode(800, 600), "Treap Visualizer"),
          insertButton(50, 500, 100, 40, "Insert"),
          deleteButton(170, 500, 100, 40, "Delete"),
          searchButton(290, 500, 100, 40, "Search"),
          displayButton(410, 500, 100, 40, "Display"),
          clearTreeButton(530, 500, 100, 40, "Clear Tree") {}

// Función principal que ejecuta el visualizador en un bucle
void TreapVisualizer::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    handleMouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
        }

        window.clear(sf::Color::White);

        // Dibujar los botones en la ventana
        insertButton.draw(window);
        deleteButton.draw(window);
        searchButton.draw(window);
        displayButton.draw(window);
        clearTreeButton.draw(window);

        window.display();
    }
}

// Manejo de clics del ratón en los botones
void TreapVisualizer::handleMouseClick(const sf::Vector2f& mousePos) {
    if (insertButton.isClicked(mousePos)) {
        // Acción para "Insert"
    } else if (deleteButton.isClicked(mousePos)) {
        // Acción para "Delete"
    } else if (searchButton.isClicked(mousePos)) {
        // Acción para "Search"
    } else if (displayButton.isClicked(mousePos)) {
        // Acción para "Display"
    } else if (clearTreeButton.isClicked(mousePos)) {
        // Acción para "Clear Tree"
    }
}





















/*TreapVisualizer::TreapVisualizer(Treap& treap)
        : treap(treap), window(sf::VideoMode(800, 600), "Treap Visualizer") {}

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
    drawNode(x, y, text);

    // Dibujar la línea y el hijo izquierdo
    if (node->left) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y)),
                sf::Vertex(sf::Vector2f(x - offset, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->left, x - offset, y + 100, offset / 2);
    }

    // Dibujar la línea y el hijo derecho
    if (node->right) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y)),
                sf::Vertex(sf::Vector2f(x + offset, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        drawTree(node->right, x + offset, y + 100, offset / 2);
    }
}

void TreapVisualizer::drawNode(int x, int y, const std::string& text) {
    // Dibuja el círculo del nodo
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
    window.draw(circle);

    // Dibuja el texto dentro del nodo
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Manejo de error: fuente no encontrada
        return;
    }

    sf::Text nodeText(text, font, 14);
    nodeText.setFillColor(sf::Color::Black);
    nodeText.setPosition(x - 20, y - 20);
    window.draw(nodeText);
}*/
