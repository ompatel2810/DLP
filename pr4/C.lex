%{
#include <stdio.h>
#include <stdlib.h>
int char_count = 0, word_count = 0, line_count = 0;
%}

%%

[^ \t\n]+  { word_count++; char_count += yyleng; }  /* Match words */
[ \t]      { char_count += yyleng; }  /* Match spaces and tabs */
\n         { line_count++; char_count++; }  /* Match new lines */
.          { char_count++; }  /* Match any other characters */

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    
    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);
    return 0;
}

int yywrap() {
    return 1;
}