#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
    //lectura de primer archivo csv -> smi.csv

    std::ifstream leerDesde;
    std::string linea = "";
    std::string word = "";
    leerDesde.open("/home/rorrolubuntu/Desktop/prueba/recuperativopruebas/csv/smi.csv");
    std::vector<int>  ano_smi;
    std::vector<float> valorsmi;

    while(std::getline(leerDesde, linea)){
        if(linea[0]== '"'){


            std::stringstream datosEnProceso(linea);

            std::getline(datosEnProceso, word, ';');
            std::stringstream datos(word);
            std::string str1(word);
            str1.erase(std::remove(str1.begin(), str1.end(), '"'),
            str1.end());
            //std::cout << str1 << '\n';
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

    std::ifstream leerDesde2;
    std::string linea2 = "";
    std::string word2 = "";
    leerDesde2.open("/home/rorrolubuntu/Desktop/prueba/recuperativopruebas/csv/dollars.csv");
    std::vector<int> ano_dollars;  
    std::vector<float> valordollars; 

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
    //funcion de distrubucion de valores 
    int contador=0;
    float suma=0;
    float promedio=0;
    std::vector<float> valorpromdollars, pesodolar , sumas;
    std::vector<int> contadores;
    for(int i = 0;i<ano_smi.size() ;i++){
        // cout << ano_dollars[i] << '\n';
        for(int j=0; j< ano_dollars.size() ; j++){
            if (ano_dollars[j] == ano_smi[i])
            {
                // cout << ano_smi[j] << '\n';
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
    float sumatoriaXY = 0;
    float x2 = 0;
    float sumX = 0;
    float SumY = 0;
    float m = 0;
    float b = 0;

    for(int i = 0;i< ano_smi.size() ;i++){
        sumatoriaXY = sumatoriaXY + (pesodolar[i] * ano_smi[i]);
        x2 = x2 + (ano_smi[i] * ano_smi[i]);
        sumX = sumX + ano_smi[i];
        SumY = SumY + pesodolar[i];
    //    cout << "promedio es: "  << valorpromdollars[i] << " el año es: " << ano_smi[i] << endl;
    //    cout << "contador: "  << contadores[i] << " el año es: " << ano_smi[i] << endl;
    //    cout << "suma: "  << sumas[i] << " el año es: " << ano_smi[i] << endl;
    }
    m= ((25*sumatoriaXY) - (sumX*SumY)) / ((25*x2) - (sumX*sumX));
    b= (SumY/25) - (m * (sumX/25));

    cout << "suma x = "  << sumX << "X -  " << endl;
    cout << "x2 = "  <<x2 << "X -  " << endl;
    cout << "sumay = "  << SumY << "X -  " << endl;
    cout << "x por y "  << sumatoriaXY << "X -  "  << endl;
    cout << "la funcion de regresion es y =  "  << m << "X  " << b  << endl;




    // for(int i = 0;i< 25;i++){
    //    cout << "promedio es: "  << valorpromdollars[i] << " el año es: " << ano_smi[i] << endl;
    //    cout << "contador: "  << contadores[i] << " el año es: " << ano_smi[i] << endl;
    //    cout << "suma: "  << sumas[i] << " el año es: " << ano_smi[i] << endl;
    // }
        for(int i = 0;i< 25;i++){
        cout << "pdivisa de dolar peso chileno: "  << pesodolar[i] << " para el año: " << ano_smi[i] << endl;
    }
    for(int i = 0;i<10 ;i++){
        //cout << "El salario minimo para el año en chile: " << ano_smi[i] << " el valor es: " << valorsmi[i] << endl;
    }
    for(int i = 0;i< 10;i++){
        //cout << "El salario minimo para el año en usa: "  << ano_dollars[i] << " el valor es: " << valordollars[i] << endl;
    }

}
