//
// Created by mauri on 25/10/2024.
//

#ifndef TREAP_BUTTON_H
#define TREAP_BUTTON_H


#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2f& mousePos) const;

private:
    sf::RectangleShape shape;
    sf::Text label;
    sf::Font font; // Asegúrate de cargar una fuente en el constructor
};



#endif //TREAP_BUTTON_H
