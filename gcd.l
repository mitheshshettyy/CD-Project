%{
#include "y.tab.h"
%}

%%
"int"       { return INT; }
"main"      { return MAIN; }
"begin"     { return BEGINN; }
"end"       { return END; }
"if"        { return IF; }
"for"       { return FOR; }

"("         { return LP; }
")"         { return RP; }
","         { return COMMA; }
";"         { return SEMI; }
"="         { return ASSIGN; }
"++"        { return INC; }

">"|"<"|"=="|"!="|">="|"<="   { return RELOP; }

[0-9]+      { return NUM; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }

[ \t\n]     ;   

.           { return yytext[0]; }
%%
