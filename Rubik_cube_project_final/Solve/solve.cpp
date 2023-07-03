#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "solve.h"
#include <string>
#include <vector>
#include <random>
#pragma warning(disable:4996)

std::string solver(char* cube) {
    char* facelets = cube;
    char* sol = solution(
        facelets,
        24,
        1000,
        0,
        "cache"
    );
    if (sol == NULL)return "No answer";
    std::string answer;
    for (int i = 0; sol[i] != '\0'; ++i) {
        answer.push_back(sol[i]);
    }
    return answer;
}

std::vector<std::string> get_solution(std::string Cube) {
    char* cube = new char[(int)Cube.size()];
    for (int i = 0; i < (int)Cube.size(); ++i) {
        cube[i] = Cube[i];
    }
    std::string solution = solver(cube);
    std::vector<std::string> the_solution;
    std::string temp = "";
    for (int i = 0; i < (int)solution.size(); ++i) {
        if (solution[i] == ' ') {
            the_solution.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(solution[i]);
        }
    }
    if((int)temp.size())the_solution.push_back(temp);
    return the_solution;
}

std::string SuperSolve(std::string desorden){
    std::vector<std::string> cubo;
    while(!desorden.empty()){
        if(desorden[1] == '\''){
            cubo.push_back(desorden.substr(0, 2));
            desorden.erase(desorden.begin());
            desorden.erase(desorden.begin());
        }else{
            cubo.push_back(desorden.substr(0, 1));
            desorden.erase(desorden.begin());
        }
    }

    //for (int i = 0; cubo.size() ; i++){
    //    std::cout << cubo[i] << std::endl;
    //}
     std::vector<std::string> move = get_solution(to_cube_not(cubo));
     /*for (int i = 0; i < move.size(); i++)
     {
         std::cout << move[i] << std::endl;
     }*/

     string solution = "";
     for (int i = 0; i < move.size(); i++)
     {
         if (move[i].size() == 1) {
             solution += move[i];
         }
         else {
             if (move[i][1] == '\'')
             {
                 solution += move[i][0];
                 solution += move[i][0];
                 solution += move[i][0];
             }
             else {
                 solution += move[i][0];
                 solution += move[i][0];
             }
         }
     }

     return solution;
}