# Graphics_OPENGL
Homeworks &amp; tasks lab´s

## OpenGL Code Explanation CIRCLE

Este repositorio contiene un código de ejemplo que utiliza OpenGL para renderizar y mostrar diferentes formas geométricas en una ventana de GLFW.

### Requisitos

Para ejecutar este código, debes tener instaladas las siguientes bibliotecas:

- OpenGL
- GLFW

### Instrucciones

Sigue estos pasos para ejecutar el código:

1. Clona el repositorio en tu máquina local.
2. Compila el código usando un compilador compatible con C++ y las bibliotecas OpenGL.
3. Ejecuta el programa resultante.

### Descripción del código

El código consta de los siguientes componentes principales:

- Configuración y creación de la ventana GLFW.
- Carga de las funciones de OpenGL utilizando la biblioteca GLAD.
- Definición de shaders para dibujar diferentes formas geométricas (triángulos, líneas y puntos).
- Configuración de los datos de vértices y atributos para cada forma geométrica.
- Compilación y enlace de los shaders.
- Renderizado de las formas geométricas utilizando los shaders y los datos de vértices correspondientes.

El código está organizado de manera que se dibujan tres formas geométricas diferentes:

1. Triángulos: Se utiliza un shader de vértices y un shader de fragmentos para dibujar triángulos de color naranja.

2. Líneas: Se utiliza un shader de vértices y un shader de fragmentos para dibujar una línea blanca alrededor de un círculo formado por múltiples segmentos.

3. Puntos: Se utiliza un shader de vértices y un shader de fragmentos para dibujar puntos rojos en los vértices de un círculo formado por múltiples segmentos.

### Créditos

Este código fue desarrollado por Cristhian Ocola y Carlos Morales.

¡Disfruta explorando y experimentando con el código de OpenGL!
