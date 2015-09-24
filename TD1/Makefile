CC = gcc
CCFLAGS = -Wall -std=c99
LIBS = -lglut -lgsl -lgslcblas -lm -lGLU -lGL

TARGET= exo1-1 gsl_matrix

all : $(TARGET)
	cd .

% :  %.c
	$(CC) $(CCFLAGS) $@.c -o $@ $(LIBS)

clean:
	rm -rf $(TARGET) *.o *~
