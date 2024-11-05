//
// Created by mauri on 25/10/2024.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& text) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Blue);

    if (!font.loadFromFile("arial.ttf")) {
        // Maneja el error si la fuente no se carga
    }

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(14);
    label.setFillColor(sf::Color::White);
    label.setPosition(x + 10, y + 5); // Ajusta según el tamaño del botón
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(const sf::Vector2f& mousePos) const {
    return shape.getGlobalBounds().contains(mousePos);
}

