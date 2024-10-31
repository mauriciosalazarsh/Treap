//
// Created by mauri on 25/10/2024.
//

#include "TreapNode.h"
#include <random> // Incluye random para el generador de números aleatorios

#include "TreapNode.h"
#include <random> // Incluye random para el generador de números aleatorios

TreapNode::TreapNode(int key) : key(key), left(nullptr), right(nullptr) {
    // Configuración del generador de números aleatorios entre 0 y 1
    static std::random_device rd;    // Fuente de entropía
    static std::mt19937 gen(rd());   // Generador de números aleatorios basado en Mersenne Twister
    static std::uniform_real_distribution<> dis(0.0, 1.0); // Distribución entre 0 y 1

    this->priority = dis(gen); // Genera un valor entre 0 y 1 y lo asigna a la prioridad
}

