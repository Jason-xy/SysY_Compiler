# part of the makefile

CFLAGS = -O0 -g

all: calc3.tab.c lex.yy.c ast.c main.c
	gcc -o calc $(CFLAGS) calc3.tab.c lex.yy.c ast.c main.c


calc3.tab.c : calc3.y
	bison -d calc3.y

lex.yy.c : calc3.l
	flex calc3.l
	


clean:
	$(RM) *.o *.exe calc3.tab.c calc3.tab.h lex.yy.c