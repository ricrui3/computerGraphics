CFLAGS = -Wall -Werror -g

main: main.cpp Coordinate2D.o Coordinate3D.o ImagePPM.o Pixel.o
	g++ main.cpp Coordinate2D.o Coordinate3D.o ImagePPM.o Pixel.o $(CFLAGS) -o main.out -O2

Pixel: Pixel.cpp
	g++ Pixel.cpp -c

ImagePPM: ImagePPM.cpp
	g++ ImagePPM.cpp -c

Coordinate3D: Coordinate3D.cpp
	g++ Coordinate3D.cpp -c

Coordinate2D: Coordinate2D.cpp
	g++ Coordinate2D.cpp -c

clean:
	rm -f $@.out

clang:
	clang-format-3.4 -i -style=Google *.h *.cpp
