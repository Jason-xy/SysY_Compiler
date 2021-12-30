genllvm: main.c tree.c lrparser.tab.c lex.yy.c
	gcc main.c tree.c lrparser.tab.c lex.yy.c genllvm.c -o genllvm
lex.yy.c: lrlex.l
	flex lrlex.l
lrparser.tab.c: lrparser.y
	bison -d lrparser.y
clean:
	rm lex.yy.c lrparser.tab.c
clean_all:
	rm error.txt output.txt genllvm lex.yy.c lrparser.tab.c lrparser.tab.h ast.txt
run:
	./genllvm test.sy