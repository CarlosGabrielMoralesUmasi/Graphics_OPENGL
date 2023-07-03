#ifndef CUBE_H
#define CUBE_H

// GLM Graphics

#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// C++ Standard
#include <iostream>
#include <vector>
#include <string>

// Structure Face
#include "Face.h"
// Structure Face
struct Cube
{
    std::vector<Face> faces;
    glm::vec3 center;
    std::vector<int> IPT;
    std::string mira = "-z";
    Cube()
    {
        GenFaces();
        std::vector<int> indices = {0, 1, 2, 0, 2, 3};
        int n = 4;
        for (int i = 0; i < faces.size(); i++)
        {
            for (int j = 0; j < indices.size(); j++)
            {
                IPT.push_back(indices[j] + i * n);
            }
        }
    }
    void GenFaces()
    {
        faces.push_back(Face(0.5f, 'f', 'y'));
        faces.push_back(Face(0.5f, 't', 'o')); //aca puedes cambiar los colores a cubo de solo un color
        faces.push_back(Face(0.5f, 'i', 'r'));
        faces.push_back(Face(0.5f, 'd', 'b'));
        faces.push_back(Face(0.5f, 'u', 'g'));
        faces.push_back(Face(0.5f, 'a', 'w'));
    }

    std::vector<float> GenEbo()
    {
        std::vector<float> ebo;
        for (int i = 0; i < faces.size(); i++)
        {
            PushVector(ebo, faces[i].GenEBO());
        }
        return ebo;
    }
    void Transform(glm::mat4 transform, glm::vec3 c,int op)
    {
        for (int i = 0; i < faces.size(); i++)
        {
            faces[i].Transform(transform,c, op);
        }
    }
    void PushVector(std::vector<float> &A, std::vector<float> B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            A.push_back(B[i]);
        }
    }
    void ShowCube()
    {
        for (int i = 0; i < faces.size(); i++)
        {
            faces[i].ShowFace();
        }
    }
    void ShowEBO()
    {
        std::vector<float> ebo = GenEbo();
        //std::cout << ebo.size() / 5 << std::endl;
        for (int i = 0; i < ebo.size(); i++)
        {
            printf("%8.2f", ebo[i]);
            if ((i + 1) % 5 == 0)
            {
                printf("\n");
            }
        }
    }
    void ShowIPT()
    {
        for (int i = 0; i < IPT.size(); i++){
            printf("%5d", IPT[i]);
            if ((i + 1) % 6 == 0)
            {
                printf("\n");
            }
        }
    }
};

#endif