#include <stdio.h>
#include <string.h>

#define STATES 48
#define ACTION_COLS 16   
#define GOTO_COLS 8      

char action[STATES][ACTION_COLS][10];

int goTo[STATES][GOTO_COLS];

char *terminals[] = {
    "INT","MAIN","LP","RP","BEGINN","END","IF","FOR",
    "ID","NUM","COMMA","SEMI","ASSIGN","INC","RELOP","$"
};

char *nonTerminals[] = {
    "program","declarations","varlist","statements",
    "if_stmt","for_stmt","assign_stmt","expr"
};

void initTable() {
    for(int i=0;i<STATES;i++) {
        for(int j=0;j<ACTION_COLS;j++)
            strcpy(action[i][j],"");
        for(int j=0;j<GOTO_COLS;j++)
            goTo[i][j] = -1;
    }

    // ===== Fill ACTION (only important entries) =====

    strcpy(action[0][0], "s1");       
    goTo[0][0] = 2;                  

    strcpy(action[1][1], "s3");       

    strcpy(action[2][15], "s4");      

    strcpy(action[3][2], "s5");       

    strcpy(action[4][15], "acc");     

    strcpy(action[5][3], "s6");       
    strcpy(action[6][4], "s7");       

    strcpy(action[7][0], "s8");       
    goTo[7][1] = 9;                  

    strcpy(action[8][8], "s10");      
    goTo[8][2] = 11;                 

    strcpy(action[9][6], "s12");      
    goTo[9][3] = 13;
    goTo[9][4] = 14;

    strcpy(action[10][10], "s15");    
    strcpy(action[10][15], "r4");

    strcpy(action[11][11], "s16");    

    strcpy(action[12][2], "s17");     

    strcpy(action[13][5], "s18");     

    strcpy(action[14][7], "s19");     
    goTo[14][5] = 20;

    strcpy(action[15][8], "s10");
    goTo[15][2] = 21;

    strcpy(action[16][15], "r2");

    strcpy(action[17][8], "s22");
    strcpy(action[17][9], "s23");
    goTo[17][7] = 24;

    strcpy(action[18][15], "r1");

    strcpy(action[19][2], "s25");

    strcpy(action[20][15], "r5");
    strcpy(action[21][15], "r3");
    strcpy(action[22][15], "r9");
    strcpy(action[23][15], "r10");

    strcpy(action[24][14], "s26");    

    strcpy(action[25][8], "s27");

    strcpy(action[26][8], "s22");
    strcpy(action[26][9], "s23");
    goTo[26][7] = 28;

    strcpy(action[27][12], "s29");   
    strcpy(action[28][3], "s30");

    strcpy(action[29][9], "s31");
    strcpy(action[30][8], "s32");
    goTo[30][6] = 33;

    strcpy(action[31][11], "s34");

    strcpy(action[32][12], "s35");

    strcpy(action[33][15], "r6");

    strcpy(action[34][8], "s22");
    strcpy(action[34][9], "s23");
    goTo[34][7] = 36;

    strcpy(action[35][8], "s22");
    strcpy(action[35][9], "s23");
    goTo[35][7] = 37;

    strcpy(action[36][14], "s38");

    strcpy(action[37][11], "s39");

    strcpy(action[38][8], "s22");
    strcpy(action[38][9], "s23");
    goTo[38][7] = 40;

    strcpy(action[39][15], "r8");

    strcpy(action[40][11], "s41");

    strcpy(action[41][13], "s42");    
    strcpy(action[42][8], "s43");

    strcpy(action[43][3], "s44");
    strcpy(action[44][4], "s45");

    strcpy(action[45][8], "s32");
    goTo[45][6] = 46;

    strcpy(action[46][5], "s47");

    strcpy(action[47][15], "r7");
}

void printTable() {
    printf("\nState\t|\tACTION\t\t\t\t\t\t|\tGOTO\n");

    printf("      \t");
    for(int i=0;i<ACTION_COLS;i++)
        printf("%s\t", terminals[i]);

    printf("|\t");

    for(int i=0;i<GOTO_COLS;i++)
        printf("%s\t", nonTerminals[i]);

    printf("\n-------------------------------------------------------------------------------------------------------------\n");

    for(int i=0;i<STATES;i++) {
        printf("%d\t|\t", i);

        // ACTION
        for(int j=0;j<ACTION_COLS;j++) {
            if(strlen(action[i][j]) == 0)
                printf("-\t");
            else
                printf("%s\t", action[i][j]);
        }

        printf("|\t");

        // GOTO
        for(int j=0;j<GOTO_COLS;j++) {
            if(goTo[i][j] == -1)
                printf("-\t");
            else
                printf("%d\t", goTo[i][j]);
        }

        printf("\n");
    }
}

int main() {
    initTable();
    printTable();
    return 0;
}
