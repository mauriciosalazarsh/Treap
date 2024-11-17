#include "TreapVisualizer.h"
#include <cmath>
#include <iostream>
#include <iomanip> // Para usar std::ostringstream
#include <sstream>


TreapVisualizer::TreapVisualizer(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title),
nextStepButton(-5, 30, 150, 50, "Next Step", font, "rectangle.png", sf::Color::Black)

{
    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Error: No se pudo cargar la fuente");
    }

    if (!nodeTexture.loadFromFile("node.png")) {
        throw std::runtime_error("Error: No se pudo cargar la textura del nodo");
    }

    message.setFont(font);
    message.setCharacterSize(24);
    message.setFillColor(sf::Color::Black);
    message.setPosition(10, 10);
}



void TreapVisualizer::setMessage(const std::string& msg) {
    message.setString(msg);
}

void TreapVisualizer::drawStep(TreapNode* root) {
    // Limpia la ventana
    window.clear(sf::Color::White);

    // Dibuja el mensaje actual
    window.draw(message);

    // Dibuja el árbol
    if (root) {
        drawTree(root, window.getSize().x / 2, 100, window.getSize().x / 4);
    }

    // Dibuja el botón
    nextStepButton.render(window);

    // Muestra los cambios
    window.display();

    // Espera interacción
    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }

            if (nextStepButton.isClicked(window, event)) {
                return; // Continuar al siguiente paso
            }
        }
    }
}




void TreapVisualizer::drawTree(TreapNode* node, float x, float y, float offset) {
    if (!node) return;

    // Dibuja el nodo actual
    drawNode(node, x, y);

    // Dibuja la conexión al hijo izquierdo
    if (node->left) {
        drawEdge(node, node->left, x, y, x - offset, y + 100);
        drawTree(node->left, x - offset, y + 100, offset / 2);
    }

    // Dibuja la conexión al hijo derecho
    if (node->right) {
        drawEdge(node, node->right, x, y, x + offset, y + 100);
        drawTree(node->right, x + offset, y + 100, offset / 2);
    }
}


void TreapVisualizer::drawNode(TreapNode* node, float x, float y) {
    if (!node) return;

    // Crear el sprite del nodo
    sf::Sprite sprite;
    sprite.setTexture(nodeTexture); // Asignar la textura cargada
    sprite.setOrigin(nodeTexture.getSize().x / 2.0f, nodeTexture.getSize().y / 2.0f); // Centrar el sprite
    sprite.setPosition(x, y); // Posicionar el sprite en la ubicación del nodo

    // Escalar el sprite para que sea más pequeño
    sprite.setScale(0.1, 0.1); // Ajusta los valores para el tamaño deseado

    // Crear el texto con clave y prioridad
    std::ostringstream oss;
    oss <<  "   " << node->key << std::endl << "(" << std::fixed << std::setprecision(3) << node->priority << ")";
    sf::Text text;
    text.setFont(font);
    text.setString(oss.str());
    text.setCharacterSize(18); // Ajusta el tamaño del texto según el nodo
    text.setFillColor(sf::Color::Black);

    // Centrar el texto dentro del nodo
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    text.setPosition(x, y);

    // Dibujar el sprite y el texto
    window.draw(sprite);
    window.draw(text);
}


void TreapVisualizer::drawEdge(TreapNode* parent, TreapNode* child, float x1, float y1, float x2, float y2) {
    float nodeRadius = 40; // Radio del nodo (mismo que en drawNode)

    sf::VertexArray edge(sf::Lines, 2);
    edge[0].position = sf::Vector2f(x1, y1 + nodeRadius); // Parte inferior del nodo padre
    edge[1].position = sf::Vector2f(x2, y2 - nodeRadius); // Parte superior del nodo hijo
    edge[0].color = edge[1].color = sf::Color::Black;

    // Dibujar la línea
    window.draw(edge);
}




void TreapVisualizer::visualizeTreap(Treap* treap) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Renderizar el árbol
        window.clear(sf::Color::White);
        if (treap->getRoot()) {
            drawTree(treap->getRoot(), window.getSize().x / 2, 100, window.getSize().x / 4);
        }
        window.draw(message);
        window.display();
    }
}
