#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& label, const sf::Font& font, const std::string& texturePath, sf::Color textColor)
    : position(x, y), size(width, height), label(label), font(font), isPressed(false) {

    // Cargar la textura del botón
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Error: No se pudo cargar la textura del botón");
    }

    // Configurar el sprite (tamaño grande y centrado)
    sprite.setTexture(texture);
    sprite.setPosition(position);
    float scaleFactor = 2; // Botón grande (escalado 2x)
    sprite.setScale((size.x / texture.getSize().x) * scaleFactor, (size.y / texture.getSize().y) * scaleFactor);
}

void Button::render(sf::RenderWindow& window) {
    if (isPressed) {
        sprite.setColor(sf::Color(200, 200, 200)); // Color más claro al presionar
    } else {
        sprite.setColor(sf::Color::White); // Color normal
    }
    window.draw(sprite); // Dibujar el rectángulo del botón
}

bool Button::isClicked(const sf::RenderWindow& window, const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            isPressed = true; // Cambia el estado a presionado
            return false;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && isPressed) {
        isPressed = false; // Cambia el estado a no presionado
        return true;
    }
    return false;
}

