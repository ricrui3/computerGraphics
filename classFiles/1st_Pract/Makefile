CFLAGS = -Wall -Werror -g

main: main.cpp ImagePPM.o Pixel.o
	g++ main.cpp ImagePPM.o Pixel.o $(CFLAGS) -o main.out -O2

Pixel: Pixel.cpp
	g++ Pixel.cpp -c

ImagePPM: ImagePPM.cpp
	g++ ImagePPM.cpp -c

clean:
	rm -f $@.out
