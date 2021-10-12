/************************************************** 
 * @FileName: man_lex.c                           *
 * @Author: JasonHsu                              *
 * @Website: https://jason-xy.cn                  *     
 * @Date: 2021-10-12                              *   
 * @Description: SysY lexer                       *
 * @Version: V1.0                                 *
 **************************************************/
#include "man_lex.h"

/* Define the word struct to storage the info of word */
//intConst | operator | separator | identifier | keyword
enum WordType{intConst = 0, operator = 1, separator = 2, identifier = 3, keyword = 4};

/************************************************** 
 * @Description: Find digital                     *
 * @FunctionPrototype: bool isDigital(char* str)  *
 * @Input: Pointer of a character                 *
 **************************************************/
bool isDigital(char* str){
    if(*str >= '0' && *str <= '9')
        return true;
    return false;
}

/************************************************** 
 * @Description: Find letter                      *
 * @FunctionPrototype: bool isLetter(char* str)   *
 * @Input: Pointer of a character                 *
 **************************************************/
bool isLetter(char* str){
    if((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
        return true;
    return false;
}

/************************************************** 
 * @Description: Find separator                   *
 * @FunctionPrototype: bool isSeparator(char* str)*
 * @Input: Pointer of a character                 *
 **************************************************/
bool isSeparator(char* str){
    if(*str == ',' || *str == ';' || *str == '(' || *str == ')' || *str == '{' || *str == '}' || *str == '[' || *str == ']')
        return true;
    return false;
}

/************************************************** 
 * @Description: Find operator                    *
 * @FunctionPrototype: bool isOperator(char* str) *
 * @Input: Pointer of a word                      *
 **************************************************/
bool isOperatorChar(char* str){
    if(*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '%' || *str == '<' || *str == '>' || *str == '='|| \
       *str == '!' || *str == '|' || *str == '&')
       return true;
    return false;
}
bool isOperator(char* str){
    if(!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "%") || \
       !strcmp(str, "<") || !strcmp(str, ">") || !strcmp(str, "=") || !strcmp(str, "!") || \
       !strcmp(str, ">=") || !strcmp(str, "<=") || !strcmp(str, "==") || !strcmp(str, "||") || !strcmp(str, "&&"))
        return true;
    return false;
}

/************************************************** 
 * @Description: Find keyword                     *
 * @FunctionPrototype: bool isKeyword(char* str)  *
 * @Input: Pointer of a word                      *
 **************************************************/
bool isKeyword(char* str){
    if(!strcmp(str, "const") || !strcmp(str, "int") || !strcmp(str, "void") || \
       !strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || 
       !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "return"));
       return true;
    return false;
}

/******************************************************************** 
 * @Description: Delete all Tab, Enter                              *
 * @FunctionPrototype: int preProcessing(FILE* fp, char** strText)  *
 * @Input: Pointer of a file, Pointer of the textBuffer pointer     *
 ********************************************************************/
int preProcessing(FILE* fp, char** strText){
    //read text to buffer
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *strText = (char*)malloc((fileSize + 1) * sizeof(char));
    fread(*strText, fileSize, sizeof(char), fp);
    (*strText)[fileSize] = 0;

    #if DEBUG
        printf("FileSize: %d\n", fileSize);
    #endif

    //delete 9, 10, 13, 32 
    //dont delet space 
    int readIdx = 0, writeIdx = 0;
    do{
        #if DEBUG
            printf("(*strText)[%d]:%c\n", readIdx, (*strText)[readIdx]);
        #endif
        if((*strText)[readIdx] == 9 || (*strText)[readIdx] == 10 ||\
           (*strText)[readIdx] == 13 ){
               readIdx++;
               continue;
           }
        (*strText)[writeIdx++] = (*strText)[readIdx++];
    }while(readIdx <= fileSize);

    return 0;
}

/******************************************************************** 
 * @Description: Out put of flexer                                  *
 * @FunctionPrototype: void printWord(Word *pword)                  *
 * @Input: Pointer of a word struct                                 *
 ********************************************************************/

void printWord(Word *pword){
    char stype[20] = {0};
    switch(pword->wordInfo){
        case 0: 
            strcpy(stype, "intConst");
            break;
        case 1:
            strcpy(stype, "operator");
            break;
        case 2:
            strcpy(stype, "separator");
            break;
        case 3:
            strcpy(stype, "identifier");
            break;
        case 4:
            strcpy(stype, "keyword");
            break;
        default:
            strcpy(stype, "Undefined");
            break;
    }
    printf("< \"%s\", \"%s\">\n", stype, pword->wordStr);
}

