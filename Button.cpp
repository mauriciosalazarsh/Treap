//
// Created by mauri on 25/10/2024.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& text) {
    buttonShape.setPosition(x, y);
    buttonShape.setSize({width, height});
    buttonShape.setFillColor(sf::Color::Blue);

    if (!font.loadFromFile("arial.ttf")) { // Asegúrate de tener la fuente en el mismo directorio
        // Manejo de error en caso de que la fuente no se cargue
    }

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);

    // Centra el texto en el botón
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setPosition(
            x + (width - textBounds.width) / 2,
            y + (height - textBounds.height) / 2 - 5
    );
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Vector2f& mousePos) const {
    return buttonShape.getGlobalBounds().contains(mousePos);
}
