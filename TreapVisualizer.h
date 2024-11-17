#ifndef TREAPVISUALIZER_H
#define TREAPVISUALIZER_H

#include "Treap.h"
#include "Button.h" // Incluimos la clase Button
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TreapVisualizer {
private:

    sf::RenderWindow window;
    sf::Font font;
    sf::Text message;
    Button nextStepButton; // Botón "Next Step" para avanzar de paso en paso
    std::map<TreapNode*, sf::CircleShape> nodeShapes;
    std::map<std::pair<TreapNode*, TreapNode*>, sf::VertexArray> edges;
    sf::Texture nodeTexture; // Textura para los nodos

    void drawNode(TreapNode* node, float x, float y);
    void drawEdge(TreapNode* parent, TreapNode* child, float x1, float y1, float x2, float y2);
    void drawTree(TreapNode* node, float x, float y, float offset);

public:
    TreapVisualizer(int width, int height, const std::string& title);
    void setMessage(const std::string& msg);
    void drawStep(TreapNode* root);
    void visualizeTreap(Treap* treap);
};

#endif
