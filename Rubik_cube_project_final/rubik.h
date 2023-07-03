#ifndef RUBIK_H
#define RUBIK_H

// GLM Graphics

#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// C++ Standard
#include <iostream>
#include <vector>
#include <string>
#include <utility>

// Structure Face
#include "Cube.h"
// Structure Rubik

struct Rubik
{
    std::vector<Cube> cubos;
    std::vector<int> IPT;
    int ind_tam = 3 * 2 * 6;
    int num_cubos = 0;
    std::vector<glm::vec3> centros;
    std::vector<glm::vec3> puntos;
    std::vector<std::vector<std::pair<int, char>>> camadas;
    float angulo_i = 0.0f;
    float angulo_f = 90.0f;
    float angulo_i_animacion = 0.0f;
    float angulo_f_animacion = 360.0f;
    float pasos_animacion = 1.0f;
    float pasos = 1.5f;
    float sentido = 1.0f;
    float eje = 0.0f;
    Rubik()
    {
        GenCentrosCubos();
        GenIndicesCamadas();
        num_cubos = centros.size();
        ind_tam *= num_cubos;
        glm::mat4 trans;
        for (int i = 0; i < num_cubos; i++)
        {
            cubos.push_back(Cube());  //aca podriamos poner un parametro para que el cubo de inicialize con diferentes colores o un color
            trans = glm::mat4(1.0f);
            trans = glm::translate(trans, centros[i]);
            cubos[i].Transform(trans, glm::vec3(0.0f, 0.0f, 0.0f), 0);
        }

        GenIndices();
    }
    void TransformBloques(glm::mat4 trans, glm::vec3 c, int op, std::vector<std::pair<int,char>> camada)
    {
        for (int i = 0; i < camada.size(); i++)
        {
            cubos[camada[i].first].Transform(trans, c, op);
        }
    }


