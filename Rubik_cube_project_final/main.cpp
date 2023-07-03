#define STB_IMAGE_IMPLEMENTATION


#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE


//#include "Solve/solve.h"
//#include "Solve/random.h"

//#include "Solve/solve.cpp"

// GLM Graphics Rendering
#include <thread>
#include <chrono>
#include "linmath.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#include <filesystem>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Solver
#include "Solve/solve.h"
#include "Solve/random.h"
// C++ Standard Library
#include <iostream>

// Library for Cubo Rubik
#include "Point.h"
#include "Face.h"
#include "Cube.h"
#include "Rubik.h"
#include <random>
// Img and Shader
#include "stb_image.h"
#include "shader_m.h"

string val="";

int valores_cruz[] = {1,9,11,19};

// Camara
float camX = 7.0f;
float icamX = camX;
float camY = 5.0f;
float icamY = camY;
float camZ = 8.0f;
float icamZ = camZ;

double lastX = 0.0;
double lastY = 0.0;

bool s_mov_camara_x = 1;
bool s_mov_camara_y = 1;
bool s_mov_camara_z = 1;

bool solver_flag = false;
bool parar_animacion_atomo = false;
bool solver_flag_aux = false;
bool mover_cubito_manual = false;
bool mover_cubito_auto = false;
bool func_cubito_auto = false;

vector<int> estado_cubitos(27,0);
vector<int> estado_cubos_letra(27,0);
int contador_cubitos_x = 0;
int contador_cubitos_y = 0;
int contador_cubitos_aux = 0;
int cont_animacion_palabra = 0;
int contador_letras_puntos= 0;

// Movimiento

float mouseSensitivity = 0.05f;
glm::mat4 trans = glm::mat4(1.0f);
glm::mat4 trans2 = glm::mat4(1.0f);
std::string cad_desordenar = "R'F'F'";
std::string cad_solve = "RRDU'LUR'B'D'L'R'BF'";
std::string cad_manual = "";
std::string cad_manual_1 = "";
std::string cad_ordenar = "";
std::string movmientos_cubito ="";

////////////////////////////////////////////////////////////////
//PARA HACER LAS LETRAS
float divisor = 0.1;
float sentido_animacion_letra = 1.0f;
bool animacion_p_atomo = 1;
vector<glm::vec3> letras_puntos{

    //letra G1
    {480.0f*divisor,500.0f*divisor,800.0f*divisor},
    {400.0f*divisor,600.0f*divisor,800.0f*divisor},
    {300.0f*divisor,700.0f*divisor,800.0f*divisor},
    {500.0f*divisor,700.0f*divisor,800.0f*divisor},
    {400.0f*divisor,800.0f*divisor,800.0f*divisor},
    {300.0f*divisor,800.0f*divisor,700.0f*divisor},
    {500.0f*divisor,700.0f*divisor,600.0f*divisor},
    {400.0f*divisor,300.0f*divisor,700.0f*divisor},
    {300.0f*divisor,300.0f*divisor,600.0f*divisor},
    
    //LETRA G2
    {500.0f*divisor,500.0f*divisor,600.0f*divisor},
    {400.0f*divisor,600.0f*divisor,600.0f*divisor},
    {300.0f*divisor,700.0f*divisor,600.0f*divisor},
    {500.0f*divisor,700.0f*divisor,600.0f*divisor},
    {400.0f*divisor,800.0f*divisor,600.0f*divisor},
    {300.0f*divisor,800.0f*divisor,500.0f*divisor},
    {500.0f*divisor,700.0f*divisor,400.0f*divisor},
    {400.0f*divisor,300.0f*divisor,500.0f*divisor},
    {300.0f*divisor,300.0f*divisor,400.0f*divisor},

    //TOQUE FINAL
    //{300.0f*divisor,300.0f*divisor,400.0f*divisor},
    {300.0f*divisor,600.0f*divisor,700.0f*divisor},
    {300.0f*divisor,600.0f*divisor,720.0f*divisor},
    {300.0f*divisor,500.0f*divisor,770.0f*divisor},
    {500.0f*divisor,600.0f*divisor,320.0f*divisor},
    {500.0f*divisor,600.0f*divisor,320.0f*divisor},
    {500.0f*divisor,500.0f*divisor,370.0f*divisor},
    {400.0f*divisor,400.0f*divisor,160.0f*divisor},
    {400.0f*divisor,500.0f*divisor,190.0f*divisor},
    {400.0f*divisor,500.0f*divisor,170.0f*divisor},
    //{300.0f*divisor,500.0f*divisor,750.0f*divisor},
   


};


