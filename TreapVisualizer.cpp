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

    // Configuración del botón "Insertar"
    insertButton.setSize(sf::Vector2f(100, 50));
    insertButton.setFillColor(sf::Color::Green);
    insertButton.setOutlineColor(sf::Color::Black);
    insertButton.setOutlineThickness(2);
    insertButton.setPosition(window.getSize().x - 340, window.getSize().y - 70); // A la izquierda del input box

    insertButtonText.setFont(font);
    insertButtonText.setString("Insertar");
    insertButtonText.setCharacterSize(20);
    insertButtonText.setFillColor(sf::Color::Black);
    insertButtonText.setPosition(window.getSize().x - 330, window.getSize().y - 60); // Centrado dentro del botón

    // Configuración del botón "Eliminar"
    deleteButton.setSize(sf::Vector2f(100, 50));
    deleteButton.setFillColor(sf::Color::Red);
    deleteButton.setOutlineColor(sf::Color::Black);
    deleteButton.setOutlineThickness(2);
    deleteButton.setPosition(window.getSize().x - 460, window.getSize().y - 70); // A la izquierda del botón "Insertar"

    deleteButtonText.setFont(font);
    deleteButtonText.setString("Eliminar");
    deleteButtonText.setCharacterSize(20);
    deleteButtonText.setFillColor(sf::Color::Black);
    deleteButtonText.setPosition(window.getSize().x - 450, window.getSize().y - 60); // Centrado dentro del botón

    // Configuración del botón "Buscar"
    searchButton.setSize(sf::Vector2f(100, 50));
    searchButton.setFillColor(sf::Color::Yellow);
    searchButton.setOutlineColor(sf::Color::Black);
    searchButton.setOutlineThickness(2);
    searchButton.setPosition(window.getSize().x - 580, window.getSize().y - 70); // A la izquierda del botón "Eliminar"

    searchButtonText.setFont(font);
    searchButtonText.setString("Buscar");
    searchButtonText.setCharacterSize(20);
    searchButtonText.setFillColor(sf::Color::Black);
    searchButtonText.setPosition(window.getSize().x - 570, window.getSize().y - 60); // Centrado dentro del botón


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
    std::string inputText;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Detectar clic en la caja de entrada
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Verificar si el clic fue en la caja de entrada
                sf::FloatRect inputBoxBounds(window.getSize().x - 220, window.getSize().y - 70, 200, 50);
                if (inputBoxBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    isInputBoxActive = true;
                } else {
                    isInputBoxActive = false;
                }

                // Verificar si el clic fue en el botón "Insertar"
                sf::FloatRect insertButtonBounds = insertButton.getGlobalBounds();
                if (insertButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    if (!inputText.empty()) {
                        int value = std::stoi(inputText);
                        treap->insert(value, *this); // Insertar el nodo en el Treap
                        inputText.clear(); // Limpiar la caja de entrada
                    }
                }

                // Verificar si el clic fue en el botón "Eliminar"
                sf::FloatRect deleteButtonBounds = deleteButton.getGlobalBounds();
                if (deleteButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    if (!inputText.empty()) {
                        int value = std::stoi(inputText);
                        treap->deleteNode(value); // Eliminar el nodo del Treap
                        inputText.clear(); // Limpiar la caja de entrada
                    }
                }

                // Verificar si el clic fue en el botón "Buscar"
                sf::FloatRect searchButtonBounds = searchButton.getGlobalBounds();
                if (searchButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    if (!inputText.empty()) {
                        int value = std::stoi(inputText);
                        if (treap->search(value)) {
                            setMessage("Nodo encontrado: " + std::to_string(value)); // Mostrar mensaje
                        } else {
                            setMessage("Nodo no encontrado: " + std::to_string(value)); // Mostrar mensaje
                        }
                        inputText.clear(); // Limpiar la caja de entrada
                    }
                }
            }

            // Manejar entrada de texto si la caja está activa
            if (isInputBoxActive && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !inputText.empty()) {
                    inputText.pop_back(); // Retroceso
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    inputText += static_cast<char>(event.text.unicode); // Solo agregar números
                }
            }
        }

        // Limpiar la ventana
        window.clear(sf::Color::White);

        // Dibujar la caja de entrada
        sf::RectangleShape inputBox(sf::Vector2f(200, 50));
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineColor(isInputBoxActive ? sf::Color::Blue : sf::Color::Black);
        inputBox.setOutlineThickness(2);
        inputBox.setPosition(window.getSize().x - 220, window.getSize().y - 70);
        window.draw(inputBox);

        // Dibujar el texto dentro de la caja
        sf::Text inputTextDisplay;
        inputTextDisplay.setFont(font);
        inputTextDisplay.setCharacterSize(24);
        inputTextDisplay.setFillColor(sf::Color::Black);
        inputTextDisplay.setPosition(window.getSize().x - 210, window.getSize().y - 60);
        inputTextDisplay.setString(inputText.empty() ? "Enter number" : inputText);
        window.draw(inputTextDisplay);

        // Dibujar el botón "Insertar"
        window.draw(insertButton);
        window.draw(insertButtonText);

        // Dibujar el botón "Eliminar"
        window.draw(deleteButton);
        window.draw(deleteButtonText);

        // Dibujar el botón "Buscar"
        window.draw(searchButton);
        window.draw(searchButtonText);

        // Dibujar el árbol si existe
        if (treap->getRoot()) {
            drawTree(treap->getRoot(), window.getSize().x / 2, 100, window.getSize().x / 4);
        }

        // Dibujar mensaje
        window.draw(message);

        // Mostrar cambios
        window.display();
    }
}






