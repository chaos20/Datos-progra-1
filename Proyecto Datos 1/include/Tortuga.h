#ifndef TORTUGA_H
#define TORTUGA_H
#include <SDL.h>
#include <cmath>
#include <stdexcept>
#include "DLinkedList.h"
#include "LinkedStack.h"
#define DEFAULT_X 500
#define DEFAULT_Y 600
#define DEFAULT_ANGLE 0

using namespace std;

class Tortuga{
private:
    double x;
    double y;
    double angle;

public:

    Tortuga(){
        angle = DEFAULT_ANGLE;
        x = DEFAULT_X;
        y = DEFAULT_Y;
    }

    ~Tortuga(){
    }

    DLinkedList<string>* curvaDeDragon(int iterations){
        string curve = "";
        DLinkedList<string> *curvaDeDragon = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            curve = "90";
            if(i == 0)
                curvaDeDragon->insert(curve);
            else{
                curvaDeDragon->goToStart();
                do{
                    if(curvaDeDragon->getPos() % 2 == 0){
                        curvaDeDragon->insert(curve);
                        if(curve == "90")
                            curve = "-90";
                        else
                            curve = "90";
                    }
                    curvaDeDragon->next();
                }while(curvaDeDragon->atEnd() == false);
                curvaDeDragon->append(curve);
            }
        }
        if(iterations > 0){
            curvaDeDragon->goToStart();
            do{
                if(curvaDeDragon->getPos() % 2 == 0){
                    curvaDeDragon->insert("A");
                }
                curvaDeDragon->next();
            } while(curvaDeDragon->atEnd() == false);
            curvaDeDragon->append("A");
        }
        setAngle(270);
        setX(500);
        setY(300);
        return curvaDeDragon;
    }

    DLinkedList<string>* flechaDeSierpinski(int iterations){
        string curve = "60";
        DLinkedList<string> *flechaDeSierpinski = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            if(i == 0){
                flechaDeSierpinski->insert(curve);
                flechaDeSierpinski->insert(curve);
            }else{
                flechaDeSierpinski->goToStart();
                if(curve == "60")
                    curve = "-60";
                else
                    curve = "60";
                do{
                    if(flechaDeSierpinski->getPos() % 3 == 0){
                        flechaDeSierpinski->insert(curve);
                        flechaDeSierpinski->insert(curve);
                        if(curve == "60")
                            curve = "-60";
                        else
                            curve = "60";
                    }
                    flechaDeSierpinski->next();
                }while(flechaDeSierpinski->atEnd() == false);
                flechaDeSierpinski->append(curve);
                flechaDeSierpinski->append(curve);
            }
        }
        if(iterations > 0){
            flechaDeSierpinski->goToStart();
            do{
                if(flechaDeSierpinski->getPos() % 2 == 0){
                    flechaDeSierpinski->insert("A");
                }
                flechaDeSierpinski->next();
            } while(flechaDeSierpinski->atEnd() == false);
            flechaDeSierpinski->append("A");
        }
        setAngle(90);
        setX(500);
        setY(450);
        return flechaDeSierpinski;
    }

    DLinkedList<string>* curvaDeLevy(int iterations){
        DLinkedList<string> *curvaDeLevy = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                curvaDeLevy->insert("A");
            else{
                curvaDeLevy->goToStart();
                do{
                    if(curvaDeLevy->getElement() == "A"){
                        curvaDeLevy->remove();
                        curvaDeLevy->insert("45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("45");
                    }
                    curvaDeLevy->next();
                }while(curvaDeLevy->atEnd() == false);
            }
        }
        setAngle(270);
        setX(600);
        setY(300);
        return curvaDeLevy;
    }

    DLinkedList<string>* arbolBinario(int iterations){
        DLinkedList<string> *arbolBinario = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                arbolBinario->insert("H");
            else{
                arbolBinario->goToStart();
                do{
                    if(arbolBinario->getElement() == "H"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("(");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                        arbolBinario->next();
                        arbolBinario->insert(")");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                    }else if(arbolBinario->getElement() == "R"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("R");
                    }
                    arbolBinario->next();
                }while(arbolBinario->atEnd() == false);
            }
        }
        setAngle(180);
        setX(500);
        setY(600);
        return arbolBinario;
    }

    DLinkedList<string>* planta(int iterations){
        DLinkedList<string> *planta = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                planta->insert("X");
            else{
                planta->goToStart();
                do{
                    if(planta->getElement() == "X"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("25");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("-25");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("-25");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("-25");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("25");
                        planta->next();
                        planta->insert("X");
                    }else if(planta->getElement() == "A"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("A");
                    }
                    planta->next();
                }while(planta->atEnd() == false);
            }
        }
        setAngle(180);
        setX(500);
        setY(650);
        return planta;
    }

    void draw(DLinkedList<string> *fractal, bool isArbol = false){
        bool finish = false;
        double newY;
        double newX;
        int fragmentSize = 5;
        if(isArbol){
            fragmentSize = 1;
        }
        LinkedStack<double> fractalStack;
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            SDL_Window* window = NULL;
            SDL_Renderer* renderer = NULL;

            if (SDL_CreateWindowAndRenderer(1300, 700, 0, &window, &renderer) == 0) {
                SDL_bool done = SDL_FALSE;

                while (!done) {
                    SDL_Event event;

                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);

                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                    if(!finish){
                        for(fractal->goToStart(); !fractal->atEnd(); fractal->next()){
                            if(fractal->getElement() == "A" || fractal->getElement() == "R" || fractal->getElement() == "H"){
                                double angleRadians = (angle * M_PI) / 180;
                                newX = (sin(angleRadians) * fragmentSize) + x;
                                newY = (cos(angleRadians) * fragmentSize) + y;
                                SDL_RenderDrawLine(renderer, x, y, newX, newY);
                                SDL_RenderPresent(renderer);
                                x = newX;
                                y = newY;
                            }else if(fractal->getElement() == "("){
                                fractalStack.push(x);
                                fractalStack.push(y);
                                fractalStack.push(angle);
                                if(isArbol){
                                    if(angle - 45 < 0){
                                        angle = 360 - ((angle - 45) * -1);
                                    }else{
                                        angle = angle - 45;
                                    }
                                }
                            }else if(fractal->getElement() == ")"){
                                setAngle(fractalStack.pop());
                                setY(fractalStack.pop());
                                setX(fractalStack.pop());
                                if(isArbol){
                                    if(angle + 45 > 360){
                                        angle = (angle + 45) - 360;
                                    }else if(angle + 45 == 360){
                                        angle = 0;
                                    }else{
                                        angle = angle + 45;
                                    }
                                }
                            }else if(fractal->getElement() == "X"){
                            }else{
                                string stringAngle = fractal->getElement();
                                int intAngle = atoi(stringAngle.c_str());
                                if(intAngle >= 0){
                                    if(angle + intAngle == 360){
                                        angle = 0;
                                    }else if(angle + intAngle > 360){
                                        angle = (angle + intAngle) - 360;
                                    }else{
                                        angle = angle + intAngle;
                                    }
                                }else{
                                    if(angle + intAngle < 0){
                                        angle = 360 - ((angle + intAngle) * -1);
                                    }else{
                                        angle = angle + intAngle;
                                    }
                                }
                            }
                        }
                        finish = true;
                    }
                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            done = SDL_TRUE;
                        }
                    }
                }
            }

            if (renderer) {
                SDL_DestroyRenderer(renderer);
            }
            if (window) {
                SDL_DestroyWindow(window);
            }
        }
        SDL_Quit();
    }

    void setAngle(double pAngle){
        angle = pAngle;
    }

    void setX (double pX){
        x = pX;
    }

    void setY (double pY){
        y = pY;
    }
};

#endif // TORTUGA_H
