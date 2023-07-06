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


## OpenGL Code README HOUSE

Este repositorio contiene un código de ejemplo que utiliza OpenGL para renderizar triángulos, líneas y puntos en una ventana de GLFW.

### Requisitos

- GLFW
- glad

### Compilación

1. Clona este repositorio.
2. Configura las dependencias de GLFW y glad.
3. Compila el código fuente usando un compilador compatible con OpenGL.

### Uso

1. Ejecuta el archivo binario generado después de la compilación.
2. Se abrirá una ventana de GLFW donde se mostrarán los triángulos, líneas y puntos.

### Atribuciones

- El código fuente de los shaders utilizados para los triángulos se encuentra en `SHADER TRIANGULOS`.
- El código fuente de los shaders utilizados para las líneas se encuentra en `SHADER LINEAS`.
- El código fuente de los shaders utilizados para los puntos se encuentra en `SHADER PUNTOS`.

### Estructura del Código Fuente

- `main.cpp`: Contiene el punto de entrada del programa.
- `framebuffer_size_callback()`: Función de devolución de llamada para el cambio de tamaño del framebuffer.
- `processInput()`: Función para procesar la entrada del usuario.
- `vertexShaderSource` y `fragmentShaderSource`: Código fuente de los shaders utilizados para los triángulos.
- `vertexShaderSourceLine` y `fragmentShaderSourceLine`: Código fuente de los shaders utilizados para las líneas.
- `vertexShaderSourcePoint` y `fragmentShaderSourcePoint`: Código fuente de los shaders utilizados para los puntos.



## OpenGL Script STAR

Este script es un ejemplo de cómo utilizar OpenGL para renderizar triángulos, líneas y puntos en una ventana de GLFW.

### Requisitos

- GLFW 3 (https://www.glfw.org/)
- GLAD (https://glad.dav1d.de/)

### Compilación

Para compilar el script, asegúrate de tener los requisitos mencionados anteriormente instalados y configurados correctamente. Luego, sigue estos pasos:

1. Compila el script con el siguiente comando:

    ```
    g++ script.cpp -o script -lglfw -ldl
    ```

2. Ejecuta el script resultante:

    ```
    ./script
    ```

### Descripción

El script muestra cómo utilizar los shaders de vértices y fragmentos para renderizar triángulos, líneas y puntos en una ventana de GLFW.

#### Shaders

El script contiene tres shaders diferentes: uno para los triángulos, otro para las líneas y otro para los puntos. Estos shaders se definen en las siguientes variables:

- Shader de triángulos:

  - Vertex shader: `vertexShaderSource`
  - Fragment shader: `fragmentShaderSource`

- Shader de líneas:

  - Vertex shader: `vertexShaderSourceLine`
  - Fragment shader: `fragmentShaderSourceLine`

- Shader de puntos:

  - Vertex shader: `vertexShaderSourcePoint`
  - Fragment shader: `fragmentShaderSourcePoint`

#### Configuración

El script utiliza GLFW para inicializar y configurar la ventana de renderizado. El tamaño de la ventana se establece en las siguientes constantes:

- Ancho de la ventana: `SCR_WIDTH`
- Altura de la ventana: `SCR_HEIGHT`

#### Renderizado

El script utiliza el bucle principal para renderizar los objetos en la ventana de GLFW. Renderiza un conjunto de triángulos utilizando el shader de triángulos y otro conjunto de líneas utilizando el shader de líneas.

Los vértices y los índices para los triángulos y las líneas se definen en las siguientes variables:

- Triángulos:
  - Vértices: `vertices`
  - Índices: `indices`

- Líneas:
  - Vértices: `verticesLINE`
  - Índices: `indicesLINE`

#### Compilación y enlace de shaders

El script compila y enlaza los shaders utilizando las funciones de OpenGL. Comprueba los errores de compilación y enlace y muestra mensajes de error si es necesario.


## Créditos

Este código fue desarrollado por Cristhian Ocola y Carlos Morales.

¡Disfruta explorando y experimentando con el código de OpenGL!