////////////////////////////////////////////////////////////////
float movimiento = 0;
bool flagMovimiento = true;
bool flagMovimiento01 = true;
bool flag_animacion = false;

float sentido = false;

bool desordenar = false;
bool manual = false;
bool ordenar = false;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow *window);

// Camadas
bool frontal = false;
bool trasera = false;
bool derecha = false;
bool izquierda = false;
bool superior = false;
bool inferior = false;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float rValue = 0.0f, gValue = 0.0f, bValue = 0.0f;


void CargarVertices(std::vector<float> vertices)
{
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(float),
                 &vertices[0],
                 GL_STATIC_DRAW);
}
void CargarIndices(std::vector<int> indices)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(int),
                 &indices[0],
                 GL_STATIC_DRAW);
}

string condition_input = "N";
vector<string> reg_mov;
vector<string> solution_cubo;
Rubik c1;
bool termino = false;

vector<double> g_n_random(){
    vector<double> valores_random(6);
     

    // Definir el rango deseado
    double min = 0.005;
    double max = 0.001;
    //cout << "Numeros aleatorios: ";
    for(int i=0; i<6;i++){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(min, max);
        //double randomNum = dis(gen);
        valores_random[i] = dis(gen);
        //cout<< valores_random[i] << " ";
    }
    
    //cout<<endl;
    return valores_random;

    //std::cout << "Número aleatorio: " << randomNum << std::endl;
}


void print_estado_cubitos(){
    for(int i=0;i<estado_cubitos.size();i++){
        cout<<i<<" "<<estado_cubitos[i]<<endl;
    }
}
    

void respirar(float f) {
    vector<double> ran = g_n_random();
    /*cout << "Numeros aleatorios: ";
    for(int i=0; i<6;i++){
        cout<< ran[i] << " ";
    }
    
    cout<<endl;
    */
    
    
    
    double aux = 1;
    if(!f){
        aux = aux*-1;
    }
    for (int i = 0; i < 6; i++)
    {
        trans = glm::mat4(1.0f);
        if (i == 0) {
            trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, ran[0]*aux));
        }
        if (i == 1) {
            trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, -ran[1]*aux));
        }
        if (i == 2) {
            trans = glm::translate(trans, glm::vec3(ran[2]*aux, 0.0f, 0.0f));
        }
        if (i == 3) {
            trans = glm::translate(trans, glm::vec3(-ran[3]*aux, 0.0f, 0.0f));
        }
        if (i == 4) {
            trans = glm::translate(trans, glm::vec3(0.0f, ran[4]*aux, 0.0f));
        }
        if (i == 5) {
            trans = glm::translate(trans, glm::vec3(0.0f, -ran[5]*aux, 0.0f));
        }

        for (int j = 0; j < c1.camadas[i].size(); j++)
        {

            /*if(estado_cubitos[c1.camadas[i][j].first] != estado_cubitos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first]){
                c1.cubos[c1.camadas[i][j].first].Transform(trans, c1.centros[c1.camadas[i][j].first], 0);
            }*/
             c1.cubos[c1.camadas[i][j].first].Transform(trans, c1.centros[c1.camadas[i][j].first], 0);
            
        }
    }
}

//cara celeste camadas[3][8] == 9,19,11,1  -> cambiar sentido -> c1.MoverCamadaSuperior(3)
//cara verde   camadas[4][3] == 9,19,11,1  -> c1.MoverCamadaSuperior(4)

void mover_cubito(float mov, char ax){
    trans = glm::mat4(1.0f);
    if( ax == 'Z'|| ax == 'z'){
        trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, mov ));
    }
    else if( ax == 'X' || ax == 'x'){
        trans = glm::translate(trans, glm::vec3(mov , 0.0f, 0.0f));
    }
    else if( ax == 'C' || ax == 'c'){
        trans = glm::translate(trans, glm::vec3(0.0f, mov , 0.0f));
    }

    c1.cubos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first].Transform(trans, c1.centros[c1.camadas[contador_cubitos_x][contador_cubitos_y].first], 0);

}   

