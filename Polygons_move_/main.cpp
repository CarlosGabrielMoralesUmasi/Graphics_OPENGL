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
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);
    // as we only have a single shader, we could also just activate our shader once beforehand if we want to 
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
    // render loop
//W-ESCALA 
//S ESCALA 
//E COLOR 
//R COLOR
//C COLOR
//T COLOR
    // -----------
    while (!glfwWindowShouldClose(window)) {
        //rombo.print_position();
        //print_matrix();
        // input
        glfwSetKeyCallback(window, processInput);
        // -----
        // render
        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        //triangulo_rojo.escalao(1.002, 1.002, 0);
        cuadrado.cambiarcolor(Restrella, Gestrella, Bestrella);
       // cuadrado.pro_rotation_eje(5);
        //cuadrado.pro_rotation_x(5);
        movimiento_cuadrado(rombo, -0.9, -0.9, 0.9, 0.9);
        contorno(circulo, 1.3,1.3,-1.3,-1.3);
        color(&Restrella, &Gestrella, &Bestrella);

        ///dibujar
        //estrella.draw(window);
        rombo.draw(window);
        cuadrado.draw(window);
        triangulo_rojo.draw(window);
        circulo.draw(window);
        trianguloLine.drawLine(window);
        //pentagono.draw(window);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();


    }
    // optional: de-allocate all resources once they've outlived their purpose:
    //------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------

    /*
    // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
        // ---------------------------------------------------------------------------------------------------------
        void processInput(GLFWwindow *window)
        {
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
        }

        // glfw: whenever the window size changed (by OS or user resize) this callback function executes
        // ---------------------------------------------------------------------------------------------
        void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            // make sure the viewport matches the new window dimensions; note that width and 
            // height will be significantly larger than specified on retina displays.
            glViewport(0, 0, width, height);
        }
    
    */
    glfwTerminate();
    return 0;

}
