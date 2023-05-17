#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Tamaño de la ventana
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    out vec3 ourColor;
    uniform mat4 transform;
    void main()
    {
        gl_Position = transform * vec4(aPos, 1.0);
        ourColor = aColor;
    }
)";

const char *fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    in vec3 ourColor;
    void main()
    {
        FragColor = vec4(ourColor, 1.0);
    }
)";

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Establece una perspectiva adecuada
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));


    // Ajusta la posición y orientación de la cámara
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glm::mat4 view = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view));

    //gluLookAt(3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Crea el shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    // Compila el vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glAttachShader(shaderProgram, vertexShader);

    // Compila el fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Enlaza el shader program
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Define los vértices del octógono en 2D
    float octagonVertices[] = {
    0.0f, 1.0f, 0.0f,   // Vértice 1
    -0.7f, 0.7f, 0.0f,  // Vértice 2
    -1.0f, 0.0f, 0.0f,  // Vértice 3
    -0.7f, -0.7f, 0.0f, // Vértice 4
    0.0f, -1.0f, 0.0f,  // Vértice 5
    0.7f, -0.7f, 0.0f,  // Vértice 6
    1.0f, 0.0f, 0.0f,   // Vértice 7
    0.7f, 0.7f, 0.0f    // Vértice 8
};

    // Crear el búfer de atributos
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // Enlazar y cargar los datos en el búfer de atributos
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(octagonVertices), octagonVertices, GL_STATIC_DRAW);

    // Configurar los atributos de vértices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Configurar el color de los vértices
    float colors[] = {
        1.0f, 0.0f, 0.0f,   // Vértice 1 (Rojo)
        0.0f, 1.0f, 0.0f,   // Vértice 2 (Verde)
        0.0f, 0.0f, 1.0f,   // Vértice 3 (Azul)
        1.0f, 1.0f, 0.0f,   // Vértice 4 (Amarillo)
        1.0f, 0.0f, 1.0f,   // Vértice 5 (Magenta)
        0.0f, 1.0f, 1.0f,   // Vértice 6 (Cyan)
        1.0f, 1.0f, 1.0f,   // Vértice 7 (Blanco)
        0.5f, 0.5f, 0.5f    // Vértice 8 (Gris)
    };

    // Crear el búfer de color
    unsigned int colorVBO;
    glGenBuffers(1, &colorVBO);

    // Enlazar y cargar los datos en el búfer de color
    glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Configurar el atributo de color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Transformación del objeto
    float angle = 45.0f;
    glm::mat4 transform = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));

    // Obtener la ubicación de la transformación uniforme en el shader
    int transformLoc = glGetUniformLocation(shaderProgram, "transform");

    // Pasar la transformación al shader
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    // Renderizar el octágono
    glDrawArrays(GL_POLYGON, 0, 8);

    // Desenlazar el búfer de atributos y el programa de shader
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);

}
int main()
{
    // ...

    // Crear una ventana GLFW
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Error al crear la ventana GLFW." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Registra la función framebuffer_size_callback para el evento de cambio de tamaño de la ventana
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

    // ...
}

       






















/*

███████████████████████████████████████████████████████████████████████
█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░███░░░░░░░░░░█████████████
█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░███░░▄▀▄▀▄▀░░█████████████
█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░███░░░░▄▀░░░░█████████████
█░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█████░░▄▀░░███████████████
█░░▄▀░░█████████░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░░░███░░▄▀░░███████████████
█░░▄▀░░██░░░░░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀▄▀░░███░░▄▀░░███████████████
█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░░░▄▀░░███░░▄▀░░███████████████
█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░████░░▄▀░░███░░▄▀░░███████████████
█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░▄▀░░█░░░░▄▀░░░░█████████████
█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀░░█████████████
█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░░░█░░░░░░░░░░█████████████
███████████████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
█░░░░░░██████████░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░███░░░░░░░░░░░░░░█░░░░░░█████████░░░░░░░░░░░░░░█░░░░░░░░░░░░░░██████████░░░░░░██░░░░░░█
█░░▄▀░░░░░░░░░░░░░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀▄▀░░███░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░░░▄▀░░███░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░░░░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░████░░▄▀░░███░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░█████████░░▄▀░░██████████████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░▄▀░░███░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀▄▀░░███░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░██░░░░░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░░░███░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░░░░░█░░░░░░░░░░▄▀░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░██████████░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█████░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░█████████████████░░▄▀░░██████████░░▄▀░░██░░▄▀░░█
█░░▄▀░░██████████░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░░░░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░█░░░░░░░░░░▄▀░░██████████░░▄▀░░░░░░▄▀░░█
█░░▄▀░░██████████░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░██████████░░▄▀▄▀▄▀▄▀▄▀░░█
█░░░░░░██████████░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░██████████░░░░░░░░░░░░░░█
██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
*/
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <iostream>
#include "Polygon.h"
using namespace std;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

