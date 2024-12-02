# Treap Visualizer Project

Este proyecto implementa un visualizador de estructuras Treap usando SFML. Sigue las instrucciones a continuación para descargar las dependencias necesarias y configurar el entorno.

---

## Requisitos

- [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
- Un compilador compatible con C++11 o superior (por ejemplo, GCC o Clang)
- [CMake](https://cmake.org/) (para construir el proyecto)
- Un IDE como CLion (opcional, pero recomendado)

---

## Instrucciones para descargar y configurar SFML

1. **Descargar SFML:**
   - Dirígete al sitio oficial de [SFML](https://www.sfml-dev.org/download.php).
   - Descarga la versión adecuada para tu sistema operativo y compilador.

2. **Ubicar SFML en el directorio `C:\`:**
   - Descomprime el archivo descargado.
   - Mueve la carpeta descomprimida de SFML al directorio raíz `C:\` de tu sistema. 
   - Por ejemplo, después de moverla, deberías tener una estructura como:  
     ```
     C:\SFML\include
     C:\SFML\lib
     ```

3. **Configurar SFML en tu proyecto (CMake):**
   - Asegúrate de que las rutas de `SFML_DIR` en el archivo `CMakeLists.txt` apunten correctamente a `C:\SFML`.
   - Verifica que las librerías necesarias (`sfml-graphics`, `sfml-window`, `sfml-system`) estén vinculadas.

---

## Configuración de archivos del proyecto

1. **Archivos en `ArchivosCmakeBuild`:**
   - Copia todos los archivos dentro de la carpeta `ArchivosCmakeBuild` al directorio `cmake-build-debug` que se genera automáticamente al compilar el proyecto en tu IDE (por ejemplo, CLion).

     ```bash
     cp -r ArchivosCmakeBuild/* cmake-build-debug/
     ```

2. **Archivos en `images`:**
   - Similarmente, copia la carpeta `images` al mismo directorio `cmake-build-debug`:

     ```bash
     cp -r images/ cmake-build-debug/
     ```

---

## Compilación y ejecución

1. **Configurar el proyecto con CMake:**
   - Abre tu IDE (como CLion) y selecciona el archivo `CMakeLists.txt` para cargar el proyecto.
   - Si estás trabajando desde la terminal, ejecuta los siguientes comandos:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

2. **Ejecutar el programa:**
   - Una vez compilado, ejecuta el binario generado desde `cmake-build-debug` o la carpeta `build`:
     ```bash
     ./TreapVisualizer
     ```

---

## Notas importantes

- Asegúrate de que la carpeta `SFML` está ubicada en `C:\`.
- Verifica que las rutas a los archivos en `ArchivosCmakeBuild` e `images` coincidan con las indicadas en este README.
- Si tienes problemas para compilar o ejecutar, confirma que las librerías y archivos necesarios están en sus lugares correctos.

---

¡Eso es todo! Ahora deberías poder ejecutar el visualizador Treap correctamente.
