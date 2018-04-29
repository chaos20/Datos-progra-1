#include <iostream>
#include "Tortuga.h"

using namespace std;

#include <SDL.h>

int main(int argc, char* argv[]){
    Tortuga myTortuga;
    bool keepRunning = true;
    bool validIterations = true;
    string fractalOption = "";
    string iterations;
    while(keepRunning){
        cout << "Digite una opcion:" << "\n" << "    1. Curva de Dragon" << "\n" << "    2. Flecha de Sierpinski" << "\n" << "    3. Curva de Levy" << "\n" << "    4. Arbol Binario" << "\n" << "    5. Planta" << "\n" << "    6. Salir" << endl << endl;
        cin >> fractalOption;
        validIterations = true;
        if(fractalOption == "1"){
            while(validIterations){
                cout << "Digite la cantidad de iteraciones con las que desea el fractal: ";
                cin >> iterations;
                int intIterations = atoi(iterations.c_str());
                if(intIterations <= 0){
                    cout << "Digite un numero entero mayor a 0" << endl;
                }else{
                    DLinkedList<string> *curvaDeDragon = myTortuga.curvaDeDragon(intIterations);
                    myTortuga.draw(curvaDeDragon);
                    validIterations = false;
                }
            }
        }
        else if(fractalOption == "2"){
            while(validIterations){
                cout << "Digite la cantidad de iteraciones con las que desea el fractal: ";
                cin >> iterations;
                int intIterations = atoi(iterations.c_str());
                if(intIterations <= 0){
                    cout << "Digite un numero entero mayor a 0" << endl;
                }else{
                    DLinkedList<string> *flechaDeSierpinski = myTortuga.flechaDeSierpinski(intIterations);
                    myTortuga.draw(flechaDeSierpinski);
                    validIterations = false;
                }
            }
        }
        else if(fractalOption == "3"){
            while(validIterations){
                cout << "Digite la cantidad de iteraciones con las que desea el fractal: ";
                cin >> iterations;
                int intIterations = atoi(iterations.c_str());
                if(intIterations <= 0){
                    cout << "Digite un numero entero mayor a 0" << endl;
                }else{
                    DLinkedList<string> *curvaDeLevy = myTortuga.curvaDeLevy(intIterations);
                    myTortuga.draw(curvaDeLevy);
                    validIterations = false;
                }
            }
        }
        else if(fractalOption == "4"){
            while(validIterations){
                cout << "Digite la cantidad de iteraciones con las que desea el fractal: ";
                cin >> iterations;
                int intIterations = atoi(iterations.c_str());
                if(intIterations <= 0){
                    cout << "Digite un numero entero mayor a 0" << endl;
                }else{
                    DLinkedList<string> *arbolBinario = myTortuga.arbolBinario(intIterations);
                    myTortuga.draw(arbolBinario, true);
                    validIterations = false;
                }
            }
        }
        else if(fractalOption == "5"){
            while(validIterations){
                cout << "Digite la cantidad de iteraciones con las que desea el fractal: ";
                cin >> iterations;
                int intIterations = atoi(iterations.c_str());
                if(intIterations <= 0){
                    cout << "Digite un numero entero mayor a 0" << endl;
                }else{
                    DLinkedList<string> *planta = myTortuga.planta(intIterations);
                    myTortuga.draw(planta);
                    validIterations = false;
                }
            }
        }
        else if(fractalOption == "6"){
            keepRunning = false;
        }
        else{
            cout << "Digite una opcion valida" << endl;
        }
    }
    return 0;
}
