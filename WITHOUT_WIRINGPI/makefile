OBJ = library.o
DEPS = library.h
LIBS =
CFLAGS =
CC = gcc -oterm -lpthread 
EXTENSION = .c
%.o:%s(EXTENSION)$(DEPS)
	%(CC) -c -o$@$<$(CFLAGS)
pi.a:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:clean
clean:
		rm -f *.o* ~core*~