/*
//----------------------SHADER TRIANGULOS----------------------------------------

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


//----------------------SHADER LINEAS----------------------------------------

const char *vertexShaderSourceLine = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\0";
const char *fragmentShaderSourceLine = "#version 330 core\n"
    "out vec4 FragColor;\n"
	"in vec4 vertexColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\n\0";


//----------------------SHADER PUNTOS----------------------------------------
    
const char *vertexShaderSourcePoint = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\0";
const char *fragmentShaderSourcePoint = "#version 330 core\n"
    "out vec4 FragColor;\n"
	"in vec4 vertexColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
    "}\n\0";    
	

*/


//SHADERSS
const char *vertexShaderSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "uniform mat4 transform;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.5);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";




int estado = 0;
int cont2 = 0;
int cont3 = 0;
//RGB
float Restrella=1;
float Gestrella=1;
float Bestrella=0;

float Rrombo = 0;
float Grombo = 0;
float Brombo = 1;

float Rcuadrado = 0;
float Gcuadrado = 1;
float Bcuadrado = 0;

float Rtriangulo = 1;
float Gtriangulo = 0;
float Btriangulo = 0;

float RtrianguloLine = 1;
float GtrianguloLine = 0;
float BtrianguloLine = 1;

float Rcirculo = 1;
float Gcirculo = 1;
float Bcirculo = 0;

float Rpentagono = 1;
float Gpentagono = 0;
float Bpentagono = 0;
///color
void color(float *R, float *G, float *B) {
    float  a= 1;
    srand(time(NULL));

    for (int c = 0; c <= 100; ++c)
    {
        *R = (float(rand()) / float((RAND_MAX)) * a);
        *G = (float(rand()) / float((RAND_MAX)) * a);
        *B = (float(rand()) / float((RAND_MAX)) * a);
    }
}
//////////////////////////
int pos_luci = 0;
void contorno(Polygono& p, float max_x, float max_y, float min_x, float min_y) {
    vector<float> mi_ma_x = p.get_min_max_x();
    vector<float> mi_ma_y = p.get_min_max_y();

    if (pos_luci == 0) {                                            //arriba
 
        if (mi_ma_y[1] < max_y) {

            p.pro_rotation_z(p.vel);
            float dif = max_x - mi_ma_x[1];
            p.trans( dif,0,0 );
            return;
        }
        pos_luci = 1;
        
    }
    if (pos_luci == 1) {                                            //izquierda
        if (mi_ma_x[0] > min_x) {
            p.pro_rotation_z(p.vel);
            float dif = max_y - mi_ma_y[1];
            p.trans(0, dif, 0);
            return;
        }
        pos_luci = 2;
    }
    if (pos_luci == 2) {                                            //abajo
        if (mi_ma_y[0] > min_y) {
            p.pro_rotation_z(p.vel);
            float dif = min_x - mi_ma_x[0];
            p.trans( dif,0,0 );
            return;
        }
        pos_luci = 3;

    }
    if (pos_luci == 3) {                                              //derecha
        if (mi_ma_x[1] < max_x) {
            p.pro_rotation_z(p.vel);
            float dif = min_y - mi_ma_y[0];
            p.trans( 0,dif,0 );
            return;
        }
        pos_luci = 0;
    }
}
//////////////////////////






void movimiento_cuadrado(Polygono& p, float min_x, float min_y, float max_x, float max_y) {
    vector <float> eje_x = p.get_min_max_x();
    vector <float> eje_y = p.get_min_max_y();

        if (estado == 0) {
            if ( eje_y[1] < max_y ) {

                vector <float> direccion{
                    0.0,0.015,0.0,
                };
                p.pro_traslate(direccion);
                return;
            }
            estado = 1;
        }

        if (estado == 1) {
            if (eje_x[0] > min_x) {

                vector <float> direccion{
                    -0.015,0.0,0.0,
                };
                p.pro_traslate(direccion);
                return;
            }
            estado = 2;
        }

        if (estado == 2) {
            if ( cont2 < 108 ) {

                vector <float> direccion{
                    0.0,-0.015,0.0,
                };
                p.pro_traslate(direccion);
                cont2++;
                return;
            }
            estado = 3;
            cont2 = 0;
        }
        
        if (estado == 3) {
            if ( cont3 < 108) {

                vector <float> direccion{
                   0.015,0.0, 0.0,
                };
                p.pro_traslate(direccion);
                cont3++;
                return;
            }
            estado = 0;
            cont3 = 0;
        }
        
    }

