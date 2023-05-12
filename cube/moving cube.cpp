#include <iostream>
#include <cmath>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 40;
class primeros_puntos {
public:
    double x, y, z;
    primeros_puntos(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    // Overloaded '-' operator to perform camera subtraction
    primeros_puntos operator-(const primeros_puntos& camera) {
        return primeros_puntos(x - camera.x, y - camera.y, z - camera.z);
    }
};

class segundos_puntos {
public:
    int u, v;
    segundos_puntos(int _u, int _v) : u(_u), v(_v) {}
};

// Function to perform camera subtraction on a Point
primeros_puntos cameraSubtraction(primeros_puntos p, primeros_puntos camera) {
    return p - camera;
}

// Function to get the fractional coordinates of a Point
segundos_puntos getFraction(primeros_puntos p) {
    return segundos_puntos(round((p.x / p.z) * 10) + WIDTH / 2, round((p.y / p.z) * 10) + HEIGHT / 2);
}

// Function to draw a line between two Points
void aristas(primeros_puntos p1, primeros_puntos p2, primeros_puntos camera, char matrix[][WIDTH]) {
    // Resta el punto inicial y final a la posición de la cámara
    primeros_puntos p1_cam = cameraSubtraction(p1, camera);
    primeros_puntos p2_cam = cameraSubtraction(p2, camera);

    // Convierte los puntos a fracciones
    segundos_puntos f1 = getFraction(p1_cam);
    segundos_puntos f2 = getFraction(p2_cam);

    // Calcula la diferencia en x y y, la dirección y el error inicial
    int dx = abs(f2.u - f1.u); 
    int dy = abs(f2.v - f1.v);
    int sx = (f1.u < f2.u) ? 1 : -1;
    int sy = (f1.v < f2.v) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        // Si la fracción está dentro de la matriz, dibuja un punto en la posición correspondiente
        if (f1.u >= 0 && f1.u < WIDTH && f1.v >= 0 && f1.v < HEIGHT) {
            // Cambia el color del caracter a amarillo
            printf("\033[33m*\033[0m");
            // Coloca el caracter en la matriz
            matrix[f1.v][f1.u] = '*';
        }

        // Si se ha alcanzado el punto final, sale del bucle
        if (f1.u == f2.u && f1.v == f2.v) {
            break;
        }

        // Calcula el siguiente punto en la línea
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            f1.u += sx;
        }
        if (e2 < dx) {
            err += dx;
            f1.v += sy;
        }
    }
}



void el_print(char matrix[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
          
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void updateMatrix(primeros_puntos* points, primeros_puntos camera, char matrix[HEIGHT][WIDTH]) {
    // Limpia la matriz
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = '.';
        }
    }

    // Dibuja las líneas
    int lines[][2] = {
        {0, 1}, {2, 3}, {4, 5}, {6, 7}, // Paralelas al eje z
        {0, 2}, {1, 3}, {4, 6}, {5, 7}, // Paralelas al eje y
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Paralelas al eje x
    };
    int num_lines = sizeof(lines) / sizeof(lines[0]);
    for (int i = 0; i < num_lines; i++) {
        aristas(points[lines[i][0]], points[lines[i][1]], camera, matrix);
    }

    // Imprime la matriz
    el_print(matrix);
}


int main() {
    primeros_puntos points[] = {
        { 1, 1, 1 },
        { -1, 1, 1 },
        { 1, -1, 1 },
        { -1, -1, 1 },
        { 1, 1, -1 },
        { -1, 1, -1 },
        { 1, -1, -1 },
        { -1, -1, -1 }
    };
    primeros_puntos la_camara = { 1, 2, 2 };
    char matrix[HEIGHT][WIDTH];

    updateMatrix(points, la_camara, matrix);
    el_print(matrix);

    char key;
    while (true) {
        cin >> key;
        if (key == 'q') {
            la_camara.x += 1;
        }
        else if (key == 'a') {
            la_camara.y += 1;
        }
        else if (key == 'w') {
            la_camara.x -= 1;
        }
        else if (key == 's') {
            la_camara.y -= 1;
        }
        else if (key == 'e') {
            la_camara.z += 1;
        }
        else if (key == 'd') {
            la_camara.z -= 1;
        }
          else if (key == 'g') {
            la_camara.z -= 1;
        }
        else {
            break;
        }

        // Actualiza la matriz y la imprime
        updateMatrix(points, la_camara, matrix);
        el_print(matrix);
    }

    return 0;
}