//necesitamos un cont del 1 al 27
void animacion_pal(float mov , char eje){
 //   letras_puntos
    trans2 = glm::mat4(1.0f);
 
    if(eje == 'z'){
        trans2 = glm::translate(trans2, glm::vec3(0.0f, 0.0f, mov * sentido_animacion_letra));
        c1.cubos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first].Transform(trans2, c1.centros[c1.camadas[contador_cubitos_x][contador_cubitos_y].first], 0);
   
    }
    if(eje == 'x'){
        trans2 = glm::translate(trans2, glm::vec3(mov * sentido_animacion_letra, 0.0f, 0.0f));
        c1.cubos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first].Transform(trans2, c1.centros[c1.camadas[contador_cubitos_x][contador_cubitos_y].first], 0);
   
    }
    if(eje == 'y'){
        trans2 = glm::translate(trans2, glm::vec3(0.0f, mov * sentido_animacion_letra, 0.0f));
        c1.cubos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first].Transform(trans2, c1.centros[c1.camadas[contador_cubitos_x][contador_cubitos_y].first], 0);
    }
    //cout<<"entro aqi"<<endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));

 

}

void reiniciar_estados_cubo(){
    for(int i=0;i<27;i++){
        estado_cubos_letra[i] = 0;
    }
}

void animacion_palabra(){
    bool aum;
    
    //letras_puntos.size()
    if (func_cubito_auto && contador_letras_puntos< letras_puntos.size()) { ///falta arreglarr estooo
            //cout<<"entro al if"<<endl;
            aum = true;
            movimiento++;
            //cout<<contador_letras_puntos<<endl;
            //cout<<contador_cubitos_x<<" ";
            if(estado_cubos_letra[c1.camadas[contador_cubitos_x][contador_cubitos_y].first] == 0){ 
                if (movimiento <= letras_puntos[contador_letras_puntos].z && cont_animacion_palabra == 0 ) {
                //cout<<movimiento<<endl;
                    animacion_pal(0.1 , 'z');
                /*if(movimiento > 1499){
                    flag_animacion = true;
                }
                if(flag_animacion){
                    c1.animacion_atomo(0);
                }*/
                }
                else if(movimiento <= letras_puntos[contador_letras_puntos].x && cont_animacion_palabra== 1){
                    animacion_pal(0.1 , 'x');
                }
                else if(movimiento <= letras_puntos[contador_letras_puntos].y && cont_animacion_palabra== 2){
                    //PARA 0.01 VELOCIDAD NECESITAS EJEMPLO 1000
                    //ENTONCES PARA 0.1 VELOCIDAD NECESITARIAS 100
                    animacion_pal(0.1 , 'y');
                }
                else if(cont_animacion_palabra != 3){
                    movimiento = 0;
                    cont_animacion_palabra++;
                   
                }
                else{
                    
                     cont_animacion_palabra = 0;
                     
                     cout<<contador_letras_puntos<<" ";
                     contador_letras_puntos++;
                 
                   
                    estado_cubos_letra[c1.camadas[contador_cubitos_x][contador_cubitos_y].first]=1;
                    
                    contador_cubitos_y++;
                    if(contador_cubitos_y == 9){
                         contador_cubitos_y = 0;
                         contador_cubitos_x++;
                         if(contador_cubitos_x == 6){
                            func_cubito_auto = false;
                         }
                    }
  
                }
            
            }
            else{
                
                contador_cubitos_y++;
                
                if(contador_cubitos_y == 9){
                         contador_cubitos_y = 0;
                         contador_cubitos_x++;

                         if(contador_cubitos_x == 6){
                            func_cubito_auto = false;
                         }
                }     
            }
    }
    else{
        reiniciar_estados_cubo();
        func_cubito_auto = false;
    }
    
}

