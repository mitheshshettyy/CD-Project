%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
%}
%token INT MAIN BEGINN END IF FOR LP RP COMMA SEMI ASSIGN INC D NUM RELOP ID

%%

program:
    INT MAIN LP RP BEGINN declarations statements END
    {
        printf("\n Parsing Successful!\n");

        int x, y;
        printf("Enter two numbers: ");
        scanf("%d %d", &x, &y);

        printf("GCD(%d, %d) = %d\n", x, y, gcd(x, y));
    }
;

declarations:
    INT varlist SEMI
;

varlist:
    ID COMMA varlist
    | ID
;

statements:
    if_stmt for_stmt
;

if_stmt:
    IF LP expr RELOP expr RP assign_stmt
;

for_stmt:
    FOR LP ID ASSIGN NUM SEMI expr RELOP expr SEMI INC ID RP
    BEGINN assign_stmt END
;

assign_stmt:
    ID ASSIGN expr SEMI
;

expr:
    ID
    | NUM
;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter program:\n");
    return yyparse();
}
