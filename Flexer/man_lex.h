#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 0

typedef struct Word{
    int wordInfo;
    char wordStr[100];
}Word;

bool isDigital(char* str);
bool isLetter(char* str);
bool isSeparator(char* str);
bool isOperatorChar(char* str);
bool isOperator(char* str);
bool isKeyword(char* str);
int preProcessing(FILE* fp, char** strText);
int Flexer(char* str);
void printWord(Word *pword);
