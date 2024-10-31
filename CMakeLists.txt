cmake_minimum_required(VERSION 3.28)
project(Treap)

set(CMAKE_CXX_STANDARD 17)

# Ruta de SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Agregar el ejecutable
add_executable(Treap main.cpp
        TreapNode.h
        TreapNode.cpp
        Treap.h
        Treap.cpp
        TreapManager.h
        TreapManager.cpp
        TreapVisualizer.h
        TreapVisualizer.cpp
        Button.h
        Button.cpp)

# Enlazar las bibliotecas de SFML
target_link_libraries(Treap sfml-graphics sfml-window sfml-system)