
# Taller Recuperativo Computacion Paralela y Distribuida

## Información

Taller recuperativo, sobre el uso de herramientas de paralelismo como "(Open)MPI" y otras herramientas de desarrollo de programación general, para la asignatura de computación paralela y distribuida - UTEM.


## Requerimientos

Para el caso del uso de "(Open)MPI" es necesario tener instalada sus librerías/dependencias

* OpenMPI

Para el caso de su instalación en Ubuntu, los comandos a efectuar son:

## 

```
sudo apt update
sudo apt install libopenmpi-dev
```

También es necesario, la herramienta Makefile, que nos permitirá poder compilar nuestro lenguaje C++, desde la terminal.

* Makefile

Para el caso de su instalación en Ubuntu, los comandos a efectuar son:

## 

```
sudo apt-get update
sudo apt-get install make
```
## Uso

Para poder probar este proyecto, es necesario ir a la carpeta del proyecto y situarse en la raiz del directorio, en la cual se encuentren los siguientes archivos

```
ls
csv  dist  main2.cpp  main.cpp  makefile  maquinas.txt
```
Una vez situado, es necesario disponer de una terminal para poder ejecutar los siguientes comandos:

```
make
dist/programa (#pathruta)smi.csv (#pathruta)dollars.csv

```

Para mi caso, en especifico ocupo la siguiente sintaxis:

```
make
dist/programa /home/rorrolubuntu/Desktop/prueba/recuperativopruebas/csv/smi.csv /home/rorrolubuntu/Desktop/prueba/recuperativopruebas/csv/dollars.csv
```

## Problema y Resultados

El taller presenta la siguiente problematica, Usando los archivos adjuntos ( smi.csv y dollars.csv ), se solicita desarrollar un programa en C/C++ (usando MPI ) que leyendo argumentos desde la línea de argumentos, lleve el valor del salario mínimo (valor anual de Chile) a la divisa del dólar (valor diario) para luego encontrar la función matemática que explica el crecimiento del indicador.
Y se establece un ejemplo:

```
usuario@maquina:~$mpirun -hostfile maquinas.txt programa smi.csv dollars.csv
=== Resultado ===
y = 4340x - 8598010
=== Integrantes ===
Juanito
```

Resultado propio, si bien el programa solo pide que se muestre la función de regresión, me parece importante poder ilustrar, el cambio del salario minimo de chile a la divisa del dolar por sus periodos anuales.
Por lo tanto al ejercutar el archivo se espera la siguiente respuesta:

```
                         === Resultados de divisa segun año === 
 El sueldo minimo anual transformado en la divisa de dolar  148.444 para el año: 1995
 El sueldo minimo anual transformado en la divisa de dolar  158.896 para el año: 1996
 El sueldo minimo anual transformado en la divisa de dolar  170.305 para el año: 1997
 El sueldo minimo anual transformado en la divisa de dolar  174.878 para el año: 1998
 El sueldo minimo anual transformado en la divisa de dolar  169.647 para el año: 1999
 El sueldo minimo anual transformado en la divisa de dolar  178.228 para el año: 2000
 El sueldo minimo anual transformado en la divisa de dolar  162.679 para el año: 2001
 El sueldo minimo anual transformado en la divisa de dolar  157.891 para el año: 2002
 El sueldo minimo anual transformado en la divisa de dolar  164.018 para el año: 2003
 El sueldo minimo anual transformado en la divisa de dolar  193.297 para el año: 2004
 El sueldo minimo anual transformado en la divisa de dolar  221.036 para el año: 2005
 El sueldo minimo anual transformado en la divisa de dolar  247.519 para el año: 2006
 El sueldo minimo anual transformado en la divisa de dolar  266.888 para el año: 2007
 El sueldo minimo anual transformado en la divisa de dolar  290.347 para el año: 2008
 El sueldo minimo anual transformado en la divisa de dolar  289.458 para el año: 2009
 El sueldo minimo anual transformado en la divisa de dolar  330.148 para el año: 2010
 El sueldo minimo anual transformado en la divisa de dolar  366.184 para el año: 2011
 El sueldo minimo anual transformado en la divisa de dolar  385.211 para el año: 2012
 El sueldo minimo anual transformado en la divisa de dolar  404.212 para el año: 2013
 El sueldo minimo anual transformado en la divisa de dolar  379.382 para el año: 2014
 El sueldo minimo anual transformado en la divisa de dolar  354.223 para el año: 2015
 El sueldo minimo anual transformado en la divisa de dolar  374.908 para el año: 2016
 El sueldo minimo anual transformado en la divisa de dolar  411.194 para el año: 2017
 El sueldo minimo anual transformado en la divisa de dolar  437.301 para el año: 2018
 El sueldo minimo anual transformado en la divisa de dolar  425.306 para el año: 2019
                                 === Resultado === 
                      La funcion de regresion es y = 13.5337x -26887.7
                                 === Integrantes === 
                                Rodrigo Estay Poblete 
```
