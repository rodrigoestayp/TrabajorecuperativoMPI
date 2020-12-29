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

using namespace std;


int main(int argc, char** argv ){

    std::ifstream leerDesde;
    std::string linea = "";
    std::string word = "";
    leerDesde.open("/home/rorrolubuntu/Desktop/prueba/recuperativopruebas/csv/smi.csv");
    std::vector<int> valorsmi, ano_smi;

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
            valorsmi.push_back(stoi(str2));

         }
        

        

    }
    for(int i = 0;i< ano_smi.size();i++){
        cout << "El salario minimo para el año en chile: " << ano_smi[i] << " el valor es: " << valorsmi[i] << endl;

    }

}
