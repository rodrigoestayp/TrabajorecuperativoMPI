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

    // inicializar variables globales
    int rank;
    int size;

    // Inicializacion de mpi
    MPI_Init(&argc, &argv);

    // Obtencion del rank y el size del cluster
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    //lectura de primer archivo csv -> smi.csv

    std::ifstream leerDesde;
    std::string linea = "";
    std::string word = "";
    leerDesde.open(argv[1]);
    std::vector<int>  ano_smi;
    std::vector<float> valorsmi;

    int valores[2];
    if(rank==0){
        int cantidadLin =0;
        while(std::getline(leerDesde, linea)){        
            if(linea[0]== '"'){
                // envio de linea
                if(numProce >= size){
                    numProce = 1;
                }
                MPI_Send(&linea[0],linea.size()+1,MPI_CHAR,numProce,0,MPI_COMM_WORLD);
                numProce += 1;
                cantidadLin += 1;
            }
            }
            while(cantidadLin!=0){
                cantidadLin -= 1;
                MPI_Recv(&valores,2,MPI_INT,Nproc,0,MPI_COMM_WORLD,&status);
                ano_smi.push_back();
                valorsmi.push_back();
            }

            else{
                MPI_Probe(0,0,MPI_COMM_WORLD,&status);
                int count;
                MPI_Get_count(&status,MPI_CHAR,&count);
                char buf [count];
                MPI_Recv(&buf,count,MPI_CHAR,0,0,MPI_COMM_WORLD,&status);
                std::string lineaN = buf; 
                std::stringstream datosEnProceso(linea);
                std::getline(datosEnProceso, word, ';');
                std::stringstream datos(word);
                std::string str1(word);
                str1.erase(std::remove(str1.begin(), str1.end(), '"'),
                str1.end());

                std::getline(datosEnProceso, word, ';');
                std::stringstream datoss(word);
                std::string str2(word);
                str2.erase(std::remove(str2.begin(), str2.end(), '"'),
                str2.end());

                valores = {stoi(str1),stoi(str2)};
                MPI_Send(&valores,2,MPI_INT,0,0,MPI_COMM_WORLD);
            }

    }
    //funcion de distrubucion de valores 
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
    cout << "           === Resultados de divisa segun año === " << endl;
    for(int i = 0;i< 25;i++){
        cout << " la divisa de dolar peso chileno: "  << pesodolar[i] << " para el año: " << ano_smi[i] << endl;
    }
    cout << "                   === Resultado === " << endl;
    cout << "      La funcion de regresion es y = "  << m << "x " << b  << endl;
    cout << "                   === Integrantes === " << endl;
    cout << "                 Rodrigo Estay Poblete " << endl;
   

}
