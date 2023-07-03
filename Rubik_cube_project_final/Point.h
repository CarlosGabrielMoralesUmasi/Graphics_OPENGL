#ifndef POINT_H
#define POINT_H



#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
using namespace std;

// Estructura point
struct Point
{
    glm::vec4 point;
    glm::vec2 texture;
    
    Point(std::vector<float> point, glm::vec2 texture)
    {
        for (int i = 0; i < point.size(); i++)
        {
            this->point[i] = point[i];
        }
        this->point[3] = 1.0f;
        this->texture = texture;
    }
    void Transform(glm::mat4 transform, glm::vec3 c, int op)
    {
        glm::vec4 centro = glm::vec4(c, 1.0f);
        if (op) {
            this->point = transform * (this->point - centro) + centro;
        }
        else {
            this->point = transform * this->point;
        }

    }
    std::vector<float> Gen_EBO()
    {
        std::vector<float> EBO;
        for (int i = 0; i < 3; i++)
        {
            EBO.push_back(this->point[i]);
        }
        for (int i = 0; i < 2; i++)
        {
            EBO.push_back(this->texture[i]);
        }
        return EBO;
    }
    void ShowPoint()
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%8.2f", this->point[i]);
        }
        for (int i = 0; i < 2; i++)
        {
            printf("%8.2f", this->texture[i]);
        }
        printf("\n");
    }
};

#endif