void TreapVisualizer::drawInputBox(sf::RenderWindow& window, sf::Font& font, std::string& inputText) {
    // Crear el rectángulo para la caja de entrada
    sf::RectangleShape inputBox(sf::Vector2f(200, 50)); // Tamaño del cuadro
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(window.getSize().x - 220, 20); // Esquina superior derecha

    // Crear el texto dentro del cuadro
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(window.getSize().x - 210, 30); // Margen dentro del cuadro
    text.setString(inputText.empty() ? "Enter number" : inputText); // Mostrar texto o placeholder

    // Dibujar el cuadro y el texto
    window.draw(inputBox);
    window.draw(text);
}

void TreapVisualizer::handleInput(sf::RenderWindow& window, sf::Event& event, std::string& inputText) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !inputText.empty()) { // Manejar retroceso
            inputText.pop_back();
        } else if (std::isdigit(event.text.unicode)) { // Solo aceptar números
            inputText += static_cast<char>(event.text.unicode);
        }
    }
}


void TreapVisualizer::handleTextInput(sf::Event event, std::string& inputText) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !inputText.empty()) {
            // Eliminar el último carácter si se presiona retroceso
            inputText.pop_back();
        } else if (std::isprint(event.text.unicode)) {
            // Agregar solo caracteres imprimibles
            inputText += static_cast<char>(event.text.unicode);
        }
    }
}

void TreapVisualizer::drawInputBox(sf::RenderWindow& window, sf::Font& font, const std::string& inputText) {
    // Crear el rectángulo para la caja de entrada
    sf::RectangleShape inputBox(sf::Vector2f(200, 50));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(window.getSize().x - 220, window.getSize().y - 70); // Esquina inferior derecha
    window.draw(inputBox);

    // Crear el texto dentro de la caja
    sf::Text textDisplay;
    textDisplay.setFont(font);
    textDisplay.setString(inputText.empty() ? "Enter text..." : inputText);
    textDisplay.setCharacterSize(24);
    textDisplay.setFillColor(sf::Color::Black);
    textDisplay.setPosition(window.getSize().x - 210, window.getSize().y - 60); // Margen dentro del cuadro
    window.draw(textDisplay);
}
