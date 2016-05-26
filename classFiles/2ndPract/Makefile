CFLAGS = -Wall -Werror -g

main: main.cpp Coordinate2D.o Coordinate3D.o ImagePPM.o Pixel.o Triangle.o Sphere.o
	g++ main.cpp Sphere.o Triangle.o Coordinate2D.o Coordinate3D.o ImagePPM.o Pixel.o $(CFLAGS) -o main.out -O2

Pixel: Pixel.cpp
	g++ Pixel.cpp -c

ImagePPM: ImagePPM.cpp
	g++ ImagePPM.cpp -c

Coordinate3D: Coordinate3D.cpp
	g++ Coordinate3D.cpp -c

Coordinate2D: Coordinate2D.cpp
	g++ Coordinate2D.cpp -c

Triangle: Triangle.cpp
	g++ Triangle.cpp -c

Sphere: Sphere.cpp
	g++ Sphere.cpp

clean:
	rm -f *.out *.o ./generatedFiles/*

clang:
	clang-format-3.4 -i -style=Google *.h *.cpp
