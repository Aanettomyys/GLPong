CFLAGS = -O2 -std=c99
LIBS =  -lSDL -lGL -lGLU -lm

TARGET = GLPong
	
all:
	gcc -o $(TARGET) *.c $(CFLAGS) $(LIBS)
	strip $(TARGET)
	
clean:
	rm -f $(TARGET)