void mover_cubo(string& movimientos){
    int contador_animacion = 0;
    
    if(!movimientos.empty()){
        switch (movimientos[0])
        {
        case 'Z':
            mover_cubito(0.1,movimientos[0]);
            movimientos.erase(movimientos.begin());
            estado_cubitos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first] = 1;
            
            break;
        case 'X':
            mover_cubito(0.1,movimientos[0]);
            movimientos.erase(movimientos.begin());
            estado_cubitos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first] = 1;
            break;
        case 'C':
            mover_cubito(0.1,movimientos[0]);
            movimientos.erase(movimientos.begin());
            estado_cubitos[c1.camadas[contador_cubitos_x][contador_cubitos_y].first] = 1;
            break;    
        default:
            break;
        }
    }
    
}


void AnimarRespirar() {
    
    bool aum;
    if (flagMovimiento) {
            aum = true;
            movimiento++;
            if (movimiento <= 1000) {
                respirar(aum);
            }
            else {
                flagMovimiento = false;
                movimiento = 0;
            }
        }
        else {
            aum = false;
            movimiento++;
            if (movimiento <= 1000) {
                respirar(aum);
            }
            else {
                flagMovimiento = true;
                movimiento = 0;
            }
        }
}
void Animacion(std::string &automatico)
{
    if (!automatico.empty())
    {
        if (automatico[1] == '\'' && (c1.sentido == 1.0f)) {
            automatico.erase(automatico.begin() + 1);
            automatico.insert(automatico.begin(), 2, automatico[0]);
        }
        switch (automatico[0])
        {
        case 'F':
            if (c1.MoverCamadaFrontal(0)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }
            // c1.ShowCamadas();
            break;
        case 'B':
            if (c1.MoverCamadaFrontal(1)) {
                //solver_flag = true;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }
            // c1.ShowCamadas();
            break;
        case 'R':
            if (c1.MoverCamadaLateral(2)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }
            // c1.ShowCamadas();
            break;
        case 'L':
            if (c1.MoverCamadaLateral(3)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }// c1.ShowCamadas();
            break;
        case 'U':
            if (c1.MoverCamadaSuperior(4)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }
            // c1.ShowCamadas();
            break;
        case 'D':
            if (c1.MoverCamadaSuperior(5)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                std::cout << automatico << std::endl;
            }
            // c1.ShowCamadas();
            break;
        default:
            break;
        }
    }
    else {
        desordenar = false;
    }
}


void Manual(std::string& automatico)
{
    if (!automatico.empty())
    {
       
        switch (automatico[0])
        {
        case 'F':
            if (c1.MoverCamadaFrontal(0)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
                AnimarRespirar();
            }
            // c1.ShowCamadas();
            break;
        case 'B':
            if (c1.MoverCamadaFrontal(1)) {
                //solver_flag = true;
                automatico.erase(automatico.begin());
            }
            // c1.ShowCamadas();
            break;
        case 'R':
            if (c1.MoverCamadaLateral(2)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
            }
            // c1.ShowCamadas();
            break;
        case 'L':
            if (c1.MoverCamadaLateral(3)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
            }// c1.ShowCamadas();
            break;
        case 'U':
            if (c1.MoverCamadaSuperior(4)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
            }
            // c1.ShowCamadas();
            break;
        case 'D':
            if (c1.MoverCamadaSuperior(5)) {
                //solver_flag = false;
                automatico.erase(automatico.begin());
            }
            // c1.ShowCamadas();
            break;
        default:
            break;
        }
    }
}




int grafica1()
{
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
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
     gladLoadGL(glfwGetProcAddress);


    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    //Shader ourShader("C:/Users/HP/OneDrive/Desktop/computacion_grafica/cg_compiler/USB_CG_Compiler/glfw-master/glfw-master/build/mak.mingw.x64/OwnProjects/Project_06/vertex.vs", "C:/Users/HP/OneDrive/Desktop/computacion_grafica/cg_compiler/USB_CG_Compiler/glfw-master/glfw-master/build/mak.mingw.x64/OwnProjects/Project_06/fragment.fs");
    //"C:/Users/HP/OneDrive/Desktop/computacion_grafica/cg_compiler/USB_CG_Compiler/glfw-master/glfw-master/OwnProjects/Project_06/vertex.vs"
    Shader ourShader("D:\\grafica\\prueba\\glfw-master\\glfw-master\\OwnProjects\\Project_06\\vertex.vs", "D:\\grafica\\prueba\\glfw-master\\glfw-master\\OwnProjects\\Project_06\\fragment.fs");
    
    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // load and create a texture
    // -------------------------
    unsigned int texture1, texture2;
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("D:\\grafica\\prueba\\glfw-master\\glfw-master\\OwnProjects\\Project_06\\color.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load("D:\\grafica\\prueba\\glfw-master\\glfw-master\\OwnProjects\\Project_06\\color.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);

    // pass projection matrix to shader (as projection matrix rarely changes there's no need to do this per frame)
    // -----------------------------------------------------------------------------------------------------------
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    // render loop
    // -----------

    int bandera = 1;
    int banderanum = 0;

    CargarIndices(c1.IPT);
    //c1.ShowCamadas();
    

    std::cout << "Instrucciones" << std::endl;
    std::cout << "F -> Camada frontal" << std::endl;
    std::cout << "B -> Camada trasera" << std::endl;
    std::cout << "R -> Camada derecha" << std::endl;
    std::cout << "L -> Camada izquierda" << std::endl;
    std::cout << "U -> Camada superior" << std::endl;
    std::cout << "D -> Camada inferior" << std::endl;
    std::cout << std::endl;
    
    std::cout << "W -> Para ingresar movimiento" << std::endl;
    std::cout << "S -> Movimientos inversos" << std::endl;
    std::cout << "**Nota Antes de crear la solucion volver el sentido a la normalidad**" << std::endl;
    
    std::cout << "E -> Para generar solve" << std::endl;
    std::cout << "Q -> Animacion de la solucion" << std::endl;
    std::cout << "A -> Animacion de atomo" << std::endl;
    std::cout << "Z -> Animacion de para la letra , pero el cubo tiene que estar armado de forma original" << std::endl;
    std::cout << "X -> Cambiar sentido para reconstruir cubo despues de formar la palabra" << std::endl;
    std::cout << "P -> Parar animacion de atomo y retornarla a la forma original de cubo" << std::endl;


    
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);

        glBindTexture(GL_TEXTURE_2D, texture1);

        // activate shader
        ourShader.use();

        // camera/view transformation
        glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        float radius = 10.0f;
        //camX = static_cast<float>(sin(glfwGetTime()) * radius);
        //camZ = static_cast<float>(cos(glfwGetTime()) * radius);
        view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
        ourShader.setMat4("view", view);

        glBindVertexArray(VAO);

        CargarVertices(c1.GenEbo());

        glDrawElements(GL_TRIANGLES, c1.ind_tam, GL_UNSIGNED_INT, 0);
        //glDraweLEMENTS(GL_LINES)

        if (desordenar) {               //ESTO ES PARA QUE FUNCIONE EL SOLVER , CUANDO SE HACE MOVIMIENTOS
            //Animacion(cad_solve);
            Animacion(cad_desordenar);
        }
        if (manual) {                   //PARA QUE HAGA LOS MOVIMIENTOS NORMALES MANUALES DEL CUBO RUBICK
            Manual(cad_manual_1);
        }

        
        if (flagMovimiento01) {         //PARA QUE RESPIRE EL CUBO
            AnimarRespirar();
        }

        
        if(mover_cubito_auto){      //PARA HACER LA ANIMACION DE LA PALABRA
            animacion_palabra();
        }

        //PARA MOVER 1 CUBITO MANUALMENTE
        
        /*if(mover_cubito_manual){
            mover_cubo(movmientos_cubito);
        }*/
            
        //animacion_p_atomo
        if(solver_flag && animacion_p_atomo){
            
            
            animacion_p_atomo = c1.animacion_atomo(0,parar_animacion_atomo);
        }

        
        trans = glm::mat4(1.0f);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    
}

