/* just like Unix wc */
%{
int chars = 0;
int words = 0;
int lines = 0;
int nums = 0;
%}

DIGIT      [0-9]

%%
[a-zA-Z]+				{ words++; chars += strlen(yytext); }
{DIGIT}+"."*{DIGIT}* 	{ nums ++; chars += strlen(yytext); }
\n						{ chars++; lines++; }
. 						{ chars++; }

%%
main(int argc, char **argv)
{
	yylex();
	printf("lines: %8d\n", lines);
	printf("words: %8d\n", words);
	printf("nums: %8d\n", nums);
	printf("chars: %8d\n", chars);
}