///////////////////////////////////////////////////
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
////////////////circulo
//const float PI = 3.14159f;

vector<float> generarVerticesCirculo(float radio, int numPuntos) {
    vector<float> vertices;

    for (int i = 0; i < numPuntos; i++) {
        float angulo = 2 * PI * i / numPuntos;
        float x = radio * cos(angulo);
        float y = radio * sin(angulo);
        float z = 0.0f;

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
    }

    return vertices;
}
// ---------------------------------------------------------------------------------------------------------
///////////VARIABLES
bool condition = false;
/*
vector<float> vertices_hexagono{
        0.5, 0.1, 0.0,
        0.7, 0.2, 0.0,
        0.8, 0.1, 0.0,
        0.7, 0.0, 0.0,
        0.5, 0.0, 0.0,
        0.4, 0.1, 0.0
    };
    
*/
/*
vector<float> vertices_octogono{
        0.4, 0.1, 0.0,
        0.6, 0.1, 0.0,
        0.7, 0.2, 0.0,
        0.7, 0.4, 0.0,
        0.6, 0.5, 0.0,
        0.4, 0.5, 0.0,
        0.3, 0.4, 0.0,
        0.3, 0.2, 0.0
    };
*/
vector<float> vertices_rombo{
    0.7,0.1,0.0,
    0.8,0.2,0.0,
    0.9,0.1,0.0,
    0.8,0.0,0.0,
};
vector<float> vertices_estrella{
    1.14,0.05,0.0,
    1.06,0.1,0.0,
    1.16,0.1,0.0,
    1.19,0.2,0.0,
    1.22,0.1,0.0,
    1.32,0.1,0.0,
    1.24,0.05,0.0,
    1.27,-0.05,0.0,
    1.19,0.01,0.0,
    1.11,-0.05,0.0,
};

vector<float> vertices_cuadrado{
    0.3,0.2,0.0,
    0.5,0.2,0.0,
    0.5,0.0,0.0,
    0.3,0.0,0.0,
};
vector<float> vertices_triangulo{
     0,0.2,1.0,
    -0.1,0.0,0,
     0.1,0.0,0,
};
vector<float> vertices_pentagono{
        0.5, 0.0, 0.0,
        0.8, 0.0, 0.0,
        1.0, 0.4, 0.0,
        0.6, 0.8, 0.0,
        0.2, 0.4, 0.0
    };

vector<float> vertices_circulo = generarVerticesCirculo(0.1f, 30);




// ---------------------------------------------------------------------------------------------------------
//objetos
Polygono estrella(vertices_estrella, Restrella, Gestrella, Bestrella);
Polygono rombo(vertices_rombo, Rrombo, Grombo, Brombo);
Polygono cuadrado(vertices_cuadrado, Rcuadrado, Gcuadrado, Bcuadrado);
Polygono triangulo_rojo(vertices_triangulo, Rtriangulo, Gtriangulo, Btriangulo);
Polygono circulo(vertices_circulo, Rcirculo, Gcirculo, Bcirculo);
Polygono pentagono(vertices_pentagono, Rpentagono, Gpentagono,Bpentagono);
Polygono trianguloLine(vertices_triangulo, RtrianguloLine, GtrianguloLine, BtrianguloLine);

// ---------------------------------------------------------------------------------------------------------
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        estrella.cambiarcolor(Restrella, Gestrella, Bestrella);
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        cuadrado.cambiarcolor(Restrella, Gestrella, Bestrella);
    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
        triangulo_rojo.cambiarcolor(Restrella, Gestrella, Bestrella);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        rombo.cambiarcolor(Restrella, Gestrella, Bestrella);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        triangulo_rojo.escalao(1.5, 1.5, 0.0);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        triangulo_rojo.escalao(0.4, 0.4, 0.0);
    }
       
    
}
const char *vertexShaderSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "uniform mat4 transform;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.5);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";

