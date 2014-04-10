OBJ = main.o
DEPS = 
LIBS = -lwiringPi -lwiringPiDev
CFLAGS =
CC = gcc
EXTENSION = .c
%.o:%s(EXTENSION)$(DEPS)
	%(CC) -c -o$@$<$(CFLAGS)
pi.a:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:clean
clean:
		rm -f *.o* ~core*~