/******************************************************************** 
 * @Description: Flexer                                             *
 * @FunctionPrototype: int Flexer(char* str)                        *
 * @Input: Pointer of a strTextBuffer                               *
 ********************************************************************/

int Flexer(char* str){
    char wordBuff[100] = {0};
    int buffIdx = 0;
    Word* pword = malloc(sizeof(Word)); 
    int state = 0; //0: construct word | 1: classify | 2: error handler
    int preType = 0; //0: null | 1: digital | 2: separator | 3: letter | 4: operator
    while(*str){
        #if DEBUG
            printf("state: %d\t*str: %c\twordBuff: %s\n", state, *str, wordBuff);
        #endif
        switch(state){
            case 0: 
                switch(preType){
                    case 0: 
                        //start to construct word
                        if(*str == ' '){
                            str++;
                            break;
                        }
                        if(isDigital(str)) preType = 1;
                        else if(isSeparator(str)) preType = 2;
                        else if(isLetter(str)) preType = 3;
                        else if(isOperatorChar(str)) preType = 4;
                        wordBuff[buffIdx++] = *str;
                        str++;
                        break;
                    case 1:
                        if(*str == ' ' || isSeparator(str) || isOperatorChar(str)){
                            //find intConst
                            pword->wordInfo = 0;
                            strcpy(pword->wordStr, wordBuff);
                            state = 1;
                            //reinit
                            memset(wordBuff, 0, 100 * sizeof(char));
                            buffIdx = 0;
                            preType = 0;
                            break;
                        }
                        else if(isDigital(str)) preType = 1;
                        else if(isLetter(str)) preType = 3;
                        wordBuff[buffIdx++] = *str;
                        str++;
                        break;
                    case 2:
                        //find separator
                        pword->wordInfo = 2;
                        strcpy(pword->wordStr, wordBuff);
                        state = 1;
                        //reinit
                        memset(wordBuff, 0, 100 * sizeof(char));
                        buffIdx = 0;
                        preType = 0;
                        break;
                    case 3:
                        if(*str == ' ' || isSeparator(str) || isOperatorChar(str)){
                            //find identifier or keyword
                            strcpy(pword->wordStr, wordBuff);
                            if(isKeyword(pword->wordStr))
                                pword->wordInfo = 4;
                            pword->wordInfo = 3;
                            state = 1;
                            //reinit
                            memset(wordBuff, 0, 100 * sizeof(char));
                            buffIdx = 0;
                            preType = 0;
                            break;
                        }
                        else if(isDigital(str)) preType = 1;
                        else if(isLetter(str)) preType = 3;
                        wordBuff[buffIdx++] = *str;
                        str++;
                        break;
                    case 4:
                        if(isOperatorChar(str)){
                            preType = 4;
                            wordBuff[buffIdx++] = *str;
                            str++;
                            break;
                        }else{
                            //find operator
                            strcpy(pword->wordStr, wordBuff);
                            if(!isOperator(pword->wordStr))
                                pword->wordInfo = 5;
                            else
                                pword->wordInfo = 1;
                            state = 1;
                            //reinit
                            memset(wordBuff, 0, 100 * sizeof(char));
                            buffIdx = 0;
                            preType = 0;
                            break;
                        }
                    default:
                        printf("Unknow character: %c\n", *(str++));
                        break;
                }
                break;

            case 1:
                printWord(pword);
                memset(pword, 0, sizeof(Word));
                state = 0;
                break;

            case 2:
                //catched error
                break;

            default:
                printf("Unknow error!\n");
                break;
        }
    }

    free(pword);
    return 0;
}

int main(int argc, char **argv){
    //help
    if(argc != 2){
        printf("Usage: ./man_lex <fileName>\n");
        return 1;
    }

    //file operation
    FILE *fp;
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("No such file or directory\n");
        return 1;
    }  

    //preProcessing
    char* strText;
    preProcessing(fp, &strText);
    fclose(fp);
    #if DEBUG
        printf("%s\n", strText);
    #endif

    //Lexer
    Flexer(strText);

    //finished
    free(strText);
    return 0;
}