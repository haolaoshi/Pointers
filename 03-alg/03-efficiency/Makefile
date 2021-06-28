CC=g++
CFLAGS=-g
objts=efficient  ge-sort
all:$(objts)
efficient:prg3.cpp prg.cpp 
ge-sort:prg.cpp prg3.cpp
$(objts):
	$(CC) $(CFLAGS)  $< -o $@
clean:
	$(RM) *.o  efficient  ge-sort
