#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    bool isPressed; // Estado del botón (si está presionado o no)
    sf::Vector2f position;          // Posición del botón
    sf::Vector2f size;              // Tamaño del botón
    std::string label;              // Texto del botón
    sf::Text text;                  // Texto que se muestra en el botón
    const sf::Font& font;           // Referencia a la fuente utilizada
    sf::Texture texture;            // Textura del botón
    sf::Sprite sprite;              // Sprite para mostrar la textura

public:
    // Constructor con textura
    Button(float x, float y, float width, float height, const std::string& label, const sf::Font& font, const std::string& texturePath, sf::Color textColor);

    Button(float x, float y, float width, float height, const std::string &label, const sf::Font &font,
           const std::string &texturePath);

    // Método para renderizar el botón
    void render(sf::RenderWindow& window);

    bool isClicked(const sf::RenderWindow &window, const sf::Event &event);

    // Verificar si se hizo clic en el botón
    bool isClicked(const sf::RenderWindow& window, const sf::Event& event) const;
};

#endif // BUTTON_H