int main()
{
    // Cube c1;
    // glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    // c1.ShowCube();
    // // c1.Transform(trans);
    // c1.ShowEBO();
    // c1.ShowIPT();
    grafica1();
    
    return 0;
}

void processInput(GLFWwindow *window)
{
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    double xOffset = (xpos - camX);
    double yOffset = (ypos - camY);
    camX = xpos*mouseSensitivity;
    camY = ypos*mouseSensitivity;
}




void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    //MOVIMIENTOS PARA MOVER LOS CUBITOS - TRASLADARLOS MANUALMENTE
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
     {
        
        if(mover_cubito_auto){
           
            
            mover_cubito_auto = false;
        }
        else{

            mover_cubito_auto = true;
        }

        func_cubito_auto = true;    
        movmientos_cubito += "Z"; 
        
        
     }
     if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
     {
        /*if(mover_cubito_manual){
            mover_cubito_manual = false;
        }
        else{
            mover_cubito_manual = true;
        }
        movmientos_cubito += "X"; 
        */
        contador_cubitos_x = 0;
        contador_cubitos_y = 0;
        movimiento = 0;
        contador_letras_puntos = 0;
        sentido_animacion_letra = sentido_animacion_letra * -1.0f;
        
     }
     if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
     {
        if(mover_cubito_manual){
            mover_cubito_manual = false;
        }
        else{
            mover_cubito_manual = true;
        }
        movmientos_cubito += "C"; 
        
        
     }

    //////////////////////////////////////////////////////////


    //PARA MOVIMIENTOS DE LA CAMARA///////////////////////////
     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
     {
        //s_mov_camara_y = false;
        if(solver_flag){
            solver_flag = false;
        }
        else{
            solver_flag = true;
        }
        
        //olver_flag_aux = true;
        
     }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
     {
        //s_mov_camara_y = false;
        if(parar_animacion_atomo){
            animacion_p_atomo = true;
            parar_animacion_atomo = false;
        }
        else{
            parar_animacion_atomo = true;
        }
        
        //olver_flag_aux = true;
        
     }
  

     //AQUI TERMINAN LOS MOVIMIENTOS DE LA CAMARA/////////////////////////////

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        /*cad_solve=cad_manual;
        desordenar = true;*/
        //std::cout << "EL ORDEN PARA ARREGLAR EL CUBO ES: " << cad_solve << std::endl;
         desordenar = true;
        std::cout << "Ordenamiento Automatico: " << cad_desordenar << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        
        std::cout << "Generando Solucion para: " << std::endl;
        std::cout << cad_manual << std::endl;
        std::string solucion = SuperSolve(cad_manual);
        cad_manual.clear();
        std::cout << "Solucion por el SuperSolve :) " << std::endl;
        std::cout << solucion << std::endl;
        cad_desordenar = solucion;
      
        
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        //cout<<"el numero  de cubos es: "<<c1.cubos.size()<<endl;
        if (manual) {
            manual = false;
            flagMovimiento01 = true;
        }
        else {
            manual = true;
            flagMovimiento01 = false;
        }

    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        c1.sentido *= -1.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        
        if (c1.sentido == 1.0f) {
            cad_manual += "F";
            //val = "F'";
            
        }
        else {
            cad_manual += "F'";
            //val = "F";
            
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "F";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        if (c1.sentido == 1.0f) {
            cad_manual += "B";
            //val = "B'";
        }
        else {
            cad_manual += "B'";
            //val = "B";
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "B";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        if (c1.sentido == 1.0f) {
            cad_manual += "R";
            //val = "R'";
        }
        else {
            cad_manual += "R'";
            //val = "R";
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "R";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        if (c1.sentido == 1.0f) {
            cad_manual += "L";
            //val = "L'";
        }
        else {
            cad_manual += "L'";
            //val = "L";
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "L";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
        if (c1.sentido == 1.0f) {
            cad_manual += "U";
            //val = "U'";
        }
        else {
            cad_manual += "U'";
            //val = "U";
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "U";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        if (c1.sentido == 1.0f) {
            cad_manual += "D";
            //val = "D'";
        }
        else {
            cad_manual += "D'";
            //val = "D";
        }
        //cad_manual = val + cad_manual;
        cad_manual_1 += "D";
        std::cout << "Desordenamiento: " << cad_manual << std::endl;
        std::cout << "para ordenar: " << cad_manual << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        flagMovimiento01 = true;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        flagMovimiento01 = false;
    }
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}