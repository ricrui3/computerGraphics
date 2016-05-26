#!/bin/bash

uno=1
nMenosUno=$(($1 - $uno))
echo $nMenosUno

#-------Obtiene los ejecutable de la aplicacion-----
chmod +x Makefile 
chmod +x ./LineDrawing/Makefile
make
cd LineDrawing/
make
cd ../
#---------------------------------------------------

#----Borra los arcivos .raw preexistentes-----------
rm generatedFiles/*

#-------Obtiene los archivos raw y las imagenes del octahedro y de la esfera-----
archivoOctahedro=$(printf "./generatedFiles/sphere%d.raw" "$nMenosUno") 
#archivoEsfera=$(printf "./generatedFiles/sphere%d.raw" "$1") 
./main.out 50 50 "$1"
time ./LineDrawing/linea.out 0 1 0 $archivoOctahedro
#time ./LineDrawing/linea.out 0 1 0 $archivoEsfera
#--------------------------------------------------------------------------------