    void cambiar_centros(){
        
        glm::vec3 cor = {0.5f, 0.5f, 0.5f};
        
        int cont=0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int e = 0; e < 3; e++)
                {

                    
                    centros[cont]=cor;
                    cont++;
                    //cout<<"centro x: " <<corner_start.x<<" y: "<<corner_start.y<<" z: "<<corner_start.z<<endl; 
                    // rubic[index] = Cube(corner_start, edge_size, textures, index);
                }
            }
        }
    }

    void TransformAnimado(glm::mat4 trans, glm::vec3 c, int op, std::vector<std::pair<int,char>> camada,int ind)
    {
        
       
        if(ind == 0 || ind ==1){
            cubos[camada[1].first].Transform(trans,c,op);
            cubos[camada[7].first].Transform(trans,c,op);
        }
        if(ind == 2 || ind ==3){
            cubos[camada[2].first].Transform(trans,c,op);
            cubos[camada[8].first].Transform(trans,c,op);
        }
        if(ind ==4 || ind ==5){
           cubos[camada[0].first].Transform(trans,c,op);
           cubos[camada[6].first].Transform(trans,c,op);
        }
      
    }



    void Transform(glm::mat4 trans, glm::vec3 c, int op)
    {
        for (int i = 0; i < cubos.size(); i++)
        {
            cubos[i].Transform(trans, c, op);
        }
    }
    std::vector<float> GenEbo()
    {
        std::vector<float> ebo;
        for (int i = 0; i < cubos.size(); i++)
        {
            PushVector(ebo, cubos[i].GenEbo());
        }
        return ebo;
    }
    void PushVector(std::vector<float> &A, std::vector<float> B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            A.push_back(B[i]);
        }
    }
    void GenCentrosCubos()
    {
        float edge_size = 1.0f;
        float distance = 0.0f;
        float aux = edge_size + distance;
        glm::vec3 corner_start = {-aux, -aux, -aux};
        int index = 0;
        
        

        for (int i = 0; i < 3; ++i)
        {
            corner_start.z = -1.0f;
            for (int j = 0; j < 3; j++)
            {
                corner_start.x = -1.0f;
                for (int e = 0; e < 3; e++, index++)
                {

                    // if (index != 16)
                    centros.push_back(corner_start);
                    cout<<"centro x: " <<corner_start.x<<" y: "<<corner_start.y<<" z: "<<corner_start.z<<endl; 
                    // rubic[index] = Cube(corner_start, edge_size, textures, index);
                    corner_start.x += aux;
                }
                corner_start.z += aux;
            }
            corner_start.y += aux;
        }
        
    }
    void GenIndicesCamadas()
    {
        // frontal naranja 
        camadas.push_back({std::make_pair(6, 'G'), std::make_pair(7, 'G'), std::make_pair(8, 'G'), std::make_pair(15, 'G'), std::make_pair(16, 'G'), std::make_pair(17, 'G'), std::make_pair(24, 'G'), std::make_pair(25, 'G'), std::make_pair(26, 'G')});
        // atras blanco
        camadas.push_back({std::make_pair(0, 'B'), std::make_pair(1, 'B'), std::make_pair(2, 'B'), std::make_pair(9, 'B'), std::make_pair(10, 'B'), std::make_pair(11, 'B'), std::make_pair(18, 'B'), std::make_pair(19, 'B'), std::make_pair(20, 'B')});
        // derecha rosado
        camadas.push_back({std::make_pair(8, 'O'), std::make_pair(5, 'O'), std::make_pair(2, 'O'), std::make_pair(17, 'O'), std::make_pair(14, 'O'), std::make_pair(11, 'O'), std::make_pair(26, 'O'), std::make_pair(23, 'O'), std::make_pair(20, 'O')});
        // izquierda - celeste
        camadas.push_back({std::make_pair(6, 'R'), std::make_pair(3, 'R'), std::make_pair(0, 'R'), std::make_pair(15, 'R'), std::make_pair(12, 'R'), std::make_pair(9, 'R'), std::make_pair(24, 'R'), std::make_pair(21, 'R'), std::make_pair(18, 'R')});
        // arriba -verde
        camadas.push_back({std::make_pair(24, 'W'), std::make_pair(25, 'W'), std::make_pair(26, 'W'), std::make_pair(21, 'W'), std::make_pair(22, 'W'), std::make_pair(23, 'W'), std::make_pair(18, 'W'), std::make_pair(19, 'W'), std::make_pair(20, 'W')});
        // abajo -azul
        camadas.push_back({std::make_pair(6, 'Y'), std::make_pair(7, 'Y'), std::make_pair(8, 'Y'), std::make_pair(3, 'Y'), std::make_pair(4, 'Y'), std::make_pair(5, 'Y'), std::make_pair(0, 'Y'), std::make_pair(1, 'Y'), std::make_pair(2, 'Y')});
    }

    //cara celeste camadas[3][8] == 9,19,11,1  -> cambiar sentido -> c1.MoverCamadaSuperior(3)
    //cara verde   camadas[4][3] == 9,19,11,1  -> c1.MoverCamadaSuperior(4)

    bool animacion_atomo(int index,bool parar){
        float aux_sentido = this->sentido;
        float aux_sentido_2 = 1.0f;
        if (index == 0)
            aux_sentido *= -1.0f;
    
        if (angulo_i_animacion == angulo_f_animacion)
        {
            if(parar){
                return false;
            }
            angulo_i_animacion = 0.0f;
        }
        angulo_i_animacion += pasos_animacion;
      

        glm::mat4 trans = glm::mat4(1.0f);  
        
        glm::mat4 trans2 = glm::mat4(1.0f);
        glm::mat4 trans3 = glm::mat4(1.0f);
        glm::mat4 trans4 = glm::mat4(1.0f);
        glm::mat4 trans5 = glm::mat4(1.0f);
        glm::mat4 trans6 = glm::mat4(1.0f);

       
        trans = glm::rotate(trans, glm::radians(pasos * aux_sentido), glm::vec3(1.0f, 0.0f, 0.3f));         //CUBOS DEL MEDIO FRENTE
        trans2 =    glm::rotate(trans2, glm::radians(pasos * aux_sentido_2), glm::vec3(1.0f, 0.0f, -0.3f)); //CUBOS DEL MEDIO TRASERA
        
        trans3 =    glm::rotate(trans3, glm::radians(pasos * aux_sentido), glm::vec3(1.0f, 0.0f, -0.9f));  
        trans4 =    glm::rotate(trans4, glm::radians(pasos * aux_sentido_2), glm::vec3(1.0f, 0.0f, 0.9f));

        trans5 =    glm::rotate(trans5, glm::radians(pasos * aux_sentido), glm::vec3(1.0f, 0.0f, 0.9f));
        trans6 =    glm::rotate(trans6, glm::radians(pasos * aux_sentido_2), glm::vec3(1.0f, 0.0f, -0.9f));
        

        if (index == 0){ 
   
            
            TransformAnimado(trans,glm::vec3(0.5f, 0.5f, 0.5f), 1, camadas[index],index);
            TransformAnimado(trans3,glm::vec3(0.5f, 0.5f, 0.5f), 1, camadas[index],index+2); //nuevoooooooo
            TransformAnimado(trans5,glm::vec3(0.5f, 0.5f, 0.5f), 1, camadas[index],index+4); //nuevoooooooo
            
            TransformAnimado(trans2,glm::vec3(-0.5f, 0.5f, 0.5f), 1, camadas[index+1],index+1); //nuevooooo
            TransformAnimado(trans4,glm::vec3(-0.5f, 0.5f, 0.5f), 1, camadas[index+1],index+3); //nuevooooo
            TransformAnimado(trans6,glm::vec3(-0.5f, 0.5f, 0.5f), 1, camadas[index+1],index+5);
        } 
          
        return true;
    
    }
    

    bool MoverCamadaFrontal(int index)
    {
        float aux_sentido = this->sentido;
        float aux_sentido_2 = 1.0f;
        if (index == 0)
            aux_sentido *= -1.0f;
        if (index == 1)
            aux_sentido *= 1.0f;
        if (angulo_i == (angulo_f))
        {
            angulo_i = 0.0f;
            UpdateCamadaFrontal(index);   
            return true;                 
        }
        angulo_i += pasos;
       
        glm::mat4 trans = glm::mat4(1.0f);  

        trans = glm::rotate(trans, glm::radians(pasos * aux_sentido), glm::vec3(0.0f, 0.0f, 1.0f));  

        if (index == 0){ 
            TransformBloques(trans, glm::vec3(0.5f, 0.5f, 1.5f), 1, camadas[index]); 

        }    
        if (index == 1)         
            TransformBloques(trans, glm::vec3(0.5f, 0.5f, -1.5f), 1, camadas[index]); 
        return false;
    }


    bool MoverCamadaLateral(int index)
    {
        float sentido = this->sentido;
        
        float aux_sentido = this->sentido;
        float aux_sentido_2 = 1.0f;
        if (index == 2)
            sentido *= -1.0f;
        if (index == 3)
            sentido *= 1.0f;
        if (angulo_i == angulo_f)
        {
            angulo_i = 0.0f;
            UpdateCamadaLateral(index);
            return true;
        }
        angulo_i += pasos;
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(pasos * sentido), glm::vec3(1.0f, 0.0f, 0.0f));
        //trans = glm::rotate(trans, glm::radians(pasos * aux_sentido), glm::vec3(0.0f, 0.0f, 1.0f));
        
        
        // std::cout << centros[camadas[index][4]].x << " " << centros[camadas[index][4]].y << " " << centros[camadas[index][4]].z << std::endl;

        if (index == 2){
            
        
            TransformBloques(trans, glm::vec3(0.5f, 0.5f, 0.5f), 1, camadas[index]);
            //TransformBloques(trans, glm::vec3(0.5f, 0.5f, 1.5f), 1, camadas[index]);
        
        
        }    
        if (index == 3)
            TransformBloques(trans, glm::vec3(-0.5f, 0.5f, 0.5f), 1, camadas[index]);

        return false;
    }
    bool MoverCamadaSuperior(int index)
    {
        float sentido = this->sentido;
        if (index == 4)
            sentido *= -1.0f;
        if (index == 5)
            sentido *= 1.0f;
        if (angulo_i == angulo_f)
        {
            angulo_i = 0.0f;
            UpdateCamadaSuperior(index);
            return true;
        }
        angulo_i += pasos;
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(pasos * sentido), glm::vec3(0.0f, 1.0f, 0.0f));
        // std::cout << centros[camadas[index][4]].x << " " << centros[camadas[index][4]].y << " " << centros[camadas[index][4]].z << std::endl;

        if (index == 4)
            TransformBloques(trans, glm::vec3(0.5f, 1.5f, 0.5f), 1, camadas[index]);
        if (index == 5)
            TransformBloques(trans, glm::vec3(0.5f, -0.5f, 0.5f), 1, camadas[index]);

        return false;
    }

    void GenIndices()
    {
        std::vector<int> indices = {0, 1, 2, 0, 2, 3};
        int n = 4;
        for (int i = 0; i < 6 * num_cubos; i++)
        {
            for (int j = 0; j < indices.size(); j++)
            {
                IPT.push_back(indices[j] + i * n);
            }
        }
    }
    void ShowIPT()
    {
        for (int i = 0; i < IPT.size(); i++)
        {
            printf("%5d", IPT[i]);
            if ((i + 1) % 6 == 0)
            {
                printf("\n");
            }
        }
    }
    void UpdateCamadaFrontal(int index)
    {
        std::vector<std::pair<int,char>> aux_camada;
        aux_camada.clear();
        if (this->sentido == 1.0f)
        {
            if (index == 0)
                aux_camada = rotar_90_derecha(camadas[index]);
            if (index == 1)
                aux_camada = rotar_90_izquierda(camadas[index]);
        }
        else
        {
            if (index == 0)
                aux_camada = rotar_90_izquierda(camadas[index]);
            if (index == 1)
                aux_camada = rotar_90_derecha(camadas[index]);
        }

        camadas[index] = aux_camada;

        if (index == 0)
        {
            // Camada Superior
            camadas[4][0] = camadas[index][6];
            camadas[4][1] = camadas[index][7];
            camadas[4][2] = camadas[index][8];
            // Camada inferior
            camadas[5][0] = camadas[index][0];
            camadas[5][1] = camadas[index][1];
            camadas[5][2] = camadas[index][2];
            // Camada Derecha
            camadas[2][6] = camadas[index][8];
            camadas[2][3] = camadas[index][5];
            camadas[2][0] = camadas[index][2];
            // Camada Izquierda
            camadas[3][6] = camadas[index][6];
            camadas[3][3] = camadas[index][3];
            camadas[3][0] = camadas[index][0];
        }
        if (index == 1)
        {
            // Camada Superior
            camadas[4][6] = camadas[index][6];
            camadas[4][7] = camadas[index][7];
            camadas[4][8] = camadas[index][8];
            // Camada inferior
            camadas[5][6] = camadas[index][0];
            camadas[5][7] = camadas[index][1];
            camadas[5][8] = camadas[index][2];
            // Camada Derecha
            camadas[2][8] = camadas[index][8];
            camadas[2][5] = camadas[index][5];
            camadas[2][2] = camadas[index][2];
            // Camada Izquierda
            camadas[3][8] = camadas[index][6];
            camadas[3][5] = camadas[index][3];
            camadas[3][2] = camadas[index][0];
        }
    }

    void UpdateCamadaLateral(int index)
    {
        std::vector<std::pair<int,char>> aux_camada;
        aux_camada.clear();

        if (this->sentido == 1.0f)
        {
            if (index == 2)
                aux_camada = rotar_90_derecha(camadas[index]);
            if (index == 3)
                aux_camada = rotar_90_izquierda(camadas[index]);
        }
        else
        {
            if (index == 2)
                aux_camada = rotar_90_izquierda(camadas[index]);
            if (index == 3)
                aux_camada = rotar_90_derecha(camadas[index]);
        }

        camadas[index] = aux_camada;
        if (index == 2)
        {
            // Camada Frontal
            camadas[0][8] = camadas[index][6];
            camadas[0][5] = camadas[index][3];
            camadas[0][2] = camadas[index][0];
            // Camada Trasera
            camadas[1][8] = camadas[index][8];
            camadas[1][5] = camadas[index][5];
            camadas[1][2] = camadas[index][2];
            // Camada Superior
            camadas[4][8] = camadas[index][8];
            camadas[4][5] = camadas[index][7];
            camadas[4][2] = camadas[index][6];
            // Camada inferior
            camadas[5][8] = camadas[index][2];
            camadas[5][5] = camadas[index][1];
            camadas[5][2] = camadas[index][0];
        }
        if (index == 3)
        {
            // Camada Frontal
            camadas[0][6] = camadas[index][6];
            camadas[0][3] = camadas[index][3];
            camadas[0][0] = camadas[index][0];
            // Camada Trasera
            camadas[1][6] = camadas[index][8];
            camadas[1][3] = camadas[index][5];
            camadas[1][0] = camadas[index][2];
            // Superior
            camadas[4][6] = camadas[index][8];
            camadas[4][3] = camadas[index][7];
            camadas[4][0] = camadas[index][6];
            // Inferior
            camadas[5][6] = camadas[index][2];
            camadas[5][3] = camadas[index][1];
            camadas[5][0] = camadas[index][0];
        }
    }
    void UpdateCamadaSuperior(int index)
    {
        std::vector<std::pair<int,char>> aux_camada;
        aux_camada.clear();

        if (this->sentido == 1.0f)
        {
            if (index == 4)
                aux_camada = rotar_90_derecha(camadas[index]);
            if (index == 5)
                aux_camada = rotar_90_izquierda(camadas[index]);
        }
        else
        {
            if (index == 4)
                aux_camada = rotar_90_izquierda(camadas[index]);
            if (index == 5)
                aux_camada = rotar_90_derecha(camadas[index]);
        }

        camadas[index] = aux_camada;

        if (index == 4)
        {
            // Camada frontal
            camadas[0][8] = camadas[index][2];
            camadas[0][7] = camadas[index][1];
            camadas[0][6] = camadas[index][0];
            // Camada trasera
            camadas[1][8] = camadas[index][8];
            camadas[1][7] = camadas[index][7];
            camadas[1][6] = camadas[index][6];
            // Camada derecha
            camadas[2][8] = camadas[index][8];
            camadas[2][7] = camadas[index][5];
            camadas[2][6] = camadas[index][2];
            // Camada izquierda
            camadas[3][8] = camadas[index][6];
            camadas[3][7] = camadas[index][3];
            camadas[3][6] = camadas[index][0];
        }
        if (index == 5)
        {
            // Camada frontal
            camadas[0][0] = camadas[index][0];
            camadas[0][1] = camadas[index][1];
            camadas[0][2] = camadas[index][2];
            // Camada trasera
            camadas[1][0] = camadas[index][6];
            camadas[1][1] = camadas[index][7];
            camadas[1][2] = camadas[index][8];
            // Camada derecha
            camadas[2][2] = camadas[index][8];
            camadas[2][1] = camadas[index][5];
            camadas[2][0] = camadas[index][2];
            // Camada izquierda
            camadas[3][2] = camadas[index][6];
            camadas[3][1] = camadas[index][3];
            camadas[3][0] = camadas[index][0];
        }
    }
    std::vector<std::pair<int,char>> rotar_90_izquierda(std::vector<std::pair<int,char>> a)
    {
      

        // std::cout << "Transformado" << std::endl;
        // ShowMatrix(destino);

        return {a[6], a[3], a[0], a[7], a[4], a[1], a[8], a[5], a[2]};
    }
    std::vector<std::pair<int,char>> rotar_90_derecha(std::vector<std::pair<int,char>> a)
    {
       

        // std::cout << "Transformado" << std::endl;
        // ShowMatrix(destino);

        return {a[2], a[5], a[8], a[1], a[4], a[7], a[0], a[3], a[6]};
    }

    void ShowMatrix(std::vector<std::vector<int>> a)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void ShowCamadas()
    {
        for (int i = 0; i < camadas.size(); i++)
        {
            std::cout << "Camada: " << i << " -> ";
            for (int j = 0; j < camadas[i].size(); j++)
            {
                std::cout << camadas[i][j].first << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};
#endif