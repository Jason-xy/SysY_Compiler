CC = gcc
CFLAGS = -O0 -g
NAME = rdparser

$(NAME):y.tab.c lex.yy.c ast.c main.c
	$(CC) -o $(NAME) $(CFLAGS) y.tab.c lex.yy.c ast.c main.c

y.tab.c:lrparser.y
	bison -vdty -Wno-yacc lrparser.y

lex.yy.c:lrlex.l
	flex lrlex.l

.PHONY: clean
clean:
	$(RM) *.o *.exe y.tab.c y.tab.h lex.yy.c y.output $(NAME)
