#ifndef FACE_H
#define FACE_H


#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

using namespace std;


#include "Point.h"

// Estructura Cara
struct Face
{
    std::vector<Point> vertices;
    std::vector<glm::vec2> color;
    Face(float center, char axis, char col)
    {
        std::vector<std::vector<float>> g_v = GenVertices(center,axis);
        //std::cout << g_v.size() << std::endl;
        GenColor(col);
        for (int i = 0; i < g_v.size(); i++)
        {
            vertices.push_back(Point(g_v[i],color[i]));
        }
    }
    void Transform(glm::mat4 transform, glm::vec3 c, int op)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i].Transform(transform, c, op);
        }
    }
    void GenColor(char col) {
        color.push_back(glm::vec2(0.0f, 0.0f));
        color.push_back(glm::vec2(0.1f, 0.0f));
        color.push_back(glm::vec2(0.1f, 0.1f));
        color.push_back(glm::vec2(0.0f, 0.1f));
        if (col == 'y')
        {
            AplicarColor(0.0f);
        }
        if (col == 'g')
        {
            AplicarColor(0.5f);
        }
        if (col == 'r')
        {
            AplicarColor(0.4f);//0.6 ES PARA ROJO
        }
        if (col == 'b')
        {
            AplicarColor(0.3f);
        }
        if (col == 'o')
        {
            AplicarColor(0.2f);
        }
        if (col == 'w')
        {
            AplicarColor(0.1f);
        }
    }
    void AplicarColor(float aumentar) {
        for (int i = 0; i < color.size(); i++)
        {
            color[i].x += aumentar;
        }
    }
    std::vector<std::vector<float>> GenVertices(float center, char axis)
    {
        std::vector<std::vector<float>> vertices_face;
        if (axis == 'f')
        {
            vertices_face.push_back({center - 0.5f, center - 0.5f, 0.0f});
            vertices_face.push_back({center + 0.5f, center - 0.5f, 0.0f});
            vertices_face.push_back({center + 0.5f, center + 0.5f, 0.0f});
            vertices_face.push_back({center - 0.5f, center + 0.5f, 0.0f});
        }
        if (axis == 't')
        {
            vertices_face.push_back({ center + 0.5f, center - 0.5f, 1.0f });
            vertices_face.push_back({ center - 0.5f, center - 0.5f, 1.0f });
            vertices_face.push_back({ center - 0.5f, center + 0.5f, 1.0f });
            vertices_face.push_back({ center + 0.5f, center + 0.5f, 1.0f });
        }
        if (axis == 'i')
        {
            vertices_face.push_back({0.0f, center - 0.5f, center + 0.5f});
            vertices_face.push_back({0.0f, center - 0.5f, center - 0.5f});
            vertices_face.push_back({0.0f, center + 0.5f, center - 0.5f});
            vertices_face.push_back({0.0f, center + 0.5f, center + 0.5f});
        }
        if (axis == 'd')
        {
            vertices_face.push_back({ 1.0f, center - 0.5f, center - 0.5f });
            vertices_face.push_back({ 1.0f, center - 0.5f, center + 0.5f });
            vertices_face.push_back({ 1.0f, center + 0.5f, center + 0.5f });
            vertices_face.push_back({ 1.0f, center + 0.5f, center - 0.5f });
        }
        if (axis == 'u')
        {
            vertices_face.push_back({center - 0.5f, 0.0f ,center - 0.5f});
            vertices_face.push_back({center + 0.5f, 0.0f ,center - 0.5f});
            vertices_face.push_back({center + 0.5f, 0.0f ,center + 0.5f});
            vertices_face.push_back({center - 0.5f, 0.0f ,center + 0.5f});
        }
        if (axis == 'a')
        {
            vertices_face.push_back({ center - 0.5f, 1.0f ,center - 0.5f });
            vertices_face.push_back({ center + 0.5f, 1.0f ,center - 0.5f });
            vertices_face.push_back({ center + 0.5f, 1.0f ,center + 0.5f });
            vertices_face.push_back({ center - 0.5f, 1.0f ,center + 0.5f });
        }
        return vertices_face;
    }
    void PushVector(std::vector<float>& A, std::vector<float> B) {
        for (int i = 0; i < B.size(); i++)
        {
            A.push_back(B[i]);
        }
    }
    std::vector<float> GenEBO() {
        std::vector<float> ebo;
        for (int i = 0; i < vertices.size(); i++)
        {
            PushVector(ebo, vertices[i].Gen_EBO());
        }
        return ebo;
    }

   
    void ShowFace(){
        std::cout << " *  Coordenadas Vertices *   *H*    *  Texture  *" << std::endl;	
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i].ShowPoint();
        }
    }
};

#endif