# README: Explicación del código

# Importa las librerías necesarias
import math

# Definición de constantes
WIDTH = 40
HEIGHT = 40

# Definición de la clase 'primeros_puntos'
class primeros_puntos:
    def __init__(self, _x, _y, _z):
        self.x = _x
        self.y = _y
        self.z = _z

    # Sobrecarga del operador '-' para realizar la resta de puntos
    def __sub__(self, camera):
        return primeros_puntos(self.x - camera.x, self.y - camera.y, self.z - camera.z)

# Definición de la clase 'segundos_puntos'
class segundos_puntos:
    def __init__(self, _u, _v):
        self.u = _u
        self.v = _v

# Función para realizar la resta de la cámara a un punto
def cameraSubtraction(p, camera):
    return p - camera

# Función para obtener las coordenadas fraccionales de un punto
def getFraction(p):
    return segundos_puntos(round((p.x / p.z) * 10) + WIDTH // 2, round((p.y / p.z) * 10) + HEIGHT // 2)

# Función para dibujar una línea entre dos puntos
def aristas(p1, p2, camera, matrix):
    # Resta el punto inicial y final a la posición de la cámara
    p1_cam = cameraSubtraction(p1, camera)
    p2_cam = cameraSubtraction(p2, camera)

    # Convierte los puntos a fracciones
    f1 = getFraction(p1_cam)
    f2 = getFraction(p2_cam)

    # Calcula la diferencia en x y y, la dirección y el error inicial
    dx = abs(f2.u - f1.u)
    dy = abs(f2.v - f1.v)
    sx = 1 if f1.u < f2.u else -1
    sy = 1 if f1.v < f2.v else -1
    err = dx - dy

    while True:
        # Si la fracción está dentro de la matriz, dibuja un punto en la posición correspondiente
        if 0 <= f1.u < WIDTH and 0 <= f1.v < HEIGHT:
            # Cambia el color del carácter a amarillo
            print("\033[33m*\033[0m", end="")
            # Coloca el carácter en la matriz
            matrix[f1.v][f1.u] = '*'

        # Si se ha alcanzado el punto final, sale del bucle
        if f1.u == f2.u and f1.v == f2.v:
            break

        # Calcula el siguiente punto en la línea
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            f1.u += sx
        if e2 < dx:
            err += dx
            f1.v += sy

# Función para imprimir la matriz en la salida estándar
def el_print(matrix):
    for i in range(HEIGHT):
        for j in range(WIDTH):
            print(matrix[i][j], end=' ')
        print()
}
# La función updateMatrix 
Se encarga de actualizar la matriz de proyección. Primero, se limpia la matriz llenándola con puntos ('.') para representar un espacio vacío. Luego, se recorren las líneas definidas en la lista lines y se llama a la función aristas para dibujar cada línea en la matriz.

# La función main 
Es la función principal del programa. En ella se definen los puntos de la escena y la cámara. Luego, se crea una matriz para la proyección y se llama a la función updateMatrix para inicializarla y mostrarla en la salida estándar. Después, se entra en un bucle donde se espera la entrada del usuario para mover la cámara en la escena. Cada vez

