#!/bin/bash

uno=$(($1))
echo $uno

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
for (( i = 0; i < "$uno"; i++ )); do
	archivoEsfera=$(printf "./generatedFiles/sphere%d.raw" "$i") 
	./main.out 50 50 "$i"
	time ./LineDrawing/linea.out 0 1 0 $archivoEsfera
	imagenEsfera=$(printf "./generatedImages/sphere%d.ppm" "$i")
	cp LineImg2.ppm $imagenEsfera
done
#--------------------------------------------------------------------------------