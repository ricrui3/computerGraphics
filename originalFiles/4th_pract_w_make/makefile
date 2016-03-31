CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=trial.c noGLfunctions.c opengl.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=line

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@