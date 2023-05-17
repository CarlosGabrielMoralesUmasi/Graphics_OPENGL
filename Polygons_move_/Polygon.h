#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <unistd.h> 
#include "Matrices.h"
using namespace std;

// ---------------------------------------------------------------------------------------------
struct Polygono{

    vector<float> vertices;
    vector<float> directions;
    float polygon_color_R=0,polygon_color_G=0,polygon_color_B=0;
    float vel=2;
    ///
    Polygono(vector<float> temp_vertices,float R,float G,float B){
        vertices.reserve(temp_vertices.size()+((temp_vertices.size()/3)*3));
        for(int j=1;j<=temp_vertices.size();++j){
			vertices.push_back(temp_vertices[j-1]);
			//RGB
			if(j%3==0){
				vertices.push_back(R);
				vertices.push_back(G);
				vertices.push_back(B);
			}	
		}
        directions.reserve((temp_vertices.size()/3)*2);
    }


    //cambiar color
    void cambiarcolor(float R,float G,float B){
        int j=1;
        for(int i=0;i<vertices.size()/6;i++){
            int position=j*3;
            vertices[position]=R;
            vertices[position+1]=G;
            vertices[position+2]=B;
            j+=2;
		}
    }
    void draw(GLFWwindow* window,bool wired=false){
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size()* sizeof(vertices), this->vertices.data(), GL_STATIC_DRAW);
        if(wired)
            glDrawArrays(GL_LINE_LOOP, 0, vertices.size()/6);   
        else
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size()/6);   
    }

    void drawLine(GLFWwindow* window,bool wired=true){
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size()* sizeof(vertices), this->vertices.data(), GL_STATIC_DRAW);
        glDrawArrays(GL_LINE_LOOP, 0, vertices.size()/6);   
    }

    void drawPoint(GLFWwindow* window){
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size()* sizeof(vertices), this->vertices.data(), GL_STATIC_DRAW);
        glDrawArrays(GL_POINTS, 0, vertices.size()/6);   
           
    }
    vector<float> get_min_max_x(){
        vector<float> result;
        result.reserve(2);
        result.resize(2);
        result[0]=vertices[0];
        result[1]=vertices[0];
        for(int i=0;i<vertices.size()/6;i++){
            int pos=i*6;
            if(vertices[pos]<result[0])
                result[0]=vertices[pos];
            else if(vertices[pos]>result[1])
                result[1]=vertices[pos];
        }
        return result;
    }
    vector<float> get_min_max_y(){
        vector<float> result;
        result.reserve(2);
        result.resize(2);
        result[0]=vertices[1];
        result[1]=vertices[1];
        for(int i=0;i<vertices.size()/6;i++){
            int pos=i*6;
            if(vertices[pos+1]<result[0])
                result[0]=vertices[pos+1];
            else if(vertices[pos+1]>result[1])
                result[1]=vertices[pos+1];
        }
        return result;
    }
    ///traslaciones
    void trans(float new_x, float new_y, float new_z) {
        for (int i = 0; i < vertices.size() / 6; i++) {
            int pos = i * 6;
            vertices[pos] += new_x;
            vertices[pos + 1] += new_y;
            vertices[pos + 2] += new_z;
        }
    }
    void pro_traslate(vector<float> point){
        Matriz m1(4,4);
        Matriz m2(vertices);
        Matriz m3(4,4);
        m1.create_matrix_point(point);
        Multiply(m1,m2,m3);
        m3.export_to_vertex(vertices);
    }
    ///rotaciones 
    void pro_rotation_x(float angle){
        Matriz m1(4,4);
        Matriz m2(vertices);
        Matriz m3(4,(vertices.size()/6));

        m1.convert_matrix_rotation_x(angle);
        Multiply(m1,m2,m3);
        m3.export_to_vertex(vertices);
    }
 
    void pro_rotation_y(float angle){
        Matriz m1(4,4);
        Matriz m2(vertices);
        Matriz m3(4,(vertices.size()/6));
        
        m1.convert_matrix_rotation_y(angle);
        Multiply(m1,m2,m3);
        m3.export_to_vertex(vertices);
    }

    void pro_rotation_z(float angle) {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        m1.convert_matrix_rotation_z(angle);
        Multiply(m1, m2, m3);
        m3.export_to_vertex(vertices);

    }
    /*void pro_rotation_eje(float angle) {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        m1.convert_matrix_rotation_origin(angle);  // Llamada a la función modificada
        Multiply(m2, m1, m3);  // Cambio de orden en la multiplicación de matrices
        m3.export_to_vertex(vertices);
    }*/
    /*void pro_rotation_eje(float angle) {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        // Calcular el centro del cuadrado
        float centerX = 0.0f;
        float centerY = 0.0f;
        for (int i = 0; i < vertices.size(); i += 6) {
            centerX += vertices[i];
            centerY += vertices[i + 1];
        }
        centerX /= (vertices.size() / 6);
        centerY /= (vertices.size() / 6);

        // Mover el centro del cuadrado al origen
        //m1.convert_matrix_traslation(-centerX, -centerY, 0.0f);

        // Realizar la rotación en torno al origen
        m1.convert_matrix_rotation_z(angle);

        // Mover el centro del cuadrado de regreso
        //m2.convert_matrix_traslation(centerX, centerY, 0.0f);

        // Aplicar las transformaciones
        Multiply(m1, m2, m3);
        m3.export_to_vertex(vertices);
}*/

    ///escalados
    void escalao(float x, float y, float z) {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        m1.convert_matrix_scale(x, y, z);
        Multiply(m1, m2, m3);
        m3.export_to_vertex(vertices);
    }
    void escalaomas() {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        m1.convert_escalado_mas();
        Multiply(m1, m2, m3);
        m3.export_to_vertex(vertices);
    }
    void escalaomenos() {
        Matriz m1(4, 4);
        Matriz m2(vertices);
        Matriz m3(4, (vertices.size() / 6));

        m1.convert_escalado_menos();
        Multiply(m1, m2, m3);
        m3.export_to_vertex(vertices);
    }
    //imprimir
    void print_position() {
    string ejes[3] = {"p1", "p2", "p3"};
    for (int i = 0; i < vertices.size() / 3; i++) {
        int pos = i * 3;
        cout << ejes[i] << ": ";
        cout << vertices[pos] << "\t";
        cout << vertices[pos + 1] << "\t";
        cout << vertices[pos + 2] << endl;
    }
    cout << "///////////////////////\n";
    }

};
