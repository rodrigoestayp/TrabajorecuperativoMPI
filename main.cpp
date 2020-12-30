#include <iostream>
#include <cstdlib>
#include <cmath>
#include <mpi.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;


int main(int argc, char** argv ){
    //Lectura de primer archivo csv -> smi.csv
    //Inicialización de variables

    std::ifstream leerDesde;
    std::string linea = "";
    std::string word = "";
    leerDesde.open(argv[1]);
    std::vector<int>  ano_smi;
    std::vector<float> valorsmi;

    // Control de error, en caso de que falle el path
    if(leerDesde.fail()){
        std::cout << "El path de la ruta del archivo /smi.csv es erroneo, porfavor verificar "  << '\n';
        std::exit(1);
    }

    // Funcion de lectura de segundo archivo csv -> smi
    while(std::getline(leerDesde, linea)){
        if(linea[0]== '"'){

            std::stringstream datosEnProceso(linea);

            std::getline(datosEnProceso, word, ';');
            std::stringstream datos(word);
            std::string str1(word);
            str1.erase(std::remove(str1.begin(), str1.end(), '"'),
            str1.end());
            ano_smi.push_back(stoi(str1));

            std::getline(datosEnProceso, word, ';');
            std::stringstream datoss(word);
            std::string str2(word);
            str2.erase(std::remove(str2.begin(), str2.end(), '"'),
            str2.end());
            valorsmi.push_back(stof(str2));

         }
    }
    // funcion de lectura de segundo archivo csv -> dollars
    // Inicialización de variables

    std::ifstream leerDesde2;
    std::string linea2 = "";
    std::string word2 = "";
    leerDesde2.open(argv[2]);
    std::vector<int> ano_dollars;  
    std::vector<float> valordollars;

    // Control de error, en caso de que falle el path
    if(leerDesde2.fail()){
        std::cout << "El path de la ruta del archivo /dollars.csv es erroneo, porfavor verificar "  << '\n';
        std::exit(1);
    } 

    // Funcion de lectura de segundo archivo csv -> dollars
    while(std::getline(leerDesde2, linea2)){
        if(linea2[0]== '"'){

            std::stringstream datosEnProceso(linea2);
            std::getline(datosEnProceso, word2, ';');
            std::stringstream datos(word2);
            std::string str1(word2);
            str1.erase(std::remove(str1.begin(), str1.end(), '"'),
            str1.end());
            str1.erase(4);
            //std::cout << str1 << '\n';
            ano_dollars.push_back(stoi(str1));

            std::getline(datosEnProceso, word2, ';');
            std::stringstream datoss(word2);
            std::string str2(word2);
            str2.erase(std::remove(str2.begin(), str2.end(), '"'),
            str2.end());
            //std::cout << str2 << '\n';
            valordollars.push_back(stof(str2));

         }  

    }
    //Sacar promedio y funcion de distrubucion de valores.
    int contador=0;
    float suma=0;
    float promedio=0;
    int largodollars = ano_dollars.size();
    int largo_smi= ano_smi.size();
    std::vector<float> valorpromdollars, pesodolar , sumas;
    std::vector<int> contadores;
    for(int i = 0;i<largo_smi ;i++){
        for(int j=0; j< largodollars ; j++){
            if (ano_dollars[j] == ano_smi[i])
            {
                contador++;
                suma= suma + valordollars[j];
            }
        }
        promedio= suma/contador;
        contadores.push_back(contador);
        sumas.push_back(suma);
        valorpromdollars.push_back(promedio);
        pesodolar.push_back(valorsmi[i]/valorpromdollars[i]);
        contador=0;
        suma=0;
    }
    // Funcion para crear la funcion de la regresion lineal 
    // Inicialización de variables
    float sumatoriaXY = 0;
    float x2 = 0;
    float sumX = 0;
    float SumY = 0;
    float m = 0;
    float b = 0;

    for(int i = 0;i< largo_smi ;i++){
        sumatoriaXY = sumatoriaXY + (pesodolar[i] * ano_smi[i]);
        x2 = x2 + (ano_smi[i] * ano_smi[i]);
        sumX = sumX + ano_smi[i];
        SumY = SumY + pesodolar[i];
    }
    m= ((25*sumatoriaXY) - (sumX*SumY)) / ((25*x2) - (sumX*sumX));
    b= (SumY/25) - (m * (sumX/25));

    // Muestra de datos y resultados 
    cout << "                         === Resultados de divisa segun año === " << endl;
    for(int i = 0;i< 25;i++){
        cout << " El sueldo minimo anual transformado en la divisa de dolar  "  << pesodolar[i] << " para el año: " << ano_smi[i] << endl;
    }
    cout << "                                 === Resultado === " << endl;
    cout << "                      La funcion de regresion es y = "  << m << "x " << b  << endl;
    cout << "                                 === Integrantes === " << endl;
    cout << "                             Rodrigo Andres Estay Poblete " << endl;
   

}