void drawCube()
{
    // Define los vértices del octógono en 2D
    float octagonVertices[] = {
        0.0f, 1.0f,    // Vértice 1
        0.7f, 0.7f,    // Vértice 2
        1.0f, 0.0f,    // Vértice 3
        0.7f, -0.7f,   // Vértice 4
        0.0f, -1.0f,   // Vértice 5
        -0.7f, -0.7f,  // Vértice 6
        -1.0f, 0.0f,   // Vértice 7
        -0.7f, 0.7f    // Vértice 8
    };

    // Define los vértices del cubo en 3D
    float cubeVertices[8][3];  // 8 vértices con 3 coordenadas (x, y, z)

    // Genera los vértices del cubo a partir de los vértices del octógono
    for (int i = 0; i < 8; i++)
    {
        cubeVertices[i][0] = octagonVertices[i * 2];      // Coordenada x
        cubeVertices[i][1] = octagonVertices[i * 2 + 1];  // Coordenada y
        cubeVertices[i][2] = 0.0f;                        // Coordenada z (en este ejemplo, todos los vértices están en el plano xy)
    }

    // Dibuja las caras del cubo utilizando las llamadas a glBegin(GL_QUADS) y glEnd()
    glBegin(GL_QUADS);

    // Cara frontal
    glVertex3f(cubeVertices[0][0], cubeVertices[0][1], cubeVertices[0][2]);
    glVertex3f(cubeVertices[1][0], cubeVertices[1][1], cubeVertices[1][2]);
    glVertex3f(cubeVertices[2][0], cubeVertices[2][1], cubeVertices[2][2]);
    glVertex3f(cubeVertices[3][0], cubeVertices[3][1], cubeVertices[3][2]);

    // Cara posterior
    glVertex3f(cubeVertices[4][0], cubeVertices[4][1], cubeVertices[4][2]);
    glVertex3f(cubeVertices[5][0], cubeVertices[5][1], cubeVertices[5][2]);
    glVertex3f(cubeVertices[6][0], cubeVertices[6][1], cubeVertices[6][2]);
    glVertex3f(cubeVertices[7][0], cubeVertices[7][1], cubeVertices[7][2]);

    // Otras caras del cubo (izquierda, derecha, arriba, abajo)

    glEnd();
}

void setPerspective(float fov, float aspectRatio, float nearPlane, float farPlane)
{
    float f = 1.0f / tan(fov * 0.5f * (M_PI / 180.0f));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-aspectRatio * nearPlane * f, aspectRatio * nearPlane * f, -nearPlane * f, nearPlane * f, nearPlane, farPlane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void GluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz)
{
    GLfloat forward[3], side[3], up[3];
    GLfloat matrix[16];
    GLfloat theta;
    
    forward[0] = centerx - eyex;
    forward[1] = centery - eyey;
    forward[2] = centerz - eyez;

    // Normalize forward vector
    theta = sqrt(forward[0]*forward[0] + forward[1]*forward[1] + forward[2]*forward[2]);
    forward[0] /= theta;
    forward[1] /= theta;
    forward[2] /= theta;

    // Calculate side vector
    side[0] = forward[1]*upz - forward[2]*upy;
    side[1] = forward[2]*upx - forward[0]*upz;
    side[2] = forward[0]*upy - forward[1]*upx;

    // Normalize side vector
    theta = sqrt(side[0]*side[0] + side[1]*side[1] + side[2]*side[2]);
    side[0] /= theta;
    side[1] /= theta;
    side[2] /= theta;

    // Calculate up vector
    up[0] = side[1]*forward[2] - side[2]*forward[1];
    up[1] = side[2]*forward[0] - side[0]*forward[2];
    up[2] = side[0]*forward[1] - side[1]*forward[0];

    // Create matrix
    matrix[0] = side[0];
    matrix[4] = side[1];
    matrix[8] = side[2];
    matrix[12] = 0.0f;
    matrix[1] = up[0];
    matrix[5] = up[1];
    matrix[9] = up[2];
    matrix[13] = 0.0f;
    matrix[2] = -forward[0];
    matrix[6] = -forward[1];
    matrix[10] = -forward[2];
    matrix[14] = 0.0f;
    matrix[3] = 0.0f;
    matrix[7] = 0.0f;
    matrix[11] = 0.0f;
    matrix[15] = 1.0f;

    // Multiply current matrix by new matrix
    glMultMatrixf(matrix);

    // Translate to eye position
    glTranslatef(-eyex, -eyey, -eyez);
}


void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Establece una perspectiva adecuada
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setPerspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);

    // Ajusta la posición y orientación de la cámara
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GluLookAt(3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Crea el shader program
    unsigned int shaderProgram = glCreateProgram();

    // Compila el vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glAttachShader(shaderProgram, vertexShader);

    // Compila el fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Enlaza el shader program
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Dibuja el cubo
    drawCube();

    // Elimina los shaders y el shader program después de usarlos
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(shaderProgram);

    glFlush();
}



// ---------------------------------------------------------------------------------------------------------

int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    gladLoadGL(glfwGetProcAddress);

    
    // build and compile our shader program
    // ------------------------------------
    // vertex shader

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glUseProgram(shaderProgram);
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(VAO);
   
    // -----------
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();


    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;

}
